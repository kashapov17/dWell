QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

HEADERS +=  ../dWell/user.h \
            ../dWell/ubook.h \

SOURCES +=  tst_testuser.cpp \
            tst_testubook.cpp \
            ../dWell/user.cpp \
            ../dWell/ubook.cpp \
