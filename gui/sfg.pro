######################################################################
# Automatically generated by qmake (3.0) Wed Aug 10 20:38:48 2016
######################################################################
# To generate Visual C++ Makefiles: qmake sfg.pro
# To generate Visual C++ Project Files: qmake -tp vc sfg.pro
######################################################################
QT       += core gui widgets

TEMPLATE = app
TARGET = sfg

CPP_LIB = ../cpp_lib

INCLUDEPATH += .
INCLUDEPATH += $$CPP_LIB

# Input
SOURCES += main.cpp
SOURCES += mainwindow.cpp
SOURCES += FormsModel.cpp
SOURCES += $$CPP_LIB/utils.cpp
#SOURCES += $$CPP_LIB/logger.cpp

# Input
HEADERS += mainwindow.h
HEADERS += FormsModel.h
HEADERS += $$CPP_LIB/utils.h
HEADERS += $$CPP_LIB/logger.h
