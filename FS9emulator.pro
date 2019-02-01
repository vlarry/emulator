#-------------------------------------------------
#
# Project created by QtCreator 2017-06-15T11:47:37
#
#-------------------------------------------------

QT += core gui serialport sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FS9emulator
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    qcmd.cpp \
    ciodevice.cpp \
    qkey.cpp \
    qcommand.cpp \
    cconfigurationmodulewidget.cpp \
    csetinput.cpp \
    cinputhelp.cpp \
    cbzuinterface.cpp \
    qled.cpp \
    cdbcontroller.cpp \
    cdbjornal.cpp \
    cappendinfodialog.cpp

HEADERS  += mainwindow.h \
    qcmd.h \
    ciodevice.h \
    qkey.h \
    qcommand.h \
    cconfigurationmodulewidget.h \
    csetinput.h \
    cinputhelp.h \
    cbzuinterface.h \
    qled.h \
    cdbcontroller.h \
    cdbjornal.h \
    cappendinfodialog.h

FORMS    += mainwindow.ui \
    command.ui \
    configurationmodulewidget.ui \
    setinput.ui \
    inputhelp.ui \
    bzuinterface.ui \
    dbjornal.ui \
    appendinfodialog.ui

win32::RC_FILE = \
                 resource/icon.rc

RESOURCES += \
    resource.qrc
