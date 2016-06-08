#include "kreis.h"
#include <math.h>

Kreis::Kreis()
{

}

void Kreis::drawKreis(int k, int r, int h) {
    //Zeichnet Dreiecke in den Kreis
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 180; i++)
    {
        x = r * cosf(i) - h;
        y = r * sinf(i) + k;
        glVertex3f(x + k,y - h,0);

        x = r * cosf(i + 0.1) - h;
        y = r * sinf(i + 0.1) + k;
        glVertex3f(x + k,y - h,0);
    }
    glEnd();
}



