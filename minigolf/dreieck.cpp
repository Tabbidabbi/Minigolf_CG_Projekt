#include "dreieck.h"

Dreieck::Dreieck()
{
}

void Dreieck::drawRectangle(float red, float yellow, float blue,float radius) {


    float adjacentSide = cosf(M_PI/180);
    float oppositeSide = sinf(M_PI/180);


    glBegin(GL_TRIANGLES);
    glColor3f(red,yellow,blue);
    glVertex3d(0,0,0);
    glVertex3d(0,0,radius);

    glVertex3d(adjacentSide*radius,0, oppositeSide);
    glEnd();








}



