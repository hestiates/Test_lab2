TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += editor.c \
    load.c \
    move.c \
    save.c \
    show.c \
    mklb.c \
    append_line.c \
    process_forward.c \
    create_text.c \
    remove_all.c \
    showdigitsonly.c \
    paste_n.c

HEADERS += \
    common.h \
    _text.h \
    text.h

QMAKE_CFLAGS += -Wall -Wextra

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
