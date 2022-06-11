#include "carcontrl.h"
#include "ui_carcontrl.h"

carContrl::carContrl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::carContrl)
{
    ui->setupUi(this);

    ctrlSocket = new QTcpSocket;

    connect(ctrlSocket,SIGNAL(connected()),this,SLOT(slotConnect()));
    connect(ctrlSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(slotError(QAbstractSocket::SocketError)));
    connect(ctrlSocket,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
    connect(ctrlSocket,SIGNAL(readyRead()),this,SLOT(slotReadData()));

}

carContrl::~carContrl()
{
    delete ui;
}

void carContrl::on_pushButtonCtrlConnect_clicked()
{
    qint16 port = ui->lineEditPort->text().toInt();
    QString host_ip = ui->lineEditIP->text();

  //  connect(ctrlSocket,SIGNAL(connected()),this,SLOT(slotConnect()));
  //  connect(ctrlSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(slotError(QAbstractSocket::SocketError)));
  //  connect(ctrlSocket,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
  //  connect(ctrlSocket,SIGNAL(readyRead()),this,SLOT(slotReadData()));

    ctrlSocket->connectToHost(QHostAddress(host_ip),port);   //连接到服务器
}

void carContrl::slotConnect()
{
    qDebug() << "Connect success";
    QMessageBox::warning(this,"yes","Connected");

    //QString reqStr = "GET /?action=stream\r\n\r\n";
    //socket->write(reqStr.toLatin1().data(),reqStr.toLatin1().size());
}

void carContrl::slotDisconnected()
{
    qDebug() << "Connect lost";
    QMessageBox::warning(this,"Warning","Disconnected");
}

void carContrl::slotError(QAbstractSocket::SocketError)
{
    qDebug() << "Error : connect lost";
    QMessageBox::warning(this,"Error","Connect has lost...");
}

void carContrl::slotReadData()
{
    while(ctrlSocket->bytesAvailable() > 0){
        QByteArray temp;
        temp.resize(ctrlSocket->bytesAvailable());
        qDebug() << temp;

        ctrlSocket->read(temp.data(), temp.size());

        ui->listWidgetSpeed->addItem(QString(temp));
        ui->listWidgetSpeed->scrollToBottom();
    }
}

void carContrl::on_pushButtonForward_clicked()
{
    qDebug() << "Forward";
    QString temp = "g";
    ctrlSocket->write(temp.toLatin1().data(), temp.toLatin1().size());
}

void carContrl::on_pushButtonBack_clicked()
{
    qDebug() << "Back";
    QString temp = "b";
    ctrlSocket->write(temp.toLatin1().data(), temp.toLatin1().size());
}

void carContrl::on_pushButtonLeft_clicked()
{
    qDebug() << "Turn Left";
    QString temp = "l";
    ctrlSocket->write(temp.toLatin1().data(), temp.toLatin1().size());
}

void carContrl::on_pushButtonRight_clicked()
{
    qDebug() << "Turn Right";
    QString temp = "r";
    ctrlSocket->write(temp.toLatin1().data(), temp.toLatin1().size());
}

void carContrl::on_pushButtonStop_clicked()
{
    qDebug() << "Stop";
    QString temp = "s";
    ctrlSocket->write(temp.toLatin1().data(), temp.toLatin1().size());
}

void carContrl::on_pushButtonLeftIN_clicked()
{
    qDebug() << "Left Up";
    QString temp = "i";
    ctrlSocket->write(temp.toLatin1().data(), temp.toLatin1().size());
}

void carContrl::on_pushButtonLeftDE_clicked()
{
    qDebug() << "Left Down";
    QString temp = "k";
    ctrlSocket->write(temp.toLatin1().data(), temp.toLatin1().size());
}

void carContrl::on_pushButtonRightIN_clicked()
{
    qDebug() << "Right Up";
    QString temp = "j";
    ctrlSocket->write(temp.toLatin1().data(), temp.toLatin1().size());
}

void carContrl::on_pushButtonRightDE_clicked()
{
    qDebug() << "Right Down";
    QString temp = "m";
    ctrlSocket->write(temp.toLatin1().data(), temp.toLatin1().size());
}

void carContrl::on_pushButtonSpeedUp_clicked()
{
    qDebug() << "Speed Up";
    QString temp = "u";
    ctrlSocket->write(temp.toLatin1().data(), temp.toLatin1().size());
}

void carContrl::on_pushButtonSpeedDown_clicked()
{
    qDebug() << "Speed Down";
    QString temp = "d";
    ctrlSocket->write(temp.toLatin1().data(), temp.toLatin1().size());
}

