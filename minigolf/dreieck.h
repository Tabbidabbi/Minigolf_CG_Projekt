#ifndef DREIECK_H
#define DREIECK_H

#include <QWidget>
#include <QOpenGLWidget>
#include "math.h"

class Dreieck
{
    public:
        //Konstruktor
        Dreieck();

        //Zeichnet dynamisches Dreieck
        void drawDynamicTriangle(float red, float yellow, float blue,float radius);
        //Zeichnet Pyramide
        void drawPyramid(float size);
        //Zeichnet gleichseitiges Dreieck
        void drawEquilateralTriangle(float red, float yellow, float blue,float size);
};

#endif // DREIECK_H
