#include "kugel.h"
#include <math.h>
#include <QVector3D>

Kugel::Kugel()
{

}

void Kugel::drawKugel( const QVector3D& pos, float rad, int nr_lat, int nr_lon )
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
