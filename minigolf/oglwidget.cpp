﻿
#include "oglwidget.h"
#include "kugel.h"
#include <cmath>
#include <QDebug>
#include <iostream>
using namespace std;






OGLWidget::OGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{

   zoom  = 50;
   rotx  = 90;
   roty  = 180;
   rotz  = 0;

   speed = 0.0;
   sphereCoordZ = -7.0;
   sphereCoordX = -2.0;


   transZ = 0;
   transX = 0;
   xCoordinate;
   zCoordinate;
   orthoX = 20;
   orthoZ = 20;
   orthoY = 20;



    QTimer *aTimer = new QTimer;
    connect(aTimer,SIGNAL(timeout(QPrivateSignal)),SLOT(animateSphere()));
    //aTimer->start(1);
    power = 0;


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

void OGLWidget::setPower(int newpower)
{
    power = newpower;
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
        glVertex3f(20.0, 0.0, 0.0);
         glVertex3f(0.0, 0.0, 0.0);
    glEnd();

    //X-Achse negativ
    glBegin(GL_LINES);
        glColor3f(1.0,0.5,0.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(-20.0, 0.0, 0.0);
    glEnd();



    //Y-Achse
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINES);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, -20.0, 0.0);
    glEnd();
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINES);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 20.0, 0.0);
    glEnd();

    //Z-Achse positiv

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,1.0);
        glVertex3f(0.0, 0.0, 20);
        glVertex3f(0.0, 0.0, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.5,0.0,1.0);
     glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 0.0, -20);

    glEnd();
}
void OGLWidget::initializeGL()
{
    initializeOpenGLFunctions();

    //Aktiviert Keyboard-Eingabe
    setFocusPolicy(Qt::StrongFocus);

    // Use depth testing and the depth buffer
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    //Legt die Breit für GL_Lines fest
    glLineWidth(5.0);
    // Calculate color for each pixel fragment
    glShadeModel(GL_SMOOTH);
    glClearColor(0,0,0,1);

 



}

void OGLWidget::paintGL()
{




    // Prepare projection matrix
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
     //aktiviert einen orthogonalen 2D-Rendermodus
                     // Parallel projection with
    glOrtho(-orthoX, orthoX, // clipping planes: left,   right
            -orthoZ, orthoZ, //                  bottom, top
            -orthoY, orthoY);//                  near,   far

    // Prepare model matrix
    glMatrixMode(GL_MODELVIEW);
    //Lädt Einheitsmatrix
    glLoadIdentity();

    float scale = zoom/100.0;
    glScalef( 2, 2, 2 ); // Scale along all axis

    //Farbbuffer und Tiefenpuffer entleeren
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //Legt die Hintergrundfarbe fest
    glClearColor(0.8, 0.8, 0.8, 1.0);


      glRotatef(rotx, 1.0f, 0.0f, 0.0f); // Rotate around x axis
      glRotatef(roty, 0.0f, 1.0f, 0.0f); // Rotate around y axis
      glRotatef(rotz, 0.0f, 0.0f, 1.0f); // Rotate around z axis


      //Multipliziert die aktuelle Matrix mit einer Verschiebungsmatrix.
      glTranslatef((transX),0,(transZ));

    //Bestimmt einen symbolischen Wert der eine Färbetechnik (Shadingtechnique) repräsentiert. Akzeptierte Werte sind GL_FLAT und GL_SMOOTH.
    glShadeModel(GL_FLAT);

    glPushMatrix();
    glTranslated(-4,0,-8);
    miniGolfTrack.drawTrack();
    glPopMatrix();
    glPushMatrix();
    drawLine();
    glPopMatrix();


    glColor3f(0.0, 0.0, 0.0);
    kugel.drawKugel(QVector3D( sphereCoordX, 0, sphereCoordZ), 0.2);

    if(speed > 0  ){
        animateSphere();
}
  }

void OGLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void OGLWidget::setLocalCoordninates(QMouseEvent *event){

    xCoordinate = 0;
    zCoordinate = 0;

lastpos = event->pos();
mouseXPos = ((float)lastpos.x()/this->width());
mouseZPos = ((float)lastpos.y()/this->height());

 if (mouseXPos >= 0.5) {
   xCoordinate = (-((0.5 - (1-mouseXPos))*(orthoX)) - (transX) ) ;
 } else {
     qDebug() << transX << mouseXPos;
    xCoordinate = (-((0.5 -mouseXPos) * ((-orthoX)) - (-transX))) ;
}

 if (mouseZPos >= 0.5) {
   zCoordinate = (-((0.5 - (1-mouseZPos))*(orthoZ)) - (transZ));
 } else {
   zCoordinate  = (-((0.5 -mouseZPos) * ((-orthoZ)) - (-transZ))) ;
}



qDebug() << "Maus Position: "  << "X ->" << xCoordinate  << "Verschiebung: " << transX ;
qDebug() << "Maus Position: " <<  "Z ->" << zCoordinate << "Verschiebung: " << transZ ;

}

void OGLWidget::shootSphere() {

    if(xCoordinate >= (sphereCoordX - 0.2) && xCoordinate <= (sphereCoordX + 0.2) ) {
        if(zCoordinate >= (sphereCoordZ - 0.2) && zCoordinate <= (sphereCoordZ + 0.2) ) {
            speed = power;

        }
    }


}

void OGLWidget::mousePressEvent(QMouseEvent *event)
{


    // Upon mouse pressed, we store the current position...
    if(event->buttons() == Qt::LeftButton) {

        setLocalCoordninates(event);


    }


    shootSphere();


    update();


}

void OGLWidget::mouseMoveEvent(QMouseEvent *event)

{

    int dx;
    int dy;

    // ... and while moving, we calculate the dragging deltas
    // Left button: Rotating around x and y axis

    if (event->buttons() == Qt::RightButton) {

          dx = lastpos.y() + event->y();
          dy = lastpos.x() + event->x();
    } else if(event->buttons() == Qt::LeftButton) {

        dx = 90;
        dy = 180;

    }
    // Now let the world know that we want to rotate
     setRotX(dx);
    setRotY(dy);

}


void OGLWidget::animateSphere()
{

    sphereCoordZ = sphereCoordZ+(speed/500);
    speed--;
     //coordX = coordX+(speed/500);
    update();
}


void OGLWidget::keyPressEvent(QKeyEvent *event) {


    switch (event->key()) {

        case Qt::Key_Up:
            transZ --;
            update();

        break;
        case Qt::Key_Down:
            transZ ++;
            update();
        break;
        case Qt::Key_Left:
            transX --;
            update();
        break;
        case Qt::Key_Right:
            transX ++;
            update();
        break;


    }



}


