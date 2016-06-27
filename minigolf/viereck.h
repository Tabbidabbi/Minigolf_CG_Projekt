#ifndef VIERECK_H
#define VIERECK_H

#include <QWidget>
#include <QOpenGLWidget>

class Viereck
{
    public:
        //Konstruktor
        Viereck();

        //Zeichent Grund
        void drawGround(float red, float green, float blue);
        //Zeichnet rechte Wand
        void drawRightWall(float red, float green, float blue);
        //Zeichnet linke Wand
        void drawLeftWall(float red, float green, float blue);
        //Zeichnet untere Wand/ Südwand
        void drawSouthWall(float red, float green, float blue);
        //Zeichnet obere Wand/ Nordwand
        void drawNorthWall(float red, float green, float blue);
};

#endif // VIERECK_H
