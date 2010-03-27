# -------------------------------------------------
# Project created by QtCreator 2010-03-18T06:50:13
# -------------------------------------------------
QT += network \
    xml \
    xmlpatterns
TARGET = HighScore
TEMPLATE = app
SOURCES += main.cpp \
    highscore.cpp \
    settings.cpp \
    about.cpp
HEADERS += highscore.h \
    settings.h \
    about.h
FORMS += highscore.ui \
    settings.ui \
    about.ui
RC_FILE = HighScore.rc
RESOURCES += resource.qrc
