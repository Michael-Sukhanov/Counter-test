#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    testboard.IPaddress = "172.20.75.180";
    testboard.reinit();
    ui->setupUi(this);
    setWindowTitle("Counter test");
    connect(ui->pushButton_start, &QPushButton::clicked, this, [=](){
        quint32 mode;
        testboard.readRegister(&mode, 0x50);
        mnt.start(&testboard, 0x200);
        ui->pushButton_stop->setEnabled(true);
        ui->pushButton_start->setEnabled(false);
    });
    connect(ui->pushButton_stop, &QPushButton::clicked, this, [=](){
        mnt.stop();
        ui->pushButton_stop->setEnabled(false);
        ui->pushButton_start->setEnabled(true);
    });
    connect(&mnt, &counter_rate_monitor::cnt_rate_ready, this, [=](){
        ui->lineEdit_cfd_rate->setText(QString::number(*mnt.CFD_cnt_rate));
        ui->lineEdit_trg_rate->setText(QString::number(*mnt.TRG_cnt_rate));
        ui->lineEdit_cfd->setText(QString::number(mnt.CFD_CNT.at(0)));
        ui->lineEdit_trg->setText(QString::number(mnt.TRG_CNT.at(0)));

    });
    connect(&mnt, &counter_rate_monitor::cnt_rate_message, this, [=](QString msg){
        ui->statusbar->showMessage(msg);
    });
    ui->pushButton_stop->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

