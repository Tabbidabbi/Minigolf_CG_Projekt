#include "kreis.h"
#include <math.h>

Kreis::Kreis()
{

}

void Kreis::drawCircle(float red, float yellow, float blue, float degree,float radius) {

    //Legen die aktuelle Matrix auf den Stack bzw. nehmen sie wieder herunter
    glPushMatrix();
    for (int i = 0; i < degree; i++) {
        dreieck.drawDynamicTriangle(red,yellow,blue,radius);
        glRotatef(1.0, 0.0f, 1.0f, 0.0f);
    }
    //Legen die aktuelle Matrix auf den Stack bzw. nehmen sie wieder herunter
    glPopMatrix();
}

void Kreis::drawZylinder(float red, float yellow, float blue, float degree, float radius,float height) {

    for (int i = 0; i < degree; i++) {
        dreieck.drawDynamicTriangle(red,yellow,blue,radius);
        //Multipliziert die aktuelle Matrix mit einer Rotationsmatrix
        glRotatef(1.0, 0.0f, 1.0f, 0.0f);
        glTranslatef(0.0,0.0,radius);
        //Zeichnet Vierecke als Außenwand des Zylinders
        glBegin(GL_QUADS);
            //Setzt Farbwerte
            glColor3f(red,yellow,blue);
            //Bestimmt die Koordinaten eines Vertex. Ein Vertex (Mehrzahl: Vertice(s)) ist ein Punkt im Raum
            glVertex3d(0,0,0);
            //Bestimmt die Koordinaten eines Vertex. Ein Vertex (Mehrzahl: Vertice(s)) ist ein Punkt im Raum
            glVertex3d(0,height,0);
            //Bestimmt die Koordinaten eines Vertex. Ein Vertex (Mehrzahl: Vertice(s)) ist ein Punkt im Raum
            glVertex3d(0.1,height,0);
            //Bestimmt die Koordinaten eines Vertex. Ein Vertex (Mehrzahl: Vertice(s)) ist ein Punkt im Raum
            glVertex3d(0.1,0,0);
        glEnd();
        //Multipliziert die aktuelle Matrix mit einer Verschiebungsmatrix
        glTranslatef(0.0,0.0,-radius);
        //Multipliziert die aktuelle Matrix mit einer Verschiebungsmatrix
        glTranslatef(0.0,1.0,0.0);
        dreieck.drawDynamicTriangle(red,yellow,blue,radius);
        //Multipliziert die aktuelle Matrix mit einer Verschiebungsmatrix
        glTranslatef(0.0,-1.0,0.0);
    }
}
