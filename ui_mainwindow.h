/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFormLayout *formLayout;
    QLineEdit *lineEdit_trg;
    QLineEdit *lineEdit_cfd_rate;
    QLineEdit *lineEdit_trg_rate;
    QLineEdit *lineEdit_cfd;
    QLabel *label;
    QPushButton *pushButton_start;
    QPushButton *pushButton_stop;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(216, 270);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        lineEdit_trg = new QLineEdit(centralwidget);
        lineEdit_trg->setObjectName(QString::fromUtf8("lineEdit_trg"));
        sizePolicy.setHeightForWidth(lineEdit_trg->sizePolicy().hasHeightForWidth());
        lineEdit_trg->setSizePolicy(sizePolicy);
        lineEdit_trg->setMinimumSize(QSize(120, 0));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_trg);

        lineEdit_cfd_rate = new QLineEdit(centralwidget);
        lineEdit_cfd_rate->setObjectName(QString::fromUtf8("lineEdit_cfd_rate"));
        sizePolicy.setHeightForWidth(lineEdit_cfd_rate->sizePolicy().hasHeightForWidth());
        lineEdit_cfd_rate->setSizePolicy(sizePolicy);
        lineEdit_cfd_rate->setMinimumSize(QSize(120, 0));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_cfd_rate);

        lineEdit_trg_rate = new QLineEdit(centralwidget);
        lineEdit_trg_rate->setObjectName(QString::fromUtf8("lineEdit_trg_rate"));
        sizePolicy.setHeightForWidth(lineEdit_trg_rate->sizePolicy().hasHeightForWidth());
        lineEdit_trg_rate->setSizePolicy(sizePolicy);
        lineEdit_trg_rate->setMinimumSize(QSize(120, 0));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_trg_rate);

        lineEdit_cfd = new QLineEdit(centralwidget);
        lineEdit_cfd->setObjectName(QString::fromUtf8("lineEdit_cfd"));
        sizePolicy.setHeightForWidth(lineEdit_cfd->sizePolicy().hasHeightForWidth());
        lineEdit_cfd->setSizePolicy(sizePolicy);
        lineEdit_cfd->setMinimumSize(QSize(120, 20));
        lineEdit_cfd->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_cfd);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        pushButton_start = new QPushButton(centralwidget);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        sizePolicy.setHeightForWidth(pushButton_start->sizePolicy().hasHeightForWidth());
        pushButton_start->setSizePolicy(sizePolicy);
        pushButton_start->setMinimumSize(QSize(120, 20));

        formLayout->setWidget(5, QFormLayout::FieldRole, pushButton_start);

        pushButton_stop = new QPushButton(centralwidget);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        sizePolicy.setHeightForWidth(pushButton_stop->sizePolicy().hasHeightForWidth());
        pushButton_stop->setSizePolicy(sizePolicy);
        pushButton_stop->setMinimumSize(QSize(120, 20));

        formLayout->setWidget(7, QFormLayout::FieldRole, pushButton_stop);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 216, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "CFD", nullptr));
        pushButton_start->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "TRG", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "CFD RATE", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "TRG RATE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
