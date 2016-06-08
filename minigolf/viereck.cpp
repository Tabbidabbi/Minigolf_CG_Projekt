#include "viereck.h"

Viereck::Viereck()
{
}


   void Viereck::drawQuad(float size, float red, float green, float blue){

       glBegin(GL_QUADS);

           glColor3f(red, green, blue);
           glVertex3d(0, 0, 0);
           glVertex3d(0, 0, 1*size);
           glVertex3d(2*size, 0, 1*size);
           glVertex3d(2*size, 0, 0);


           glEnd();


    }




