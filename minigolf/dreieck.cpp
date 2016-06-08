#include "dreieck.h"

dreieck::dreieck(){

}

void dreieck::drawTriangle(int c, int r, int t)
{
    //double c = 0; // parama
    //double r = 0; // paramb
    //double t = 0; // paramc
    glLoadIdentity();
    glOrtho(-10, 10, -10, 10, -200, 200);

    glClearColor(0.8, 0.8, 0.8, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //  glPushMatrix();

    glRotatef(5*r, 0.0f, 1.0f, 0.0f); // Rotate by r degrees around z axis
    glRotatef(5*t, 0.0f, 0.0f, 1.0f); // Rotate by r degrees around z axis
    glTranslatef(0,0,0);
    glScalef(5,5,5);
    glShadeModel(GL_FLAT);
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.5, 0.5, 0.5);
        glVertex3d(0,1,0);
        glVertex3d(-1,-1,1);
        glNormal3d(0,.5,.5);
        glVertex3d(1,-1,1);
        glNormal3d(0.5,.5,0);
        glVertex3d(1,-1,-1);
        glColor3f(1.0, 0.0, 1.0);
        glNormal3d(0,0.5,-0.5);
        glVertex3d(-1,-1,-1);
        glColor3f(0.0, 0.0, 1.0);
        glNormal3d(-0.5,0.5,0);
        glVertex3d(-1,-1,1);
    glEnd();


    glTranslatef(0,-1,0);
    //glRotatef(5*c,1,0,0);
    glBegin(GL_QUADS);                              // Draw A Quad
        glVertex3f(-1.0f, 0.0f, 1.0f);              // Top Left
        glVertex3f( 1.0f, 0.0f, 1.0f);              // Top Right
        glVertex3f( 1.0f, 0.0f, -1.0f);             // Bottom Right
        glVertex3f(-1.0f, 0.0f, -1.0f);             // Bottom Left
    glEnd();
}
