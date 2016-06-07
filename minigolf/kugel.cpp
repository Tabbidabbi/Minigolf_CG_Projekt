#include "kugel.h"
#include <stdlib.h>
#include <cmath>
#include <QDebug>

Kugel::Kugel(QWidget *parent)
    :QOpenGLWidget(parent){

}

Kugel::~Kugel()
{
}

void Kugel::initializeGL()
{
    initializeOpenGLFunctions();
    //Spezifiziert Clear-Farbenwerte(red, green, blue, alpha)
    glClearColor(0,0,0,1);
    //Tiefenvergleiche getätigt und der Tiefenpuffer aktualisiert
    //glEnable(GL_DEPTH_Test);
    //Setzt Licht0 auf freigegeben
    glEnable(GL_LIGHT0);
    //Aktivierung des Lichts
    glEnable(GL_LIGHTING);
    //Bestimmt, welche Materialeigenschaften sich auf die aktuelle Farbe auswirken
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    //Aktiviert Materialfarbe
    glEnable(GL_COLOR_MATERIAL);
}

void Kugel::paintGL( const QVector3D& pos, float rad,
                     int nr_lat, int nr_lon )
{
    // Angle delta in both directions
        const float lat_delta = M_PI / float( nr_lat );
        const float lon_delta = M_PI / float( nr_lon );

        // Create horizontal stripes of squares
        for( float lon = 0.0f; lon < 1.0f*M_PI; lon += lon_delta )
        {
            glBegin( GL_QUAD_STRIP ) ;
            for( float lat = 0.0f; lat <= 2.0f*M_PI; lat += lat_delta )
            {
                // Each iteration adds another square, the other vertices
                // are taken from the existing stripe
                float xn1 = cosf( lat ) * sinf( lon );
                float yn1 = sinf( lat ) * sinf( lon );
                float zn1 = cosf( lon );

                // Set normal vector (important for lighting!)
                glNormal3f( xn1, yn1, zn1 );
                glVertex3f( pos.x()+rad*xn1, pos.y()+rad*yn1, pos.z()+rad*zn1 );

                float xn2 = cosf( lat ) * sinf( lon + lon_delta );
                float yn2 = sinf( lat ) * sinf( lon + lon_delta );
                float zn2 = cosf( lon + lon_delta );

                glNormal3f( xn2, yn2, zn2 );
                glVertex3f( pos.x()+rad*xn2, pos.y()+rad*yn2, pos.z()+rad*zn2 );
            }
            glEnd() ;
        }
}

void Kugel::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}





