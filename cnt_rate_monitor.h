#ifndef CNT_RATE_MONITOR_H
#define CNT_RATE_MONITOR_H

#include "ipbusinterface.h"
#include "cmath"


class counter_rate_monitor : public QObject{
    Q_OBJECT
public:

   counter_rate_monitor(){
       CFD_CNT.reserve(12);
       TRG_CNT.reserve(12);

       upd_rate[0] = 1.0;
       upd_rate[1] = 0.1;
       upd_rate[2] = 0.2;
       upd_rate[3] = 0.5;
       upd_rate[4] = 1.0;
       upd_rate[5] = 2.0;
       upd_rate[6] = 5.0;
       upd_rate[7] = 10.0;
       connect(&FIFO_timer, &QTimer::timeout, this ,&counter_rate_monitor::FIFO_isOK);
       connect(this, &counter_rate_monitor::FIFO_OK, this, &counter_rate_monitor::cnt_rate);
       connect(this, &counter_rate_monitor::check_overfill, this, &counter_rate_monitor::clear_FIFO);
       connect(this,&counter_rate_monitor::No_FIFO_data, this, [=](){
//           if(abscence_FIFO > 1){
//              for(quint8 i = 0; i < 12; ++i){
//                  CFD_cnt_rate[i] = 0;
//                  TRG_cnt_rate[i] = 0;
//              }
//           }
           emit cnt_rate_ready();

       });

   }
   void start(IPbusTarget* target, quint32 PMshift){
       quint32 data;
       shift = PMshift;
       testboard = target;
       connect(testboard, &IPbusTarget::IPbusError, this, [=](QString msg){
           qDebug()<<msg;
       });
       testboard->reinit();
//      get_counters();
       for(quint8 i = 0; i < 12; ++i){
           testboard->readRegister(&data, shift + 0xc0 + 2 * i);
           CFD_CNT.append(data);
           testboard->readRegister(&data, shift + 0xc0 + 2 * i + 1);
           TRG_CNT.append(data);
       }
       clear_rates();
       emit cnt_rate_ready();
       upd_rate_address = (testboard->IPaddress == "172.20.75.175") ? 0x200 : 0x50;
       if(testboard->readRegister(&upd_mode, upd_rate_address)){
           FIFO_timer.start(quint8(upd_rate[upd_mode] * 500));
//           qDebug()<<"Iternal timer started";
       }
       else
           emit cnt_rate_message("Unknown IP");
       }

   void stop(){
       FIFO_timer.stop();
       clear_rates();
       emit cnt_rate_ready();
   }

   quint32 CFD_cnt_rate[12], TRG_cnt_rate[12];
   QVector <quint32> CFD_CNT, TRG_CNT;

signals:
   void cnt_rate_ready();
   void cnt_rate_message(QString);
   void FIFO_OK();
   void check_overfill();
   void No_FIFO_data();

private:
   IPbusTarget* testboard;
   QTimer FIFO_timer;
   double upd_rate[8];
   quint16 upd_rate_address;
   quint32 shift, upd_mode, trash[255];

private slots:

   void FIFO_isOK(){
       quint32 FIFO_load;
       quint32 mode;
       testboard->readRegister(&mode, upd_rate_address);
       if(upd_mode != mode){
           upd_mode = mode;
           if(upd_mode == 0){
               clear_rates();
               emit cnt_rate_ready();
           }
           FIFO_timer.stop();
           FIFO_timer.start(quint8(upd_rate[upd_mode] * 500));
           return;
       }
//       qDebug()<<"Chcked mode";
       if(testboard->readRegister(&FIFO_load, shift + 0x101))
           if(FIFO_load >= 24 && FIFO_load <= 481)
               emit FIFO_OK();
           else{
               emit check_overfill();
           }
       else{
           emit cnt_rate_message("FIFO is OK: can't read register");
       }
   }

   void clear_FIFO(){
//       qDebug()<<"Checkig FIFO";
       quint32 FIFO_load;
       if(testboard->readRegister(&FIFO_load, shift + 0x101)){
//           qDebug()<<"FIFO load ready";
          if(FIFO_load < 24){
              emit No_FIFO_data();
          }
          else{
//              qDebug() << "going to read FIFO";
              testboard->Non_incrementing_readRegister(trash, shift + 0x100, FIFO_load > 255 ? 255: quint8(FIFO_load));
//              qDebug() << "Clear FIFO";
              emit check_overfill();
          }

       }else
           emit cnt_rate_message("Clear FIFO: can't read register");
   }

   void cnt_rate(){
           get_counters();
           if(CFD_CNT.size() == 24 && TRG_CNT.size() == 24){
               for(quint8 i = 0; i < 12; ++i){
                   CFD_cnt_rate[i] = quint32(lround((CFD_CNT.at(i + 12) - CFD_CNT.at(i))/ upd_rate[int(upd_mode)]));
                   TRG_cnt_rate[i] = quint32(lround((TRG_CNT.at(i + 12) - TRG_CNT.at(i))/ upd_rate[int(upd_mode)]));
               }
               CFD_CNT.remove(0, 12);
               TRG_CNT.remove(0, 12);
               emit cnt_rate_ready();
           }else
               return;
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
               CFD_CNT.append(data[2 * i]);
               TRG_CNT.append(data[2 * i + 1]);
       }
       }else
           emit cnt_rate_message("get_counters: Socket error");

   }
};


#endif // CNT_RATE_MONITOR_H
