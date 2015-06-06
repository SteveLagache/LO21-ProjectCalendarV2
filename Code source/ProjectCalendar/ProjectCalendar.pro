QT      += widgets xml core

QMAKE_CXXFLAGS += -std=c++11

SOURCES += \
    main.cpp \
    projectcalendar.cpp \
    weekcalendar.cpp \
    projetmanager.cpp \
    projet.cpp \
    tache.cpp \
    agenda.cpp \
    evenement.cpp

FORMS += \
    projectcalendar.ui \
    weekcalendar.ui

HEADERS += \
    projectcalendar.h \
    weekcalendar.h \
    projetmanager.h \
    projet.h \
    tache.h \
    exception.h \
    time.h \
    agenda.h \
    evenement.h \

