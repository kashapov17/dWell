QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admindialog.cpp \
    commandantdialog.cpp \
    dormitory.cpp \
    habitant.cpp \
    habitantadddialog.cpp \
    initsetupdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    rbook.cpp \
    room.cpp \
    studentdialog.cpp \
    ubook.cpp \
    user.cpp \
    useradddialog.cpp

HEADERS += \
    admindialog.h \
    commandantdialog.h \
    config.h \
    dormitory.h \
    habitant.h \
    habitantadddialog.h \
    initsetupdialog.h \
    mainwindow.h \
    rbook.h \
    room.h \
    studentdialog.h \
    ubook.h \
    user.h \
    useradddialog.h

FORMS += \
    admindialog.ui \
    commandantdialog.ui \
    habitantadddialog.ui \
    initsetupdialog.ui \
    mainwindow.ui \
    studentdialog.ui \
    useradddialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
