#include "widget.h"
#include <QApplication>
#include "./Linux_UVC_Camera/camera_app.h"
#include "leds_app.h"
int main(int argc, char *argv[])
{
    //LOGIC APP
    capture_one_photo();
    //leds_control();
    //UI
//    QApplication a(argc, argv);
//    Widget w;
//    w.show();

//    return a.exec();
    return 0;
}
