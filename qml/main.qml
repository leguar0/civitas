import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    id: root
    visible: true
    width: 800
    height: 600
    title: "City Grid"

    Item {
        id: city
        Column {
            spacing: 0
            Repeater {
                model: 600 / 50
                delegate: Row {
                    spacing: 0
                    Repeater {
                        model: 800 / 50
                        delegate: Rectangle {
                            width: 50
                            height: 50
                            color: "#a2d5f2"
                            border.color: "#264653"
                            border.width: 1

                            MouseArea {
                                anchors.fill: parent
                                onClicked: {
                                    parent.color = "#f4a261"
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
