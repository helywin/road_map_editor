//
// Created by jiang on 2021/5/26.
//

#ifndef ROAD_MAP_EDITOR_QGSROADMAPEDITORPLUGIN_HPP
#define ROAD_MAP_EDITOR_QGSROADMAPEDITORPLUGIN_HPP

#include <qgis.h>
#include <qgisplugin.h>

class QgsRoadMapEditorPluginPrivate;

class QgsRoadMapEditorPlugin : public QObject, public QgisPlugin
{
Q_OBJECT
public:
    static const QString NAME;
    static const QString DESCRIPTION;
    static const QString CATEGORY;
    static const QString VERSION;
    static const QString ICON;
    static const QgisPlugin::PluginType TYPE;

public:
    explicit QgsRoadMapEditorPlugin(QgisInterface *qgisIf);
    ~QgsRoadMapEditorPlugin() override;

public slots:
    void initGui() override;
    void unload() override;

private:
    Q_DECLARE_PRIVATE(QgsRoadMapEditorPlugin)
    Q_DISABLE_COPY(QgsRoadMapEditorPlugin)
    QScopedPointer<QgsRoadMapEditorPluginPrivate> d_ptr;
};

#endif //ROAD_MAP_EDITOR_QGSROADMAPEDITORPLUGIN_HPP
