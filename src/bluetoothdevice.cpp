#include "bluetoothdevice.h"
#include <QTime>
#include <QDebug>
BluetoothDevice::BluetoothDevice(QObject *parent) : QObject(parent)
{
    //! [les-devicediscovery-1]
    m_discoveryAgent = new QBluetoothDeviceDiscoveryAgent();

    connect(m_discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &BluetoothDevice::appendDeviceList);

    connect(m_discoveryAgent, SIGNAL(error(QBluetoothDeviceDiscoveryAgent::Error)),
            this, SLOT(deviceScanError(QBluetoothDeviceDiscoveryAgent::Error)));

    connect(m_discoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished,
            this, &BluetoothDevice::deviceScanFinished);
    //! [les-devicediscovery-1]
    m_discoveryAgent->start();
}

BluetoothDevice::~BluetoothDevice()
{

}

void BluetoothDevice::startDeviceDiscovery()
{

}

void BluetoothDevice::stopDeviceDiscovery()
{
    m_discoveryAgent->stop();
}

void BluetoothDevice::appendDeviceList(const QBluetoothDeviceInfo &info)
{
    qDebug() << info.name() << QTime::currentTime().toString();
}

void BluetoothDevice::deviceScanError(QBluetoothDeviceDiscoveryAgent::Error error)
{
    switch (error)
    {
    case QBluetoothDeviceDiscoveryAgent::NoError:
            qDebug() << "NoError";
        break;
    case QBluetoothDeviceDiscoveryAgent::PoweredOffError:
            qDebug() << "PoweredOffError";
        break;
    case QBluetoothDeviceDiscoveryAgent::InputOutputError:
            qDebug() << "InputOutputError";
        break;
    case QBluetoothDeviceDiscoveryAgent::InvalidBluetoothAdapterError:
            qDebug() << "InvalidBluetoothAdapterError";
        break;

    default:
            qDebug() << "An unknown error has occurred.";
        break;
    }
}

void BluetoothDevice::deviceScanFinished()
{
     qDebug() << "deviceScanFinished";
     foreach (QBluetoothDeviceInfo info, m_discoveryAgent->discoveredDevices())
     {
         qDebug() << info.address().toString();
     }
}
