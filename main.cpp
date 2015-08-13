#include <QApplication>
#include <QtQml/qqml.h>
#include <QQmlEngine>
#include <QQmlApplicationEngine>
#include "src/bluetoothdevice.h"
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");

   // QTextCodec::setCodecForTr(codec);

    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());


    qmlRegisterType<BluetoothDevice>("BluetoothDevice", 1, 0, "BluetoothDevice");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
