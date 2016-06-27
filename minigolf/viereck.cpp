#include "viereck.h"

Viereck::Viereck()
{
}

void Viereck::drawGround( float red, float green, float blue){

    //Zeichnet Viereck
   glBegin(GL_QUADS);
       glColor3f(red, green, blue);
       glVertex3d(0, 0, 0);
       glVertex3d(0, 0, 4);
       glVertex3d(4, 0, 4);
       glVertex3d(4, 0, 0);
   glEnd();
}

void Viereck::drawRightWall(float red, float green, float blue) {

    //Zeichnet Viereck
    glBegin(GL_QUADS);
       glColor3f(red, green, blue);
       glVertex3d(0, 0, 0);
       glVertex3d(0, 1, 0);
       glVertex3d(0, 1, 4);
       glVertex3d(0, 0, 4);
    glEnd();

    //Zeichnet Viereck
    glBegin(GL_QUADS);

    //Zeichnet Viereck
    glBegin(GL_QUADS);
        glColor3f(red, green, blue);
        glVertex3d(0, 1, 0);
        glVertex3d(0, 1, 4);
        glVertex3d(-0.2, 1, 4);
        glVertex3d(-0.2, 1, 0);
    glEnd();
}

void Viereck::drawSouthWall(float red, float green, float blue) {

    //Zeichnet Viereck
    glBegin(GL_QUADS);
        glColor3f(red, green, blue);
        glVertex3d(0, 0, 0);
        glVertex3d(0, 1, 0);
        glVertex3d(4, 1, 0);
        glVertex3d(4, 0, 0);
    glEnd();

    //Zeichnet Viereck
    glBegin(GL_QUADS);

    //Zeichnet Viereck
    glBegin(GL_QUADS);
        glColor3f(red, green, blue);
        glVertex3d(0, 1, 0);
        glVertex3d(4, 1, 0);
        glVertex3d(4, 1, -0.2);
        glVertex3d(0, 1, -0.2);
    glEnd();
}

void Viereck::drawLeftWall(float red, float green, float blue) {

    //Zeichnet Viereck
    glBegin(GL_QUADS);
        glColor3f(red, green, blue);
        glVertex3d(4, 0, 0);
        glVertex3d(4, 1, 0);
        glVertex3d(4, 1, 4);
        glVertex3d(4, 0, 4);
    glEnd();

    //Zeichnet Viereck
    glBegin(GL_QUADS);

    //Zeichnet Viereck
    glBegin(GL_QUADS);
        glColor3f(red, green, blue);
        glVertex3d(4, 1, 0);
        glVertex3d(4, 1, 4);
        glVertex3d(4.2, 1, 4);
        glVertex3d(4.2, 1, 0);
    glEnd();
}

void Viereck::drawNorthWall(float red, float green, float blue) {

    //Zeichnet Viereck
    glBegin(GL_QUADS);
        glColor3f(red, green, blue);
        glVertex3d(0, 0, 4);
        glVertex3d(0, 1, 4);
        glVertex3d(4, 1, 4);
        glVertex3d(4, 0, 4);
    glEnd();

    //Zeichnet Viereck
    glBegin(GL_QUADS);

    //Zeichnet Viereck
    glBegin(GL_QUADS);
        glColor3f(red, green, blue);
        glVertex3d(0, 1, 4);
        glVertex3d(4, 1, 4);
        glVertex3d(4, 1, 4.2);
        glVertex3d(0, 1, 4.2);
    glEnd();
}
