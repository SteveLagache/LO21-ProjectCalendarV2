QT      += widgets xml core

QMAKE_CXXFLAGS += -std=c++11

SOURCES += \
    main.cpp \
    projectcalendar.cpp \
    weekcalendar.cpp \
    projetmanager.cpp \
    projet.cpp \
    tache.cpp \
    evenement.cpp \
    agenda.cpp

FORMS += \
    projectcalendar.ui \
    weekcalendar.ui

HEADERS += \
    projectcalendar.h \
    weekcalendar.h \
    projetmanager.h \
    projet.h \
    tache.h \
    evenement.h \
    agenda.h \
    exception.h \

