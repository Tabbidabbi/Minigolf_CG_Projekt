#include "viereck.h"

Viereck::Viereck()
{
}


   void Viereck::drawQuad(float size, float dx, float dy, float dz, float red, float green, float blue){

       glBegin(GL_QUADS);

           glColor3f(red, green, blue);
           glVertex3d(dx, dy, dz);
           glVertex3d(dx, dy*size, dz);
           glVertex3d(dx*size, dy*size, dz);
           glVertex3d(dx*size, dy, dz);


           glEnd();


    }




