#ifndef KUGEL_H
#define KUGEL_H

#include <QWidget>
#include <QOpenGLWidget>

class Kugel
{
    public:
        Kugel();
        // Draw a sphere with center pos, radius rad and nr_lat/nr_lon segments
        void drawKugel(const QVector3D &pos, float rad = 1.f, int nr_lat = 90, int nr_lon = 90 );

};

#endif // KUGEL_H
