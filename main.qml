import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import BluetoothDevice 1.0
ApplicationWindow {
    title: qsTr("Bluetooth BLE Tool")
    width: 320
    height: 480
    visible: true

BluetoothDevice{
    id: m_BluetoothDevice
}
BluetoothDeviceView{
    anchors.fill: parent
}
}
