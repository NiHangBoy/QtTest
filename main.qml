import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

//window containing the application
ApplicationWindow {
    id:window
    visible: true
    //title of the application
    title: qsTr("Hello World")
    width: 640
    height: 480
    property int someNumber: 3456

    signal qmlSignal(var anObject)

    MouseArea{
        anchors.fill: parent
        onClicked: window.qmlSignal("Hello from QML")
    }


    function myQmlFunction(msg){
        console.log("Got message:",msg)
        return "some return value"
    }

    //menu containing two menu items
    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    //Content Area

    //a button in the middle of the content area
    Button {
        text: qsTr("Hello World")
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }
}
