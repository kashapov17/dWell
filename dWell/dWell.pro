QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admindialog.cpp \
    book.cpp \
    bookentry.cpp \
    commandantdialog.cpp \
    docquery.cpp \
    habitant.cpp \
    hbook.cpp \
    main.cpp \
    mainwindow.cpp \
    qbook.cpp \
    query.cpp \
    rbook.cpp \
    relocquery.cpp \
    room.cpp \
    studentdialog.cpp \
    ubook.cpp \
    user.cpp

HEADERS += \
    admindialog.h \
    book.h \
    bookentry.h \
    commandantdialog.h \
    config.h \
    docquery.h \
    habitant.h \
    hbook.h \
    mainwindow.h \
    qbook.h \
    query.h \
    rbook.h \
    relocquery.h \
    room.h \
    studentdialog.h \
    ubook.h \
    user.h

FORMS += \
    admindialog.ui \
    commandantdialog.ui \
    mainwindow.ui \
    studentdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
