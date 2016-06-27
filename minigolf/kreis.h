#ifndef KREIS_H
#define KREIS_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <dreieck.h>

class Kreis
{
    public:
        // Öffentliche Variablen
        float x, y, rot;

        //Konstruktor
        Kreis();
        //Deklaration Dreieck-Objekt
        Dreieck dreieck;

        //Zeichnet Kreis
        void drawCircle(float red, float yellow, float blue,float degree,float radius);
        //Zeichnet Zylinder
        void drawZylinder(float red, float yellow, float blue,float degree,float radius,float height);
};

#endif // KREIS_H
