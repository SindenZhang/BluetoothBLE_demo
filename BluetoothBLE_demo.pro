TEMPLATE = app

QT += qml quick widgets bluetooth

SOURCES += main.cpp \
    src/bluetoothdevice.cpp \
    src/deviceinfo.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    src/bluetoothdevice.h \
    src/deviceinfo.h
