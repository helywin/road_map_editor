//
// Created by jiang on 2021/5/26.
//

#include "QgsRoadMapEditorPlugin.hpp"
#include <QToolBar>
#include <QAction>
#include <qgisinterface.h>

const QString QgsRoadMapEditorPlugin::NAME = "RoadMapEditor";
const QString QgsRoadMapEditorPlugin::DESCRIPTION = "Road Map Editor";
const QString QgsRoadMapEditorPlugin::CATEGORY = "Plugins";
const QString QgsRoadMapEditorPlugin::VERSION = "Version 0.0.1";
const QString QgsRoadMapEditorPlugin::ICON = QStringLiteral(":icon/map_editor.png");
const QgisPlugin::PluginType QgsRoadMapEditorPlugin::TYPE = PluginType::UI;

class QgsRoadMapEditorPluginPrivate
{
public:
    Q_DECLARE_PUBLIC(QgsRoadMapEditorPlugin)
    QgsRoadMapEditorPlugin *q_ptr;
    QToolBar *mToolbar;
    QAction *mToolbarDock;
    QgisInterface *mQgisIf;

    explicit QgsRoadMapEditorPluginPrivate(QgsRoadMapEditorPlugin *p);
};

QgsRoadMapEditorPluginPrivate::QgsRoadMapEditorPluginPrivate(QgsRoadMapEditorPlugin *p) :
        q_ptr(p)
{

}

QgsRoadMapEditorPlugin::QgsRoadMapEditorPlugin(QgisInterface *qgisIf) :
        QgisPlugin(NAME, DESCRIPTION, CATEGORY, VERSION, TYPE),
        d_ptr(new QgsRoadMapEditorPluginPrivate(this))
{
    Q_D(QgsRoadMapEditorPlugin);
    d->mQgisIf = qgisIf;
    system("touch /home/jiang/qgis_plugin/create");
}

QgsRoadMapEditorPlugin::~QgsRoadMapEditorPlugin()
{

}

void QgsRoadMapEditorPlugin::initGui()
{
    Q_D(QgsRoadMapEditorPlugin);
    d->mToolbarDock = new QAction(QIcon(""), tr("Hello World"), this);
    d->mToolbarDock->setWhatsThis(tr("Draw on the map canvas."));
    connect(d->mToolbarDock, &QAction::triggered, [this] {

    });

    d->mQgisIf->addVectorToolBarIcon(d->mToolbarDock);
    d->mToolbar = d->mQgisIf->addToolBar("Road Map Editor");
    d->mToolbar->addAction(d->mToolbarDock);
    d->mQgisIf->addPluginToMenu(tr("&Hello World"), d->mToolbarDock);
    system("touch /home/jiang/qgis_plugin/init");
}

void QgsRoadMapEditorPlugin::unload()
{

}

/**
 * Required extern functions needed  for every plugin
 * These functions can be called prior to creating an instance
 * of the plugin class
 */
// Class factory to return a new instance of the plugin class
QGISEXTERN QgisPlugin *classFactory(QgisInterface *qgisInterfacePointer)
{
    return new QgsRoadMapEditorPlugin(qgisInterfacePointer);
}

// Return the name of the plugin - note that we do not user class members as
// the class may not yet be insantiated when this method is called.
QGISEXTERN QString name()
{
    return QgsRoadMapEditorPlugin::NAME;
}

// Return the description
QGISEXTERN QString description()
{
    return QgsRoadMapEditorPlugin::DESCRIPTION;
}

// Return the category
QGISEXTERN QString category()
{
    return QgsRoadMapEditorPlugin::CATEGORY;
}

// Return the type (either UI or MapLayer plugin)
QGISEXTERN int type()
{
    return QgsRoadMapEditorPlugin::TYPE;
}

// Return the version number for the plugin
QGISEXTERN QString version()
{
    return QgsRoadMapEditorPlugin::VERSION;
}

QGISEXTERN QString icon()
{
    return QgsRoadMapEditorPlugin::ICON;
}

// Delete ourself
QGISEXTERN void unload(QgisPlugin *pluginPointer)
{
    delete pluginPointer;
}
