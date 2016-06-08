#ifndef DREIECK_H
#define DREIECK_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include "oglwidget.h"

class dreieck
{
public:
    dreieck();
    void drawTriangle(int c, int r, int t);

};

#endif // DREIECK_H
