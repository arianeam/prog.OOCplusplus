QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addwindow.cpp \
    alterarsenha.cpp \
    alterarusername.cpp \
    configwindow.cpp \
    editwindow.cpp \
    main.cpp \
    loginwindow.cpp \
    mainwindow.cpp

HEADERS += \
    Banco_de_dados.h \
    Livro.h \
    Usuario.h \
    addwindow.h \
    alterarsenha.h \
    alterarusername.h \
    configwindow.h \
    editwindow.h \
    loginwindow.h \
    mainwindow.h

FORMS += \
    addwindow.ui \
    alterarsenha.ui \
    alterarusername.ui \
    configwindow.ui \
    editwindow.ui \
    loginwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
