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
    src/configuration/configuration.cpp \
    src/jobs/job.cpp \
    src/statistics/statistics.cpp \
    src/statistics/week.cpp \
    src/system/state.cpp \
    src/system/system.cpp \
    src/users/user.cpp \
    src/utils/utils.cpp

HEADERS  += mainwindow.h \
    src/configuration/configuration.h \
    src/jobs/job.h \
    src/jobs/type.h \
    src/statistics/statistics.h \
    src/statistics/week.h \
    src/system/state.h \
    src/system/statetype.h \
    src/system/system.h \
    src/users/group.h \
    src/users/user.h \
    src/utils/utils.h

FORMS    += mainwindow.ui
