#include "widget.h"
#include "ui_widget.h"

#include "carcontrl.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    socket = new QTcpSocket;

    flag = 1;
    framlenth = 0;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    qint16 port = 8080;
    QString host_ip = ui->lineEdit->text();

    qDebug()<<"即将连接到："<<host_ip<<":"<<port;
    connect(socket,SIGNAL(connected()),this,SLOT(slotConnect()));
    connect(socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(slotError(QAbstractSocket::SocketError)));
    connect(socket,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
    connect(socket,SIGNAL(readyRead()),this,SLOT(slotReadData()));

    socket->connectToHost(QHostAddress(host_ip),port);   //连接到服务器
}

void Widget::slotConnect()
{
    qDebug()<<"connect success";
    QMessageBox::warning(this,"yes","连接到服务器");
    QString reqStr = "GET /?action=stream\r\n\r\n";
    socket->write(reqStr.toLatin1().data(),reqStr.toLatin1().size());
}

void Widget::slotDisconnected()
{
    qDebug("connect lost");
    /*fire_flag = 0;
    air_flag = 0;
    body_flag = 0;*/
    QMessageBox::warning(this,"通知","与服务器断开连接");
}

void Widget::slotError(QAbstractSocket::SocketError)
{
    qDebug("connect lost");
    /*fire_flag = 0;
    air_flag = 0;
    body_flag = 0;*/
    QMessageBox::warning(this,"通知","与服务器断开连接");
}

void Widget::slotReadData()
{
    if(flag == 1)
    {
        for(int i = 0; i < 9; i++)
        {
            socket->readLine(100);
        }
        flag = 0;
    }

    if(framlenth == 0)
    {
        if(socket->bytesAvailable() >= 54)
        {
            QByteArray ba;
            ba.resize(54);
            socket->read(ba.data(),ba.size());
            QString msg(ba);
            framlenth = msg.mid(42,8).toInt();
            qDebug() << framlenth;
            socket->readLine();
            socket->readLine();
        }
    }
    else if(framlenth > 0)
    {
        if(socket->bytesAvailable() >= framlenth)
        {
            QByteArray ba;
            ba.resize(framlenth);
            socket->read(ba.data(),ba.size());
            QPixmap pic;
            pic.loadFromData(ba);
            ui->label->setPixmap(pic.scaled(ui->label->width(),ui->label->height()));;
            flag = 2;
            framlenth = 0;
        }
        if(flag == 2)
        {
            socket->readLine();
            socket->readLine();
            flag = 0;
        }
    }
}
void Widget::on_pushButtonContrl_clicked()
{
    carContrl *ctrl_widget = new carContrl();
    ctrl_widget->show();
}
