#ifndef ZYLINDER_H
#define ZYLINDER_H
#include <kreis.h>


class Zylinder
{
    public:
        Zylinder();
        Kreis kreis;
        void drawZylinder(float red, float yellow, float blue, float degree,float radius);
};

#endif // ZYLINDER_H
