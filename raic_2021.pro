TEMPLATE = app

#DEFINES *= bot_no_qt
DEFINES *= bot_viz

QMAKE_CFLAGS_RELEASE = -O3

QT -= gui
QT -= core

CONFIG *= c++17

SOURCES *= \
    $$files(codegame/*.cpp) \
    $$files(debugging/*.cpp) \
    $$files(model/*.cpp) \
    Stream.cpp \
    TcpStream.cpp \
    main.cpp \

HEADERS *= \
    $$files(codegame/*.hpp) \
    $$files(debugging/*.hpp) \
    $$files(model/*.hpp) \ \
    Stream.hpp \
    TcpStream.hpp \
    runner.h


contains(DEFINES, bot_no_qt) {
    message(Версия для отправки на сервер (без Qt))
    CONFIG -= qt
    CONFIG -= app_bundle
    CONFIG += console

    TARGET = bot
}
contains(DEFINES, bot_viz) {
    message(Бот + визуализатор или управление мышкой)
    QT *= widgets

    TARGET = bot_viz

    SOURCES *=

    HEADERS *= widget.h   \

    RESOURCES +=
}
win32 : {
#    LIBS += ws2_32.dll
    LIBS += C:\Qt\Qt5.12.7\Tools\mingw730_64\x86_64-w64-mingw32\lib\libws2_32.a
}
unix : {
}
message($$TARGET)

