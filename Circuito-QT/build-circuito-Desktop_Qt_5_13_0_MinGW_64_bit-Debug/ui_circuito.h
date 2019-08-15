/********************************************************************************
** Form generated from reading UI file 'circuito.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CIRCUITO_H
#define UI_CIRCUITO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_circuito
{
public:
    QWidget *centralWidget;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *t1;
    QLineEdit *t2;
    QLabel *q1;
    QLabel *q2;
    QPushButton *inserir1;
    QPushButton *inserir2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *porta_serial;
    QLabel *label;
    QComboBox *vel_serial;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *conectar;
    QLabel *status_conexao;
    QPushButton *desconectar;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *ligar2;
    QPushButton *desligar2;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *ligar1;
    QPushButton *desligar1;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *circuito)
    {
        if (circuito->objectName().isEmpty())
            circuito->setObjectName(QString::fromUtf8("circuito"));
        circuito->resize(584, 366);
        centralWidget = new QWidget(circuito);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 170, 71, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(300, 170, 71, 16));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(120, 123, 71, 20));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(400, 130, 71, 16));
        t1 = new QLineEdit(centralWidget);
        t1->setObjectName(QString::fromUtf8("t1"));
        t1->setGeometry(QRect(90, 170, 113, 20));
        t2 = new QLineEdit(centralWidget);
        t2->setObjectName(QString::fromUtf8("t2"));
        t2->setGeometry(QRect(370, 170, 113, 20));
        q1 = new QLabel(centralWidget);
        q1->setObjectName(QString::fromUtf8("q1"));
        q1->setGeometry(QRect(120, 220, 47, 13));
        q2 = new QLabel(centralWidget);
        q2->setObjectName(QString::fromUtf8("q2"));
        q2->setGeometry(QRect(420, 220, 47, 13));
        inserir1 = new QPushButton(centralWidget);
        inserir1->setObjectName(QString::fromUtf8("inserir1"));
        inserir1->setGeometry(QRect(210, 170, 75, 23));
        inserir2 = new QPushButton(centralWidget);
        inserir2->setObjectName(QString::fromUtf8("inserir2"));
        inserir2->setGeometry(QRect(490, 170, 75, 23));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 20, 351, 101));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        porta_serial = new QComboBox(widget);
        porta_serial->setObjectName(QString::fromUtf8("porta_serial"));

        horizontalLayout->addWidget(porta_serial);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        vel_serial = new QComboBox(widget);
        vel_serial->setObjectName(QString::fromUtf8("vel_serial"));

        horizontalLayout->addWidget(vel_serial);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        conectar = new QPushButton(widget);
        conectar->setObjectName(QString::fromUtf8("conectar"));

        horizontalLayout_2->addWidget(conectar);

        status_conexao = new QLabel(widget);
        status_conexao->setObjectName(QString::fromUtf8("status_conexao"));

        horizontalLayout_2->addWidget(status_conexao);

        desconectar = new QPushButton(widget);
        desconectar->setObjectName(QString::fromUtf8("desconectar"));

        horizontalLayout_2->addWidget(desconectar);


        verticalLayout->addLayout(horizontalLayout_2);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(370, 270, 158, 31));
        horizontalLayout_3 = new QHBoxLayout(widget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        ligar2 = new QPushButton(widget1);
        ligar2->setObjectName(QString::fromUtf8("ligar2"));

        horizontalLayout_3->addWidget(ligar2);

        desligar2 = new QPushButton(widget1);
        desligar2->setObjectName(QString::fromUtf8("desligar2"));

        horizontalLayout_3->addWidget(desligar2);

        widget2 = new QWidget(centralWidget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(70, 270, 158, 25));
        horizontalLayout_4 = new QHBoxLayout(widget2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        ligar1 = new QPushButton(widget2);
        ligar1->setObjectName(QString::fromUtf8("ligar1"));

        horizontalLayout_4->addWidget(ligar1);

        desligar1 = new QPushButton(widget2);
        desligar1->setObjectName(QString::fromUtf8("desligar1"));

        horizontalLayout_4->addWidget(desligar1);

        circuito->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(circuito);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 584, 21));
        circuito->setMenuBar(menuBar);
        mainToolBar = new QToolBar(circuito);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        circuito->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(circuito);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        circuito->setStatusBar(statusBar);

        retranslateUi(circuito);

        QMetaObject::connectSlotsByName(circuito);
    } // setupUi

    void retranslateUi(QMainWindow *circuito)
    {
        circuito->setWindowTitle(QCoreApplication::translate("circuito", "circuito", nullptr));
        label_3->setText(QCoreApplication::translate("circuito", "Tempo aceso: ", nullptr));
        label_4->setText(QCoreApplication::translate("circuito", "Tempo aceso:", nullptr));
        label_5->setText(QCoreApplication::translate("circuito", "Quadrante 1", nullptr));
        label_6->setText(QCoreApplication::translate("circuito", "Quadrante 2", nullptr));
        q1->setText(QCoreApplication::translate("circuito", "TextLabel", nullptr));
        q2->setText(QCoreApplication::translate("circuito", "TextLabel", nullptr));
        inserir1->setText(QCoreApplication::translate("circuito", "Inserir", nullptr));
        inserir2->setText(QCoreApplication::translate("circuito", "Inserir", nullptr));
        label_2->setText(QCoreApplication::translate("circuito", "Porta", nullptr));
        label->setText(QCoreApplication::translate("circuito", "Velocidade", nullptr));
        conectar->setText(QCoreApplication::translate("circuito", "Conectar", nullptr));
        status_conexao->setText(QString());
        desconectar->setText(QCoreApplication::translate("circuito", "Desconectar", nullptr));
        ligar2->setText(QCoreApplication::translate("circuito", "Ligar", nullptr));
        desligar2->setText(QCoreApplication::translate("circuito", "Desligar", nullptr));
        ligar1->setText(QCoreApplication::translate("circuito", "Ligar", nullptr));
        desligar1->setText(QCoreApplication::translate("circuito", "Desligar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class circuito: public Ui_circuito {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CIRCUITO_H
