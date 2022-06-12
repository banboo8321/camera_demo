//CameraObject.c

#include "CameraObject.h"
#include "../Linux_UVC_Camera/camera_app.h"
#include <QDebug>

CameraObject::CameraObject(QObject *parent)
    :QThread(parent)
{

}
//CameraObject::~CameraObject()
//{}
void CameraObject::sendSignal()
{
    qDebug() << "CameraObject::"<<__FUNCTION__;
    emit iControlCMDChanged(m_iControlCMD);
}
int CameraObject::getiControlCMD() const
{
    qDebug() << "CameraObject::"<<__FUNCTION__;
    return m_iControlCMD;
}
void CameraObject::setiControlCMD(int in_value)
{
    qDebug() << "CameraObject::"<<__FUNCTION__;
    m_iControlCMD = in_value;
    //CameraObject.start();
    emit iControlCMDChanged(m_iControlCMD);
    qDebug() << "CameraObject::"<<"emit iControlCMDChanged:"<<m_iControlCMD;
}
//slot_iControl
void CameraObject::slot_iControl()
{
    qDebug() << "CameraObject::"<<__FUNCTION__;
    //qDebug() << "CameraObject::"<<"emit iControlCMDChanged";
}

void CameraObject::run()
{
    qDebug() << "CameraObject::"<<__FUNCTION__;
    bThreadRunning_flg = true;
    while(bThreadRunning_flg)
    {
        if(1 == getiControlCMD()){
            setiControlCMD(0);
            capture_one_photo();
        }
        sleep(1);
    }

//    if(isInterruptionRequested()){
//        break;
//    }
}
void CameraObject::stop()
{
    bThreadRunning_flg = false;
    if(isRunning())
    {
        exit();
        wait();
    }
}
