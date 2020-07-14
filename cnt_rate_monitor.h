#ifndef CNT_RATE_MONITOR_H
#define CNT_RATE_MONITOR_H

#include "ipbusinterface.h"
#include "cmath"


class counter_rate_monitor : public QObject{
    Q_OBJECT
public:

   counter_rate_monitor(){
       connect(&FIFO_timer, &QTimer::timeout, this ,&counter_rate_monitor::FIFO_isOK);                      //По истечении времени таймера, происходит проверка, можно ли читать из FIFO регистра
       connect(this, &counter_rate_monitor::FIFO_OK, this, &counter_rate_monitor::cnt_rate);                //Если читать можно, то считываем и получаем в результате посчитанную скорость счета
       connect(this, &counter_rate_monitor::check_overfill, this, &counter_rate_monitor::clear_FIFO);       //Если FIFO регистр читать нельзя, то происходит проверка его переполнения
       connect(this, &counter_rate_monitor::No_FIFO_data, this, [=](){emit cnt_rate_ready();});             //Если в FIFO регистре во время проверки нет данных, то скорость счета не меняется
   }

   void start(IPbusTarget* target, quint32 PMshift){                                                        //Функция, дающая команду начала измерения скорости счета
       quint32 data;                                                                                        //Временная переменная для заполнения векторов с счетчиками
       shift = PMshift;                                                                                     //Инициализация смещения адреса PM в зависимости от того, какой PM включен
       testboard = target;                                                                                  //Инициализация адресата (чью скорость счета будем считать)
       testboard->reinit();                                                                                 //Необходимо для начала работы с объектом IPbustarget
       for(quint8 i = 0; i < 12; ++i){                                                                      //Чтение предварительных значений счетчиков CFD и TRG получаемые из регистров shift + 0x2c0 ... shift + 0x2d8
           testboard->readRegister(&data, shift + 0xc0 + 2 * i);
           CFD_CNT.append(data);
           testboard->readRegister(&data, shift + 0xc0 + 2 * i + 1);
           TRG_CNT.append(data);
       }
       connect(testboard, &IPbusTarget::networkError, this, [=](QString msg){emit cnt_rate_message(msg);}); //При ошибке подключения объекта IPbustearget испускается сигнал с сообщением об ошибке (на всякий случай)
       clear_rates(); clear_FIFO();                                                                         //Скорость счета сначала ноль. Очищаем FIFO, чтобы не прочитать ничего лишнего (старые значения)
       emit cnt_rate_ready();                                                                               //Испускаем сигнал о том, что скорость счета уже можно посмотреть
       upd_rate_address = (testboard->IPaddress == "172.20.75.175") ? 0x200 : 0x50;                         //Инициализация адреса режима загрузки FIFO. По IP адресу определяется плата, а ее регистр upd rate известен
       if(testboard->readRegister(&upd_mode, upd_rate_address)){                                            //Инициализация upd_mode значением, которое было считано с upd rate
           FIFO_timer.start(int(upd_rate[upd_mode] * 500));                                                 //Запуск таймера со временем в два раза меньшим, чем период загрузки FIFO
       }
       else
           emit cnt_rate_message("Unknown IP");                                                             //Испускается если не удалось считать uod_mode
       }

   void stop(){                                                                                             //Функция остановки измерения скорости счета
       testboard->disconnect(SIGNAL(networkError(QString)));                                                //Развязка IPbustarget объекта с сигналом networkError для избежания повторной связи при следующих измерениях
       FIFO_timer.stop();                                                                                   //Остановка таймера
       clear_rates();                                                                                       //Скорость счета ноль
       CFD_CNT.clear() ; TRG_CNT.clear();                                                                   //Значения счетчиков очищаются
       emit cnt_rate_ready();                                                                               //Можно увидеть значения скорости счета
   }

   quint32 CFD_cnt_rate[12], TRG_cnt_rate[12];                                                              //Значения скорости счетчета для всех каналов (можно обратиться)
   QVector <quint32> CFD_CNT, TRG_CNT;                                                                      //Значения счетчиков для определения скорости счета

signals:
   void cnt_rate_ready();                                                                                   //Сигнал: Значения скорости счета готовы
   void cnt_rate_message(QString);                                                                          //Сигнал: Появилось сообщение
   void FIFO_OK();                                                                                          //Сигнал: Из FIFO можно читать
   void check_overfill();                                                                                   //Сигнал: Проверить, переполнено ли FIFO
   void No_FIFO_data();                                                                                     //Сигнал: FIFO пустое

private:
   IPbusTarget* testboard;                                                                                  //Указатель на объект, с которым идет общение
   QTimer FIFO_timer;                                                                                       //Таймер
   double upd_rate[8] = {1.0, 0.1, 0.2, 0.5, 1.0, 2.0, 5.0, 10.0};                                          //Массив где режим это индекс, а значение это период обновления FIFO в этом режиме
   quint16 upd_rate_address;                                                                                //Адресс режима
   quint32 shift, upd_mode;                                                                                 //Смещение регистра и режим обновления FIFO

private slots:

