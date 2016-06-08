#include "oglwidget.h"
#include "kugel.h"
#include <cmath>
#include <QDebug>

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

    // Use depth testing and the depth buffer
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    // Calculate color for each pixel fragment
    glShadeModel(GL_SMOOTH);

    // Enable lighting in scene
    glEnable(GL_LIGHTING);

    // Set position of light source
    float light_pos[] = { 10.f, 5.f, 10.f, 0.f };
    glLightfv(GL_LIGHT1, GL_POSITION, light_pos );

    // Set color for this light source
    // (We are only specifying a diffuse light source)
    float light_diffuse[] = { .8f, .8f, .8f, 1.f };
    glLightfv(GL_LIGHT1, GL_DIFFUSE,  light_diffuse );

    // Turn on this light
    glEnable(GL_LIGHT1);

    // Use the color of an object for light calculation
    glColorMaterial( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE );
    glEnable(GL_COLOR_MATERIAL);

}

void OGLWidget::paintGL()
{
    // Clear the scene
    glClearColor(0.f, 0.f, 0.f, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Prepare projection matrix
    glMatrixMode(GL_PROJECTION);
    //Lädt Einheitsmatrix
    glLoadIdentity();
                     // Parallel projection with
    glOrtho(-10, 10, // clipping planes: left,   right
            -10, 10, //                  bottom, top
            -10, 10);//                  near,   far

    // Prepare model matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Change light position
    float light_pos[] = { 10.f * cosf(light*M_PI/180.f),
                           5.f,
                          10.f * sinf(light*M_PI/180.f), 0.f };
    glLightfv(GL_LIGHT1, GL_POSITION,  light_pos);

    double c = parama; // change of color
    double r = paramb;   // degree to rotate
    double t = paramc;

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

    //Zeichnet Kugel
    glColor3f( 1.0f, 1.0f, 0.0f );
    k.drawKugel(QVector3D( 5, 0, 0), 2);




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

