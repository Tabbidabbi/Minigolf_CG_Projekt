#include "minigolftrack.h"


minigolfTrack::minigolfTrack()
{

}

void minigolfTrack::drawTrack() {

    viereck.drawGround(0.3,1,0.5);
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
    //Zeichnet Pyramide
    dreieck.drawPyramid(2);
    glPopMatrix();

    //Zeichnet rechte Wand
    viereck.drawRightWall(1,1,1);
    //Zeichnet Südwand
    viereck.drawSouthWall(1,1,1);
    //Zeichnet linke Wand
    viereck.drawLeftWall(1,1,1);

    glTranslatef(0,0,4);

    //Zeichnet Grund
    viereck.drawGround(0.3,1,0.5);
    //Zeichent rechte Wand
    viereck.drawRightWall(1,1,1);
    //Zeichnt linke Wand
    viereck.drawLeftWall(1,1,1);

    glTranslatef(0,0,4);

    //Zeichnet Grund
    viereck.drawGround(0.3,1,0.5);
    //Zeichent rechte Wand
    viereck.drawRightWall(1,1,1);
    //Zeichnt linke Wand
    viereck.drawLeftWall(1,1,1);

    glTranslatef(0,0,4);

    viereck.drawGround(0.3,1,0.5);
    //Zeichent rechte Wand
    viereck.drawRightWall(1,1,1);
    //Zeichnt linke Wand
    viereck.drawNorthWall(1,1,1);

    glTranslatef(4,0,0);

    //Zeichnet Grund
    viereck.drawGround(0.3,1,0.5);
    //Zeichnet Nordwand
    viereck.drawNorthWall(1,1,1);
    //Zeichnet Südwand
    viereck.drawSouthWall(1,1,1);

    glTranslatef(4,0,0);

    //Zeichnet den Grund der Bahn
    viereck.drawGround(0.3,1,0.5);
    glPushMatrix();
    glTranslatef(3,0.1,2);
    //Zeichnet Loch der Bahn
    kreis.drawCircle(0.7,0.4,0.3,360,0.35);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-1,0.1,3);
    //Zeichnet Zylinder
    kreis.drawZylinder(0.5,0.7,0.8,360,0.6,1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-1,0.1,1);
    //Zeichnet Zylinder
    kreis.drawZylinder(0.3,0.4,0.6,360,0.6,1);
    glPopMatrix();
    //Zeichnet Nordwand
    viereck.drawNorthWall(1,1,1);
    //Zeichnet Südwand
    viereck.drawSouthWall(1,1,1);
    //Zeichnt linke Wand
    viereck.drawLeftWall(1,1,1);
}
