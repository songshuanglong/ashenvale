TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lpthread

SOURCES += main.cpp \
    src/as_condition.cpp \
    src/as_mutex.cpp \
    src/as_object.cpp \
    src/as_poll.cpp \
    src/as_pollevent.cpp \
    src/as_server.cpp \
    src/as_socket.cpp \
    src/as_tcpclient.cpp \
    src/as_tcpserver.cpp \
    src/as_tcpsocket.cpp \
    src/as_thread.cpp \
    src/as_innerthread.cpp

HEADERS += \
    include/as_condition.h \
    include/as_engine.h \
    include/as_mutex.h \
    include/as_object.h \
    include/as_poll.h \
    include/as_pollevent.h \
    include/as_server.h \
    include/as_socket.h \
    include/as_tcpclient.h \
    include/as_tcpserver.h \
    include/as_tcpsocket.h \
    include/as_thread.h \
    include/as_innerthread.h
