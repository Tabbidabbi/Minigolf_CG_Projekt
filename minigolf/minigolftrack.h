#ifndef MINIGOLFTRACK_H
#define MINIGOLFTRACK_H

#include <viereck.h>
#include <kreis.h>
#include <dreieck.h>
#include <QWidget>
#include <QOpenGLWidget>

class minigolfTrack{
    public:
        //Konstruktor
        minigolfTrack();

        //Zeichnet die Minigolfbahn
        void drawTrack();

    protected:
        //Deklariert Viereck-Objekt
        Viereck viereck;
        //Deklariert Kreis-Objekt
        Kreis kreis;
        //Deklariert Dreieck-Objekt
        Dreieck dreieck;
};

#endif // MINIGOLFTRACK_H
