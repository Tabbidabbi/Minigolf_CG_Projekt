#ifndef KREIS_H
#define KREIS_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>


class Kreis
{
    public:
        float x,y,rot;

        Kreis();
        void drawKreis(int k, int r, int h);
};

#endif // KREIS_H
