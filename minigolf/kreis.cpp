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



