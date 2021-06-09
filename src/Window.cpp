//
// Created by jiang on 2021/6/9.
//

#include "Window.hpp"
#include <QWidget>
#include <QToolBar>
#include <QToolButton>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QLabel>
#include <QStatusBar>
#include <qgis/qgsmapcanvas.h>
#include <qgis/qgsvectorlayer.h>

#include "Utils.hpp"

class WindowPrivate
{
public:
    Q_DECLARE_PUBLIC(Window)
    Window *q_ptr;
    QToolBar *mToolBar;
    QToolButton *mToolOpen;
    QWidget *mCentralWidget;
    QVBoxLayout *mLayout;
    QgsMapCanvas *mMapCanvas;
    QStatusBar *mStatusBar;
    QLabel *mCurrentPos;
    QList<QgsMapLayer *> mMapCanvasLayerSet;

    explicit WindowPrivate(Window *p);
    void loadVector();
};

WindowPrivate::WindowPrivate(Window *p) :
        q_ptr(p)
{
    Q_Q(Window);
    initWidget(mCentralWidget, q);
    initWidget(mToolBar, q);
    initWidget(mToolOpen, mToolBar);
    initWidget(mLayout, mCentralWidget);
    initWidget(mMapCanvas, mCentralWidget);
    initWidget(mStatusBar, q);
    initWidget(mCurrentPos, mStatusBar);
    mToolOpen->setIcon()
    q->addToolBar(mToolBar);
    q->setStatusBar(mStatusBar);
    q->setCentralWidget(mCentralWidget);
    mLayout->addWidget(mMapCanvas);
    mMapCanvas->enableAntiAliasing(true);
    mMapCanvas->setCanvasColor(QColor(255, 255, 255));
    mMapCanvas->setVisible(true);
    mStatusBar->addPermanentWidget(mCurrentPos);
}

void WindowPrivate::loadVector()
{
    Q_Q(Window);
    QString filename = QFileDialog::getOpenFileName(q, "open vector", "/home/jiang/map/vector",
                                                    "*.shp;;*.*");
    QStringList temp = filename.split(QDir::separator());
    QString basename = temp.last();
    auto vecLayer = new QgsVectorLayer(filename, basename, "ogr");// , false);
    if (!vecLayer->isValid()) {
        QMessageBox::critical(q, "error", "layer is invalid");
        return;
    }

    //QgsMapLayerRegistry::instance()->addMapLayer(vecLayer);
    mMapCanvasLayerSet.append(vecLayer);
    mMapCanvas->setExtent(vecLayer->extent());
    mMapCanvas->setLayers(mMapCanvasLayerSet);
    mMapCanvas->setVisible(true);
    mMapCanvas->freeze(false);
    mMapCanvas->refresh();
}

Window::Window(QWidget *parent) :
        QMainWindow(parent),
        d_ptr(new WindowPrivate(this))
{
    Q_D(Window);
    connect(d->mMapCanvas, &QgsMapCanvas::xyCoordinates, [this](const QgsPointXY &p) {
        d_ptr->mCurrentPos->setText(QString("x:%1, y:%2").arg(p.x()).arg(p.y()));
    });
    d->loadVector();
}

Window::~Window()
{

}