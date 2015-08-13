#ifndef BLUETOOTHDEVICE_H
#define BLUETOOTHDEVICE_H

#include <QObject>
#include <QBluetoothDeviceDiscoveryAgent>

class BluetoothDevice : public QObject
{
    Q_OBJECT
public:
    explicit BluetoothDevice(QObject *parent = 0);
    ~BluetoothDevice();

public slots:
    void startDeviceDiscovery();
    void stopDeviceDiscovery();
signals:

private slots:
//    void deviceScanFinished();
//    void deviceScanError(QBluetoothDeviceDiscoveryAgent::Error);

   void appendDeviceList(const QBluetoothDeviceInfo &info);
   void deviceScanError(QBluetoothDeviceDiscoveryAgent::Error error);
   void deviceScanFinished();
private:
    QBluetoothDeviceDiscoveryAgent *m_discoveryAgent;
};

#endif // BLUETOOTHDEVICE_H
