QT       += core gui widgets network
QT += texttospeech
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


INCLUDEPATH += $$PWD/include



SOURCES += \
    include/audiorecord.cpp \
    include/tts.cpp \
    src/assistant.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/tts.cpp

HEADERS += \
    include/assistant.h \
    include/audiorecord.h \
    include/mainwindow.h \
    include/tts.h

FORMS += \
    forms/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target





LIBS += -L$$PWD/libs/lib/pocketsphinx/ -lpocketsphinx


INCLUDEPATH += $$PWD/libs/include/pocketsphinx
DEPENDPATH += $$PWD/libs/include/pocketsphinx


