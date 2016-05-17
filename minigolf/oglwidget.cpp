#include "oglwidget.h"

OGLWidget::OGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    parama = 0;
    paramb = 0;
    paramc = 0;
}

OGLWidget::~OGLWidget()
{
}


void OGLWidget::setParamA(int newa)
{
    parama = newa; // Set new value
    update();      // Trigger redraw of scene with paintGL
}

void OGLWidget::setParamB(int newb)
{
    paramb = newb;
    update();
}

void OGLWidget::setParamC(int newc)
{
    paramc = newc;
    update();
}


void OGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
//      GLfloat lp1[4]  = { 20,  0,  0, 0};
//      GLfloat lp2[4]  = { -20, 0 , 0,  0};
//      GLfloat red[4]  = {1.0, 0 , 0,  1};
//      GLfloat green[4] = { 0, 1.0, 0.0,  1};
//      GLfloat blue[4] = { 0, 0.0, 1.0,  1};
      glClearColor(0,0,0,1);
      glEnable(GL_DEPTH_TEST);
      glDepthFunc(GL_LESS);

      glShadeModel(GL_SMOOTH);
//      glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 1);
//      glEnable(GL_LIGHTING);

//      glLightfv(GL_LIGHT1, GL_POSITION, lp1);
//      glLightfv(GL_LIGHT1, GL_DIFFUSE,  red);
//      glLightfv(GL_LIGHT1, GL_SPECULAR, red);
//      glEnable(GL_LIGHT1);

//      glLightfv(GL_LIGHT2, GL_POSITION, lp2);
//      glLightfv(GL_LIGHT2, GL_DIFFUSE,  green);
//      glLightfv(GL_LIGHT2, GL_SPECULAR, green);
//      glEnable(GL_LIGHT2);

//    glClearColor(0,0,0,1);
//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_LIGHT0);
//    glEnable(GL_LIGHT1);
//    glEnable(GL_LIGHTING);
//    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
//    glEnable(GL_COLOR_MATERIAL);

}

void OGLWidget::paintGL()
{
    double c = parama; // change of color
    double r = paramb;   // degree to rotate
    double t = paramc;

    //Lädt Einheitsmatrix
    glLoadIdentity();
    //aktiviert einen orthogonalen 2D-Rendermodus
    glOrtho(-10, 10, -10, 10, -200, 200);


    //Legt die Hintergrundfarbe fest
    glClearColor(0.8, 0.8, 0.8, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


   // glPushMatrix, glPopMatrix - Legen die aktuelle Matrix auf den Stack bzw. nehmen sie wieder herunter.
  //  glPushMatrix();

    //Rotation mit einer Rotationsmatrix
    glRotatef(5*r, 0.0f, 1.0f, 0.0f); // Rotate by r degrees around z axis
    glRotatef(5*t, 0.0f, 0.0f, 1.0f); // Rotate by r degrees around z axis
    //Multipliziert die aktuelle Matrix mit einer Verschiebungsmatrix.
    glTranslatef(0,0,0);
    glScalef(5,5,5);
    //Bestimmt einen symbolischen Wert der eine Färbetechnik (Shadingtechnique) repräsentiert. Akzeptierte Werte sind GL_FLAT und GL_SMOOTH.
    glShadeModel(GL_FLAT);
//    glBegin(GL_TRIANGLE_FAN);
//        glColor3f(0.1, 0.5, 1.0);
//        glVertex3d(0,1,0);
//        glVertex3d(-1,-1,1);
//        glNormal3d(0,.5,.5);
//        glVertex3d(1,-1,1);
//        glNormal3d(0.5,.5,0);
//        glVertex3d(1,-1,-1);
//        glColor3f(1.0, 0.0, 1.0);
//        glNormal3d(0,0.5,-0.5);
//        glVertex3d(-1,-1,-1);
//        glColor3f(0.0, 0.0, 1.0);
//        glNormal3d(-0.5,0.5,0);
//        glVertex3d(-1,-1,1);
//    glEnd();
    //glPushMatrix();
//    glTranslatef(1,0,0);
//    glRotatef(5*c,1,0,0);




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

