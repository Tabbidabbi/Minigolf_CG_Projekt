
#include "oglwidget.h"
#include "kugel.h"
#include <cmath>
#include <QDebug>

float animatestep = 1.0;
float shootPower = 0;

OGLWidget::OGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    QTimer *aTimer = new QTimer;
    connect(aTimer,SIGNAL(timeout(QPrivateSignal)),SLOT(animate()));
    //aTimer->start(1);
    zoom  = 100;
    power = 0;

}
OGLWidget::~OGLWidget()
{
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

    qDebug() << "shootPower: " << shootPower;
    //qDebug() << "power: " << power;
    //qDebug() << "step: " << animatestep;

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

    // Change light position
    //float light_pos[] = { 10.f * cosf(light*M_PI/180.f),
                          // 5.f,
                          //10.f * sinf(light*M_PI/180.f), 0.f };
    //glLightfv(GL_LIGHT1, GL_POSITION,  light_pos);






    //glPushMatrix();
      glRotatef(90, 1, 0, 0);
      glRotatef(180, 0, 1, 0);
      //Multipliziert die aktuelle Matrix mit einer Verschiebungsmatrix.
      glTranslatef(-2,0,-8);

    //Bestimmt einen symbolischen Wert der eine Färbetechnik (Shadingtechnique) repräsentiert. Akzeptierte Werte sind GL_FLAT und GL_SMOOTH.
    glShadeModel(GL_FLAT);

    glPushMatrix();

    miniGolfTrack.drawTrack();
    glPopMatrix();
    drawLine();




    glColor3f(0.0, 0.0, 0.0);

    kugel.drawKugel(QVector3D( 2, 0, animatestep), 0.2);
    if(shootPower > 0){
        animate();
    }






    //Zeichnet Kugel
   // glColor3f( 1.0f, 1.0f, 0.0f );
   // k.drawKugel(QVector3D( 5, 0, 0), 2);
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

//Bekommt die aktuelle Mausposition zurück
void OGLWidget::mousePressEvent(QMouseEvent *event)
{
    // Upon mouse pressed, we store the current position...
    pos = event->pos();
}

void OGLWidget::animate()
{
    animatestep = animatestep+(shootPower/500);
    shootPower--;
    update();
}

void OGLWidget::mousePressEvent(QMouseEvent *event){
    shootPower = power;
    update();
}

