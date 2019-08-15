#ifndef CIRCUITO_H
#define CIRCUITO_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

namespace Ui {
class circuito;
}

class circuito : public QMainWindow
{
    Q_OBJECT
    QSerialPort serial;

public:
    explicit circuito(QWidget *parent = nullptr);
    ~circuito();


private slots:

    void dadosRecebidos();

    void on_conectar_clicked();

    void on_desconectar_clicked();

    void on_ligar1_clicked();

    void on_desligar1_clicked();

    void on_ligar2_clicked();

    void on_desligar2_clicked();

    void on_inserir1_clicked();

    void on_inserir2_clicked();

private:
    Ui::circuito *ui;
};

#endif // CIRCUITO_H
