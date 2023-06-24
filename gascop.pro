TEMPLATE += app
QT += widgets gui core network

CONFIG += qt c++11
LIBS += -lSDL2 -lSDL2_mixer

RESOURCES +=   	mainwin.qrc
FORMS += mainwin.ui pagerid.ui

HEADERS += mainwin.h clpclib.h pagerid.h

SOURCES += mainwin.cpp clpclib.cpp main.cpp pagerid.cpp
