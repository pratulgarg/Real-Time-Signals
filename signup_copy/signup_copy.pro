QT       += core gui
QT += sql
CONFIG += c++11
INCLUDEPATH += helpers
QT       += network
CONFIG += debug

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    forgotpassword.cpp \
    form.cpp \
    main.cpp \
    mainwindow.cpp \
    real_time.cpp \
    receiverth.cpp \
    registerit.cpp \
    secdialog.cpp \
    sendit.cpp \
    utilities.cpp \


HEADERS += \
    forgotpassword.h \
    form.h \
    mainwindow.h \
    real_time.h \
    receiverth.h \
    registerit.h \
    secdialog.h \
    sendit.h \
    utilities.h \


FORMS += \
    forgotpassword.ui \
    form.ui \
    mainwindow.ui \
    real_time.ui \
    registerit.ui \
    secdialog.ui  \
#    receiver.ui \      # Uncomment or add receiver UI

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
