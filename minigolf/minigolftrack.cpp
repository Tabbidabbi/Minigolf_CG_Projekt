#include "minigolftrack.h"


minigolfTrack::minigolfTrack()
{

}

void minigolfTrack::drawTrack() {


        viereck.drawGround(0,102,0);
        glPushMatrix();
        glTranslatef(2,0.1,1);
         glBegin(GL_LINES);

             glColor3f(1.0,1.0,1.0);
             glVertex3f(2.0, 0.0, 0.0);
             glVertex3f(-2.0, 0.0, 0.0);

         glEnd();

         glPopMatrix();

         glPushMatrix();
         glTranslatef(1,0.1,8);
         dreieck.drawPyramid(2);
         glPopMatrix();

        viereck.drawRightWall(1,1,1);
        viereck.drawSouthWall(1,1,1);
        viereck.drawLeftWall(1,1,1);

        glTranslatef(0,0,4);

        viereck.drawGround(0,102,0);
        viereck.drawRightWall(1,1,1);
        viereck.drawLeftWall(1,1,1);

        glTranslatef(0,0,4);

        viereck.drawGround(0,102,0);
        viereck.drawRightWall(1,1,1);
        viereck.drawLeftWall(1,1,1);

        glTranslatef(0,0,4);

        viereck.drawGround(0,102,0);
        viereck.drawRightWall(1,1,1);
        viereck.drawNorthWall(1,1,1);

        glTranslatef(4,0,0);

        viereck.drawGround(0,102,0);
        viereck.drawNorthWall(1,1,1);
        viereck.drawSouthWall(1,1,1);

          glTranslatef(4,0,0);

        viereck.drawGround(0,102,0);
        glPushMatrix();
        glTranslatef(3,0.1,2);
        kreis.drawCircle(0.7,0.4,0.3,360,0.35);
        glPopMatrix();
        viereck.drawNorthWall(1,1,1);
        viereck.drawSouthWall(1,1,1);
        viereck.drawLeftWall(1,1,1);





}
