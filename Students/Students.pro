TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.c \
        students.c \
        vector.c

HEADERS += \
    students.h \
    vector.h

LIBS+=/lib/x86_64-linux-gnu/libncursesw5-dev.so
INCLUDEPATH+=/usr/include/ncursesw
