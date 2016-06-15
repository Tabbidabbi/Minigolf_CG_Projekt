#ifndef MINIGOLFTRACK_H
#define MINIGOLFTRACK_H

#include <viereck.h>
#include <kreis.h>
#include <dreieck.h>
#include <QWidget>
#include <QOpenGLWidget>



class minigolfTrack
{
public:
    minigolfTrack();
    void drawTrack();

protected:
    Viereck viereck;
    Kreis kreis;
    Dreieck dreieck;

};

#endif // MINIGOLFTRACK_H
