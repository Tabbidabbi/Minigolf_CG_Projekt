#ifndef VIERECK_H
#define VIERECK_H

#include <QWidget>
#include <QOpenGLWidget>

class Viereck
{
public:
    Viereck();
    void drawGround(float red, float green, float blue);
    void drawRightWall(float red, float green, float blue);
    void drawLeftWall(float red, float green, float blue);
    void drawSouthWall(float red, float green, float blue);
    void drawNorthWall(float red, float green, float blue);

};

#endif // VIERECK_H
