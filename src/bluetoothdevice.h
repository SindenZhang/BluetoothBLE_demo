#ifndef BLUETOOTHDEVICE_H
#define BLUETOOTHDEVICE_H

#include <QObject>
#include <QVariant>
#include <QBluetoothDeviceDiscoveryAgent>

class BluetoothDevice : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QVariant devicesList READ getDevices NOTIFY devicesUpdated)


public:
    explicit BluetoothDevice(QObject *parent = 0);
    ~BluetoothDevice();
    QVariant getDevices();

public slots:
    void startDeviceDiscovery();
    void stopDeviceDiscovery();

Q_SIGNALS:
    void devicesUpdated();

private slots:
   void appendDeviceList(const QBluetoothDeviceInfo &info);
   void deviceScanError(QBluetoothDeviceDiscoveryAgent::Error error);
   void deviceScanFinished();
private:
    QBluetoothDeviceDiscoveryAgent *m_discoveryAgent;
    QList<QObject*> m_devices;


};

#endif // BLUETOOTHDEVICE_H
