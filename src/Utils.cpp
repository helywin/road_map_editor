//
// Created by jiang on 2021/5/11.
//

#include "Utils.hpp"
#include <QWidget>
#include <QPainter>
#include <QStyleOption>

void drawPrimitive(QWidget *w)
{
    QStyleOption opt;
    opt.initFrom(w);
    QPainter p(w);
    w->style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, w);
}