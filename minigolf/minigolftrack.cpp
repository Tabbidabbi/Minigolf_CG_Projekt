#include "minigolftrack.h"


minigolfTrack::minigolfTrack()
{

}

void minigolfTrack::drawTrack() {


        viereck.drawGround(0,102,0);
        viereck.drawRightWall(1,1,1);
        viereck.drawSouthWall(1,1,1);
        viereck.drawLeftWall(1,1,1);

        glTranslatef(0,0,4);
        viereck.drawGround(0,102,0);
        viereck.drawRightWall(1,1,1);
        viereck.drawLeftWall(1,1,1);
        glTranslatef(0,0,4);
          viereck.drawGround(0,102,0);
           glTranslatef(0,0,4);
           viereck.drawGround(0,102,0);
           glTranslatef(4,0,0);
           viereck.drawGround(0,102,0);




}
