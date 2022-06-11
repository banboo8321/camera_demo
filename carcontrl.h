#ifndef CARCONTRL_H
#define CARCONTRL_H

#include <QWidget>

#include <QHostAddress>
#include <QMessageBox>
#include <QTextStream>
#include <QByteArray>
#include <QTcpSocket>
#include <QDebug>

namespace Ui {
class carContrl;
}

class carContrl : public QWidget
{
    Q_OBJECT

public:
    explicit carContrl(QWidget *parent = 0);
    ~carContrl();

private slots:
    void on_pushButtonCtrlConnect_clicked();

    void slotConnect();
    void slotDisconnected();
    void slotError(QAbstractSocket::SocketError);
    void slotReadData();

    void on_pushButtonForward_clicked();

    void on_pushButtonBack_clicked();

    void on_pushButtonLeft_clicked();

    void on_pushButtonRight_clicked();

    void on_pushButtonStop_clicked();

    void on_pushButtonLeftIN_clicked();

    void on_pushButtonLeftDE_clicked();

    void on_pushButtonRightIN_clicked();

    void on_pushButtonRightDE_clicked();

    void on_pushButtonSpeedUp_clicked();

    void on_pushButtonSpeedDown_clicked();

private:
    Ui::carContrl *ui;

    QTcpSocket *ctrlSocket;
};

#endif // CARCONTRL_H
