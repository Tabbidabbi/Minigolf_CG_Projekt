#include "oglwidget.h"


OGLWidget::OGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
   zoom  = 100;
}
OGLWidget::~OGLWidget()
{
}




void OGLWidget::setZoom(int newzoom)
{
    zoom = newzoom;
    update();
}





void OGLWidget::initializeGL()
{
    initializeOpenGLFunctions();

      glClearColor(0,0,0,1);
      glEnable(GL_DEPTH_TEST);
      glDepthFunc(GL_LESS);

      glShadeModel(GL_SMOOTH);


}

void OGLWidget::paintGL()
{

    // Prepare projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
                     // Parallel projection with
    glOrtho(-10, 10, // clipping planes: left,   right
            -10, 10, //                  bottom, top
            -10, 10);//                  near,   far

    // Prepare model matrix
    glMatrixMode(GL_MODELVIEW);
    //Lädt Einheitsmatrix
    glLoadIdentity();
    //aktiviert einen orthogonalen 2D-Rendermodus
    float scale = zoom/100.0;
    glScalef( scale, scale, scale ); // Scale along all axis




    //Farbbuffer und Tiefenpuffer entleeren
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //Legt die Hintergrundfarbe fest
    glClearColor(0.8, 0.8, 0.8, 1.0);


   // glPushMatrix, glPopMatrix - Legen die aktuelle Matrix auf den Stack bzw. nehmen sie wieder herunter.
  //  glPushMatrix();

    glRotatef(90, 1, 0, 0);
    //Multipliziert die aktuelle Matrix mit einer Verschiebungsmatrix.
    glTranslatef(0,0,0);
    //Bestimmt einen symbolischen Wert der eine Färbetechnik (Shadingtechnique) repräsentiert. Akzeptierte Werte sind GL_FLAT und GL_SMOOTH.
    glShadeModel(GL_FLAT);

    miniGolfTrack.drawTrack();

    //glPushMatrix();





    //glPopMatrix();
  //  glPopMatrix();
  }

void OGLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

