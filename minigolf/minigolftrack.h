#ifndef MINIGOLFTRACK_H
#define MINIGOLFTRACK_H

#include <viereck.h>
#include <QWidget>
#include <QOpenGLWidget>



class minigolfTrack
{
public:
    minigolfTrack();
    void drawTrack();

protected:
    Viereck viereck;

};

#endif // MINIGOLFTRACK_H
