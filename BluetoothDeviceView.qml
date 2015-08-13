import QtQuick 2.0

ListView {
    id: rootBluetoothDeviceView
    width: 100
    height: 62
    model: m_BluetoothDevice.devicesList
    delegate: Column{

        width: parent.width
        height: 48
        Text {

            text: qsTr(modelData.deviceName)
        }
        Text {

            text: qsTr(modelData.deviceAddress)
        }
    }
}

