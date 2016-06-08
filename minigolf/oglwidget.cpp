#include "oglwidget.h"
#include "dreieck.h"
#include "dreieck.cpp"

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
      GLfloat lp1[4]  = { 20,  0,  0, 0};
      GLfloat lp2[4]  = { -20, 0 , 0,  0};
      GLfloat red[4]  = {1.0, 0 , 0,  1};
      GLfloat green[4] = { 0, 1.0, 0.0,  1};
      GLfloat blue[4] = { 0, 0.0, 1.0,  1};
      glClearColor(0,0,0,1);
      glEnable(GL_DEPTH_TEST);
      glDepthFunc(GL_LESS);

      glShadeModel(GL_SMOOTH);
      glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 1);
      glEnable(GL_LIGHTING);

      glLightfv(GL_LIGHT1, GL_POSITION, lp1);
      glLightfv(GL_LIGHT1, GL_DIFFUSE,  red);
      glLightfv(GL_LIGHT1, GL_SPECULAR, red);
      glEnable(GL_LIGHT1);

      glLightfv(GL_LIGHT2, GL_POSITION, lp2);
      glLightfv(GL_LIGHT2, GL_DIFFUSE,  green);
      glLightfv(GL_LIGHT2, GL_SPECULAR, green);
      glEnable(GL_LIGHT2);
}

void OGLWidget::paintGL()
{
    dreieck triangle;
    triangle.drawTriangle(parama, paramb, paramc);
}

void OGLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

