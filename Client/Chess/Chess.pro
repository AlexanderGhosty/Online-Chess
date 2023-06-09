QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chessboard.cpp \
    chesspiece.cpp \
    chesssquare.cpp \
    chessview.cpp \
    gamestate.cpp \
    main.cpp \
    mainwindow.cpp \
    piecebishop.cpp \
    pieceking.cpp \
    pieceknight.cpp \
    piecepawn.cpp \
    piecequeen.cpp \
    piecerook.cpp \
    room.cpp

HEADERS += \
    chessboard.h \
    chesspiece.h \
    chesssquare.h \
    chessview.h \
    gamestate.h \
    mainwindow.h \
    piecebishop.h \
    pieceking.h \
    pieceknight.h \
    piecepawn.h \
    piecequeen.h \
    piecerook.h \
    room.h

FORMS += \
    mainwindow.ui \
    room.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    images/white_pawn.png

RESOURCES += \
    resource.qrc

LIBS += -lws2_32
