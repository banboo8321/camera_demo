#-------------------------------------------------
#
# Project created by QtCreator 2016-08-25T15:34:58
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mjpg-streamer
TEMPLATE = app

CONFIG += debug_and_release
CONFIG(debug, debug|release){
    DESTDIR = ./debug #bin file
    OBJECTS_DIR = tmp/debug/.obj
    MOC_DIR = tmp/debug/.moc
    UI_DIR =  tmp/debug/.ui
    RCC_DIR =  tmp/debug/.qrc
#    QMAKE_CFLAGS += -D_GNU_SOURCE -DFIX_ENDIAN -DLITTLE_ENDIAN -DDELAYERING -Wno-missing-braces
}
CONFIG(release, debug|release){
    DESTDIR = ./release  #bin file
    OBJECTS_DIR = tmp/release/.obj
    MOC_DIR = tmp/release/.moc
    UI_DIR =  tmp/release/.ui
    RCC_DIR =  tmp/release/.qrc
#    QMAKE_CFLAGS += -DRELEASE -D_GNU_SOURCE -DFIX_ENDIAN -DLITTLE_ENDIAN -DDELAYERING -Wno-missing-braces
}

SOURCES += main.cpp\
    leds_app.c \
    widget.cpp \
    carcontrl.cpp   \
    Linux_UVC_Camera/bmp.c \
    Linux_UVC_Camera/camera_app.c \
    Linux_UVC_Camera/camera.c 
    

HEADERS  += widget.h \
    Linux_UVC_Camera/camera_app.h \
    carcontrl.h\
    Linux_UVC_Camera/bmp.h \
    Linux_UVC_Camera/includes.h \
    Linux_UVC_Camera/camera.h  \
    leds_app.h

#INCLUDEPATH += . \
#    ./Linux_UVC_Camera

FORMS    += widget.ui \
    carcontrl.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
