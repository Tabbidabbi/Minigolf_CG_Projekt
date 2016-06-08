#include "minigolftrack.h"


minigolfTrack::minigolfTrack()
{

}

void minigolfTrack::drawTrack() {


        viereck.drawQuad(2,0,1,0);
        glTranslatef(0,0,2);
        viereck.drawQuad(2,1,1,0);
        glTranslatef(0,0,2);
          viereck.drawQuad(2,1,1,1);
         glTranslatef(0,0,2);
        viereck.drawQuad(2,0,0,0);
        glTranslatef(2,0,0);
        viereck.drawQuad(2,0,1,0);
        glTranslatef(2,0,0);
         viereck.drawQuad(2,0,1,0);
//        glBegin(GL_QUADS);

//            glColor3f(red, green, blue);
//            glVertex3d(0, 0, 0);
//            glVertex3d(0, 0, 1*size);
//            glVertex3d(1*size, 0, 1*size);
//            glVertex3d(1*size, 0, 0);


//            glEnd();


}
