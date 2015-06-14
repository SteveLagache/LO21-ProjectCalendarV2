QT      += widgets xml core

QMAKE_CXXFLAGS += -std=c++11

SOURCES += \
    projectcalendar.cpp \
    weekcalendar.cpp \
    projetmanager.cpp \
    projet.cpp \
    tache.cpp \
    agenda.cpp \
    evenement.cpp \
    tachemanager.cpp \
    outils.cpp \
    tacheeditor.cpp \
    projeteditor.cpp \
    time.cpp \
    evenementsimpleeditor.cpp \
    evenementtacheeditor.cpp \
    tacheprogrammeur.cpp \
    main.cpp \
    evenementeditor.cpp \
    evtexport.cpp

FORMS += \
    projectcalendar.ui \
    weekcalendar.ui \
    tacheeditor.ui \
    projeteditor.ui \
    evenementsimpleeditor.ui \
    evenementtacheeditor.ui \
    tacheprogrammeur.ui \
    evenementeditor.ui \
    evtexport.ui

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
    tachemanager.h \
    outils.h \
    tacheeditor.h \
    projeteditor.h \
    evenementsimpleeditor.h \
    evenementtacheeditor.h \
    tacheprogrammeur.h \
    evenementeditor.h \
    evtexport.h

