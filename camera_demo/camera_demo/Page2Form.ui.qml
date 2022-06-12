import QtQuick 2.12
import QtQuick.Controls 2.5
import CameraObject 1.0
Page {
    width: 600
    height: 400

    header: Label {
        text: qsTr("Camera")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10

        Button {
            id: button
            x: 405
            y: 14
            text: qsTr("Take Photo")
            onClicked: {
                console.log("Take Photo button clicked")
                camera.iControlCMD = 1
                camera.sendSignal()
            }
        }
        CameraObject{
            id: camera
        }


    }

    Label {
        text: qsTr("You are on Page for camera.")
        anchors.centerIn: parent
    }
}
