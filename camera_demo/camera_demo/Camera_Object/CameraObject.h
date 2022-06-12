#ifndef CAMERA_OBJECT_H
#define CAMERA_OBJECT_H
 
#include <QObject>
#include <QThread>
#include <QtQml>
 
 
class CameraObject : public QThread
{
    Q_OBJECT
 
//    QML_ELEMENT
 
    Q_PROPERTY(int iControlCMD READ getiControlCMD WRITE setiControlCMD NOTIFY iControlCMDChanged)
    // Q_PROPERTY(QString sString READ getSString WRITE setSString NOTIFY sStringChanged)
 
public:
    explicit CameraObject(QObject *parent = nullptr);
    Q_INVOKABLE void sendSignal();
    static CameraObject *getInstance();
 
    int getiControlCMD() const;
    void setiControlCMD( int newiControlCMD);
 
    void stop();
    // QString getSString() const;
    // void setSString(const QString &newSString);
protected:
    virtual void run() override;
private:
    int m_iControlCMD;
    bool bThreadRunning_flg;
    // QString m_sString;
 
signals:
    void iControlCMDChanged(int m_iControlCMD);
    // void sStringChanged();
public slots:
    void slot_iControl();
 
};
 
#endif // CAMERA_OBJECT_H