#-------------------------------------------------
#
# Project created by QtCreator 2017-12-18T13:05:38
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = supercomputer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    configuration/configuration.cpp \
    jobs/job.cpp \
    statistics/statistics.cpp \
    statistics/week.cpp \
    system/state.cpp \
    system/system.cpp \
    users/user.cpp \
    utils/utils.cpp

HEADERS  += mainwindow.h \
    configuration/configuration.h \
    jobs/job.h \
    jobs/type.h \
    statistics/statistics.h \
    statistics/week.h \
    system/state.h \
    system/statetype.h \
    system/system.h \
    users/group.h \
    users/user.h \
    utils/utils.h

FORMS    += mainwindow.ui
