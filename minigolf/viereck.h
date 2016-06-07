#ifndef VIERECK_H
#define VIERECK_H

#include <QWidget>
#include <QOpenGLWidget>

class Viereck
{
public:
    Viereck();
    void drawQuad(float size,float dx, float dy, float dz, float red, float green, float blue);

};

#endif // VIERECK_H
