QT       += core gui printsupport sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    changepass.cpp \
    donated.cpp \
    main.cpp \
    mainpageadmin.cpp \
    mainpagemovies.cpp \
    mainwindow.cpp \
    movie.cpp \
    newmovieadd.cpp \
    profilepage.cpp \
    registerpage.cpp \
    user.cpp

HEADERS += \
    admin.h \
    changepass.h \
    donated.h \
    mainpageadmin.h \
    mainpagemovies.h \
    mainwindow.h \
    movie.h \
    newmovieadd.h \
    profilepage.h \
    registerpage.h \
    user.h

FORMS += \
    changepass.ui \
    mainpageadmin.ui \
    mainpagemovies.ui \
    mainwindow.ui \
    newmovieadd.ui \
    profilepage.ui \
    registerpage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
