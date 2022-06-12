//CameraObject.c

#include "CameraObject.h"
#include "../Linux_UVC_Camera/camera_app.h"
#include <QDebug>

CameraObject::CameraObject(QObject *parent)
{
}

void CameraObject::sendSignal()
{
    qDebug() << "CameraObject::"<<__FUNCTION__;
    capture_one_photo();
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
    emit iControlCMDChanged(m_iControlCMD);
    qDebug() << "CameraObject::"<<"emit iControlCMDChanged:"<<m_iControlCMD;
}
//slot_iControl
void CameraObject::slot_iControl()
{
    qDebug() << "CameraObject::"<<__FUNCTION__;
    //qDebug() << "CameraObject::"<<"emit iControlCMDChanged";
}
