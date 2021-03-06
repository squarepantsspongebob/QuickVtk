import QtQuick 2.6

import Lib 1.0 as Lib
import Code 1.0 as Code
import TypeInfo 1.0 as TypeInfo

Rectangle {
    id: root;

    color: "#282C34"

    MouseArea {
        anchors.fill: parent;

        onClicked: {
            root.forceActiveFocus();
        }
    }

    Header {
        id: header;

        anchors.left: parent.left;
        anchors.right: parent.right;
        anchors.top: parent.top;
    }

    Lib.SplitView {
        anchors.left: parent.left;
        anchors.right: parent.right;
        anchors.top: header.bottom;
        anchors.bottom: footer.top;

        leftItem: Code.Editor {
            anchors.fill: parent;
        }

        rightItem: Lib.TabView {
            anchors.fill: parent;

            Preview {
                anchors.fill: parent;
            }

            LogView {
                anchors.fill: parent;
            }
        }
    }

    TypeInfo.List {
        id: typeList;

        anchors.right: parent.right;
        anchors.top: header.bottom;
        anchors.bottom: footer.top;
    }

    Footer {
        id: footer;

        anchors.left: parent.left;
        anchors.right: parent.right;
        anchors.bottom: parent.bottom;
    }
}
