#include "dreieck.h"

Dreieck::Dreieck()
{
}

void Dreieck::drawDynamicTriangle(float red, float yellow, float blue,float radius) {


    float adjacentSide = cosf(M_PI/180);
    float oppositeSide = sinf(M_PI/180);


    glBegin(GL_TRIANGLES);
    glColor3f(red,yellow,blue);
    glVertex3d(0,0,0);
    glVertex3d(0,0,radius);

    glVertex3d(adjacentSide*radius,0, oppositeSide);
    glEnd();








}

void Dreieck::drawEquilateralTriangle(float red, float yellow, float blue,float size){

    glPushMatrix();
    glRotatef(-60,1,0,0);
    glBegin(GL_TRIANGLES);

    glColor3f(red,yellow,blue);
    glVertex3d(0,0,0);
    glVertex3d((size/2),0,size);
    glVertex3d(size,0,0);
    glEnd();
    glPopMatrix();
}

void Dreieck::drawPyramid(float size) {



    drawEquilateralTriangle(0.5,0.5,0.5,size);

    glRotatef(90, 0, 1, 0);
    glTranslatef(-size,0,0);
    drawEquilateralTriangle(0.5,0.5,0.7,size);


    glRotatef(90, 0, 1, 0);
    glTranslatef(-size,0,0);
    drawEquilateralTriangle(0.5,0.7,0.7,size);

    glRotatef(90, 0, 1, 0);
    glTranslatef(-size,0,0);
    drawEquilateralTriangle(1,1,1,size);






}



