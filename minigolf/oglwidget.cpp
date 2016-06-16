
#include "oglwidget.h"
#include "kugel.h"
#include <cmath>
#include <QDebug>
#include <iostream>


OGLWidget::OGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
   zoom  = 100;
   rotx  = 90;
   roty  = 180;
   rotz  = 0;
   transZ = -8;
   transX = -2;
}
OGLWidget::~OGLWidget()
{
}

void OGLWidget::setRotX(int newrx)
{
    rotx = newrx;
    update();
}
void OGLWidget::setTransZ(int newtz)
{
    transZ = newtz;
    update();
}
void OGLWidget::setTransX(int newtx)
{
    transX = newtx;
    update();
}

void OGLWidget::setRotY(int newry)
{
    roty = newry;
    update();
}

void OGLWidget::setRotZ(int newrz)
{
    rotz = newrz;
    update();
}


void OGLWidget::setZoom(int newzoom)
{
    zoom = newzoom;
    update();
}

void drawLine(){
    //X-Achse positiv

    glBegin(GL_LINES);
        glColor3f(1.0,0.0,0.0);
        glVertex3f(10.0, 2.0, 0.0);
         glVertex3f(0.0, 2.0, 0.0);
    glEnd();

    //X-Achse negativ
    glBegin(GL_LINES);
        glColor3f(1.0,0.5,0.0);
        glVertex3f(0.0, 2.0, 0.0);
        glVertex3f(-10.0, 2.0, 0.0);
    glEnd();



    //Y-Achse
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINES);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, -16.0, 0.0);
    glEnd();

    //Z-Achse positiv

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,1.0);
        glVertex3f(0.0, 2.0, 10);
        glVertex3f(0.0, 2.0, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.5,0.0,1.0);
     glVertex3f(0.0, 2.0, 0.0);
        glVertex3f(0.0, 2.0, -10);

    glEnd();
}
void OGLWidget::initializeGL()
{
    initializeOpenGLFunctions();

     
  
    // Use depth testing and the depth buffer
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    // Calculate color for each pixel fragment
    glShadeModel(GL_SMOOTH);

    // Enable lighting in scene
    //glEnable(GL_LIGHTING);

    // Set position of light source
    //float light_pos[] = { 10.f, 5.f, 10.f, 0.f };
    //glLightfv(GL_LIGHT1, GL_POSITION, light_pos );

    // Set color for this light source
    // (We are only specifying a diffuse light source)
    //float light_diffuse[] = { .8f, .8f, .8f, 1.f };
    //glLightfv(GL_LIGHT1, GL_DIFFUSE,  light_diffuse );

    // Turn on this light
    //glEnable(GL_LIGHT1);

    // Use the color of an object for light calculation
    //glColorMaterial( GL_FRONT_AND_BACK, //GL_AMBIENT_AND_DIFFUSE );
   // glEnable(GL_COLOR_MATERIAL);
    glClearColor(0,0,0,1);
 



}

void OGLWidget::paintGL()
{


    // Prepare projection matrix
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
     //aktiviert einen orthogonalen 2D-Rendermodus
                     // Parallel projection with
    glOrtho(-10, 10, // clipping planes: left,   right
            -10, 10, //                  bottom, top
            -10, 10);//                  near,   far

    // Prepare model matrix
    glMatrixMode(GL_MODELVIEW);
    //Lädt Einheitsmatrix
    glLoadIdentity();

    float scale = zoom/100.0;
    glScalef( scale, scale, scale ); // Scale along all axis

    //Farbbuffer und Tiefenpuffer entleeren
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //Legt die Hintergrundfarbe fest
    glClearColor(0.8, 0.8, 0.8, 1.0);

    // Change light position
    //float light_pos[] = { 10.f * cosf(light*M_PI/180.f),
                          // 5.f,
                          //10.f * sinf(light*M_PI/180.f), 0.f };
    //glLightfv(GL_LIGHT1, GL_POSITION,  light_pos);








      glRotatef(rotx, 1.0f, 0.0f, 0.0f); // Rotate around x axis
      glRotatef(roty, 0.0f, 1.0f, 0.0f); // Rotate around y axis
      glRotatef(rotz, 0.0f, 0.0f, 1.0f); // Rotate around z axis


      //Multipliziert die aktuelle Matrix mit einer Verschiebungsmatrix.
      glTranslatef(transX,0,transZ);

    //Bestimmt einen symbolischen Wert der eine Färbetechnik (Shadingtechnique) repräsentiert. Akzeptierte Werte sind GL_FLAT und GL_SMOOTH.
    glShadeModel(GL_FLAT);

    glPushMatrix();

    miniGolfTrack.drawTrack();
    glPopMatrix();
    glPushMatrix();
    drawLine();
    glPopMatrix();




    glColor3f(0.0, 0.0, 0.0);

    kugel.drawKugel(QVector3D( 2, 0, 1), 0.2);








  }

void OGLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void OGLWidget::mousePressEvent(QMouseEvent *event)
{
    // Upon mouse pressed, we store the current position...
    lastpos = event->pos();
}

void OGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    // ... and while moving, we calculate the dragging deltas
    // Left button: Rotating around x and y axis
    int dz = (event->buttons() & Qt::LeftButton && event->buttons() & Qt::RightButton) ? lastpos.y() - event->y() : transZ;
    int dx = (event->buttons() & Qt::LeftButton && event->buttons() & Qt::RightButton) ? lastpos.x() - event->x() : transX;
    //int dy = lastpos.x() - event->x();

    // Right button: Rotating around z and y axis
    //int dz = (event->buttons() & Qt::RightButton) ? lastpos.x() - event->x() : rotz;

    // Now let the world know that we want to rotate
   // setRotX(dx);
    //setRotY(dy);
    //setRotZ(dz);
   setTransZ((dz/10));
   setTransX((dx/10));

   // emit changeRotation( dx, dy, dz );

    // Make the current position the starting point for the next dragging step

}



