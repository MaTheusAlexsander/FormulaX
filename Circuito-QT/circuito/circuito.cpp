#include "circuito.h"
#include "ui_circuito.h"

circuito::circuito(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::circuito)
{
    ui->setupUi(this);

    for(auto& item : QSerialPortInfo::availablePorts())
        ui->porta_serial->addItem(item.portName());

    for(auto& item : QSerialPortInfo::standardBaudRates())
        ui->vel_serial->addItem(QString::number(item) );

    connect(&serial,
        SIGNAL(readyRead()),
        this,
        SLOT(dadosRecebidos()));
}

circuito::~circuito()
{
    delete ui;
}

void circuito::on_conectar_clicked(){
    serial.setPortName(ui->porta_serial->currentText());
    serial.setBaudRate(ui->vel_serial->currentText().toInt());

    if(serial.open(QIODevice::ReadWrite)){
        ui->status_conexao->setText("Status: Conectado");
    }
}

void circuito::on_desconectar_clicked(){
    serial.close();
    ui->status_conexao->setText("Status: Desconectado");
}

void circuito::dadosRecebidos(){
    auto data = serial.readAll();

    if(data.indexOf("\"Q1\":")){ //LEITURA DE JSON SEM FUNÇÕES ESPECÍFICAS, indexOf() armazena a posição do caracter
        int i = data.indexOf(":");
        int j = data.indexOf("}");
        QString s;
        while ((i + 1) < j) {
          s += data[i + 1];
          i++;
        }
        qDebug()<<s;
    }

    /*if(dados.contains("Q1")){
        ui->q1->setText(dados["Q1"].toString());
    }

    if(dados.contains("Q2")){
        ui->q2->setText(dados["Q2"].toString());
    }

    if(dados.contains("T1")){
        ui->t1->setText(dados["T1"].toString());
    }

    if(dados.contains("T2")){
        ui->t2->setText(dados["T2"].toString());
    }
    */
}

void circuito::on_ligar1_clicked(){
    serial.write("{\"Q1\":1}");
}

void circuito::on_desligar1_clicked(){
    serial.write("{\"Q1\":0}");
}

void circuito::on_ligar2_clicked(){
    serial.write("{\"Q2\":1}");
}

void circuito::on_desligar2_clicked(){
    serial.write("{\"Q2\":0}");
}

void circuito::on_inserir1_clicked(){//CONVERSÃO DE TEXTO PARA STRING E DEPOIS PARA UM
                                     //TIPO DE ARRAY A FIM DE IMPRIMIR NA SERIAL
    int tempo=ui->t1->text().toInt();
    QString temp="{\"T1\":" + QString::number(tempo) + "}";
    serial.write(temp.toLocal8Bit());
    ui->t1->clear();
}

void circuito::on_inserir2_clicked(){
    int tempo=ui->t2->text().toInt();
    QString temp="{\"T2\":" + QString::number(tempo) + "}";
    serial.write(temp.toLocal8Bit());
    ui->t2->clear();
}
