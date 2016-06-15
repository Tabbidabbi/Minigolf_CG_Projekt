#ifndef KREIS_H
#define KREIS_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <dreieck.h>


class Kreis
{
    public:
        float x,y,rot;

        Kreis();
        Dreieck dreieck;
        void drawCircle(float red, float yellow, float blue,float degree,float radius);
};

#endif // KREIS_H
