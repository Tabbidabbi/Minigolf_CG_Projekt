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

void Kreis::drawCircle(float red, float yellow, float blue,double radius) {


    float adjacentSide = cosf(M_PI/180);
    float oppositeSide = sinf(M_PI/180);


    glBegin(GL_TRIANGLES);
    glColor3f(red,yellow,blue);
    glVertex3d(0,0,0);
    glVertex3d(0,1*radius,0);

    glVertex3d(oppositeSide*5,adjacentSide,0);
    glEnd();








}