   void FIFO_isOK(){                                                                                        //Функция, проверяющая, можно ли читать из FIFO
//     qDebug() << CFD_cnt_rate[0];
       quint32 FIFO_load;                                                                                   //Получаем количество значений в FIFO
       quint32 mode;                                                                                        //Временная переменна для сравнения. Режим заполнения FIFO
       testboard->readRegister(&mode, upd_rate_address);                                                    //В нее же читаем текущий режим
       if(upd_mode != mode){                                                                                //Проверяем, соответствует ли этот режим нашим текущим измерениям и если нет
           upd_mode = mode;                                                                                 //Меняем режим измерений
           if(upd_mode == 0){                                                                               //Проверяем, не ноль ли он и если ноль, то скорости счета нет
               clear_rates();                                                                               //Обнуляем скорость счета
               emit cnt_rate_ready();                                                                       //Говорим, что значения готовы
           }
           emit clear_FIFO();                                                                               //Очищаем FIFO для следующих измерений
           FIFO_timer.start(int(upd_rate[upd_mode] * 500));                                                 //Рестарт таймера
           return;                                                                                          //Ждем следующего таймаута
       }
       qDebug()<<"Chcked mode";
       if(testboard->readRegister(&FIFO_load, shift + 0x101))                                               //Если с режимом заполнения FIFO все в порядке то проверяем, сколько значений в FIFO
           if(FIFO_load >= 24 && FIFO_load <= 481)                                                          //Если их достаточно для измерений, и FIFO не переполнено, то
               emit FIFO_OK();                                                                              //Испускаем сигнал, что с FIFO все в порядке
           else{
               emit check_overfill();                                                                       //Иначе проверяем, что там с FIFO
           }
       else{
           emit cnt_rate_message("FIFO is OK: can't read register");                                        //Если прочитать количество значений в FIFO не удалось, то выдаем сообщение об этом
       }
   }

   void clear_FIFO(){                                                                                       //Функция, которая очищает FIFO
//     qDebug()<<"Checkig FIFO";
       quint32 FIFO_load;                                                                                   //Временная переменная для определения количества значений в FIFO
       if(testboard->readRegister(&FIFO_load, shift + 0x101)){                                              //Читаем этот регистр
//        qDebug()<<"FIFO load ready";
          if(FIFO_load < 24){                                                                               //Если в FIFO слишком мало значений
              emit No_FIFO_data();                                                                          //Испускается соответствующий сигнал
          }
          else{
//            qDebug() << "going to read FIFO";
              testboard->Non_incrementing_readRegister(nullptr, shift + 0x100, FIFO_load > 255 ? 255: quint8(FIFO_load)); //Иначе Будем считывать с FIFO пока там не будет пусто
//            qDebug() << "Clear FIFO";
              emit check_overfill();
          }

       }else
           emit cnt_rate_message("Clear FIFO: can't read register");                                        //Не смог прочитать регистр
   }

   void cnt_rate(){                                                                                         //Расчет скорости счета
//       qDebug()<<"Начинаю считать скорость счета";
           get_counters();                                                                                  //Заполнение векторов значениями счетчиков
           if(CFD_CNT.size() == 24 && TRG_CNT.size() == 24){                                                //Проверка заполненности векторов, для определения скорости счета
               for(quint8 i = 0; i < 12; ++i){                                                              //Расчет скорости счета с поправкой на фактор
                   CFD_cnt_rate[i] = quint32(lround((CFD_CNT.at(i + 12) - CFD_CNT.at(i))/ upd_rate[int(upd_mode)]));
                   TRG_cnt_rate[i] = quint32(lround((TRG_CNT.at(i + 12) - TRG_CNT.at(i))/ upd_rate[int(upd_mode)]));
//                 qDebug()<<CFD_cnt_rate[i] << TRG_cnt_rate[i];
               }
               CFD_CNT.remove(0, 12);                                                                       //Первые 12 значений счетчиков удаляются для послед. определения
               TRG_CNT.remove(0, 12);                                                                       //Скорости счета
               emit cnt_rate_ready();                                                                       //Все готово
           }else{
//             qDebug()<<"Недостаточно данных";
               return;
           }
   }

   void clear_rates(){
       for(quint8 i = 0; i < 12; ++i){
           CFD_cnt_rate[i] = 0;
           TRG_cnt_rate[i] = 0;
       }
   }

   void get_counters(){
       quint32 data[24];
       if(testboard->Non_incrementing_readRegister(data, shift + 0x100, 24)){
           for(quint8 i = 0; i < 12; ++i){
               CFD_CNT.append(data[2 * i] > CFD_CNT.at(i) ? data[2 * i] : CFD_CNT.at(i));
               TRG_CNT.append(data[2 * i + 1] > TRG_CNT.at(i) ? data[2 * i + 1] : TRG_CNT.at(i));
           }
       }else
           emit cnt_rate_message("get_counters: Socket error");

   }
};


#endif // CNT_RATE_MONITOR_H
