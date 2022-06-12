QT += quick

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TARGET = camera_demo
TEMPLATE = app

SOURCES += \
        Camera_Object/CameraObject.cpp \
        Linux_UVC_Camera/bmp.c \
        Linux_UVC_Camera/camera.c \
        Linux_UVC_Camera/camera_app.c \
        main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Linux_UVC_Camera/readme.txt

HEADERS += \
    Camera_Object/CameraObject.h \
    Linux_UVC_Camera/camera.h \
    Linux_UVC_Camera/camera_app.h \
    Linux_UVC_Camera/includes.h \
    Linux_UVC_Camera/bmp.h
