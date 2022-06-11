#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QHostAddress>
#include <QMessageBox>
#include <QTextStream>
#include <QByteArray>
#include <QTcpSocket>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void slotConnect();
    void slotDisconnected();
    void slotError(QAbstractSocket::SocketError);
    void slotReadData();

    void on_pushButtonContrl_clicked();

private:

    Ui::Widget *ui;

    QTcpSocket *socket;

    int flag;
    int framlenth;
};

#endif // WIDGET_H
