QT       += core gui \
            printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admindialog.cpp \
    commandantdialog.cpp \
    doc.cpp \
    dormitory.cpp \
    habitant.cpp \
    habitanteditdialog.cpp \
    initsetupdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    rbook.cpp \
    relocationdialog.cpp \
    room.cpp \
    studentdialog.cpp \
    tools.cpp \
    ubook.cpp \
    user.cpp \
    usereditdialog.cpp

HEADERS += \
    admindialog.h \
    commandantdialog.h \
    config.h \
    doc.h \
    dormitory.h \
    habitant.h \
    habitanteditdialog.h \
    initsetupdialog.h \
    mainwindow.h \
    rbook.h \
    relocationdialog.h \
    room.h \
    studentdialog.h \
    tools.h \
    ubook.h \
    user.h \
    usereditdialog.h

FORMS += \
    admindialog.ui \
    commandantdialog.ui \
    habitanteditdialog.ui \
    initsetupdialog.ui \
    mainwindow.ui \
    relocationdialog.ui \
    studentdialog.ui \
    usereditdialog.ui

RESOURCES += \
    resources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

