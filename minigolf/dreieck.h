#ifndef DREIECK_H
#define DREIECK_H


#include <QWidget>
#include <QOpenGLWidget>
#include "math.h"

class Dreieck
{


public:
    Dreieck();

    void drawDynamicTriangle(float red, float yellow, float blue,float radius);
    void drawPyramid(float size);
    void drawEquilateralTriangle(float red, float yellow, float blue,float size);




};

#endif // DREIECK_H
