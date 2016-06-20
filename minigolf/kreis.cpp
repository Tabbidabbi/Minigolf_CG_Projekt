#include "kreis.h"
#include <math.h>

Kreis::Kreis()
{

}


void Kreis::drawCircle(float red, float yellow, float blue, float degree,float radius) {


    glPushMatrix();
    for (int i = 0; i < degree; i++) {
    dreieck.drawDynamicTriangle(red,yellow,blue,radius);
    glRotatef(1.0, 0.0f, 1.0f, 0.0f);
    }
    glPopMatrix();


}

void Kreis::drawZylinder(float red, float yellow, float blue, float degree, float radius,float height) {



    for (int i = 0; i < degree; i++) {
    dreieck.drawDynamicTriangle(red,yellow,blue,radius);
    glRotatef(1.0, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0,0.0,radius);
    glBegin(GL_QUADS);
    glColor3f(red,yellow,blue);
    glVertex3d(0,0,0);

    glVertex3d(0,height,0);
    glVertex3d(0.1,height,0);
    glVertex3d(0.1,0,0);

    glEnd();
     glTranslatef(0.0,0.0,-radius);
     glTranslatef(0.0,1.0,0.0);
     dreieck.drawDynamicTriangle(red,yellow,blue,radius);
      glTranslatef(0.0,-1.0,0.0);


    }



}




