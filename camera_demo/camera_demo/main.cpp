#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "./Linux_UVC_Camera/camera_app.h"
#include "Camera_Object/CameraObject.h"
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    //LOGIC APP
    //capture_one_photo();
    QGuiApplication app(argc, argv);

    qmlRegisterType<CameraObject>("CameraObject",1,0,"CameraObject");
    QQmlApplicationEngine engine;
    // QQmlContext *context = engine.rootContext();
    // context->setContextProperty("camera_control",&capture_one_photo);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
