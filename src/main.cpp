#include <qgis/qgsapplication.h>
#include <qgis/qgis_gui.h>
#include "Window.hpp"

int main(int argc, char *argv[])
{
    QgsApplication a(argc, argv, true);
//    QgsApplication::setPrefixPath("E:/Program Files/QGIS 3.12/", true);
    QgsApplication::initQgis();    //初始化QGIS应用
    Window window;
    window.show();
    return QgsApplication::exec();
}
