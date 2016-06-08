#include "kreis.h"
#include <math.h>

Kreis::Kreis()
{

}

void Kreis::drawKreis(float cx, float cy, float radius, int numberOfSegments)
{
    glRotatef(90.0, 1, 0, 0 );
    glBegin( GL_TRIANGLES );
        for(int i = 0; i < numberOfSegments; i++) {
            //get the current angle
            float theta = 2.0f * M_PI * float(i) / float(numberOfSegments);
            //calculate the x component
            float x = radius * cosf(theta);
            //calculate the y component
            float y = radius * sinf(theta);
            //output vertex
            glVertex2f(x + cx, y + cy);
        }
    glEnd();
}


void Kreis::createcircle (int k, int r, int h) {
  glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 180; i++)
    {
    x = r * cosf(i) - h;
    y = r * sinf(i) + k;
    glVertex3f(x + k,y - h,0);

    x = r * cosf(i + 0.1) - h;
    y = r * sinf(i + 0.1) + k;
    glVertex3f(x + k,y - h,0);
    }
    glEnd();
}



