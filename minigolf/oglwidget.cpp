#include "oglwidget.h"
#include "kugel.h"
#include <cmath>
#include <QDebug>
#include <iostream>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>

using namespace std;

OGLWidget::OGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    //Deklariert QMediaPlayer-Objekt
    colSound = new QMediaPlayer;
    //Deklariert QMediaPlayer-Objekt
    music = new QMediaPlayer;
    //Schusswinkel
    shootAngle  = 0;
    //x-Rotation
    rotx  = 90;
    //y-Rotation
    roty  = 180;
    //z-Rotation
    rotz  = 0;
    //Geschwindigkeit der Kugel
    speed = 0.0;
    //x-Koordinate der Kudel
    sphereCoordX = -2.0;
    //z-Koordinate der Kugel
    sphereCoordZ = -7.0;
    //Transformation nach z
    transZ = 0;
    //Transformation nach x
    transX = 0;
    //X-Koordinate
    xCoordinate;
    //z-Koordinate
    zCoordinate;
    //Orthogonale x
    orthoX = 20;
    //Orthogonale z
    orthoZ = 20;
    //Orthogonale y
    orthoY = 20;
    //z-Richtung
    zDirection = 0;
    //x-Richtung
    xDirection = 0;
    //Richtung
    direction;
    //Schussstaerke
    power = 50;
    //Toleranzfaktor
    toleranceFactor = 0.2;
}

OGLWidget::~OGLWidget()
{
}

//Setter-Methode
void OGLWidget::setRotX(int newrx)
{
    rotx = newrx;
    update();
}

//Setter-Methode
void OGLWidget::setTransZ(int newtz)
{
    transZ = newtz;
    update();
}

//Setter-Methode
void OGLWidget::setTransX(int newtx)
{
    transX = newtx;
    update();
}

//Setter-Methode
void OGLWidget::setRotY(int newry)
{
    roty = newry;
    update();
}

//Setter-Methode
void OGLWidget::setRotZ(int newrz)
{
    rotz = newrz;
    update();
}

//Setter-Methode
void OGLWidget::setPower(int newpower)
{
    power = newpower;
    update();

}

//Setter-Methode
void OGLWidget::setShoots(int newshoots)
{
    shoots = newshoots;
    update();

}

//Setter-Methode
void OGLWidget::setShootAngle(int newShootAngle)
{
    shootAngle = newShootAngle;

    update();
}

//Setter-Methode
void OGLWidget::musicOn() {

    music->play();

}

//Setter-Methode
void OGLWidget::musicOff() {

    music->stop();

}

//Setter-Methode
void drawLine(){
    //X-Achse positiv

    glBegin(GL_LINES);
        //Legt die Breit für GL_Lines fest
        glLineWidth(5.0);
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
    glLineWidth(3.0);
    glIsEnabled(GL_LINE_SMOOTH);

    // Calculate color for each pixel fragment
    glShadeModel(GL_SMOOTH);
    glClearColor(0,0,0,1);

    //Hintergrund- und Kollisionsmusik
    QMediaPlaylist *list = new QMediaPlaylist();
    list->addMedia(QUrl("qrc:/sounds/music.wav"));
    list->setPlaybackMode(QMediaPlaylist::Loop);

    music->setPlaylist(list);
    music->setVolume(50);
    music->play();

    colSound->setMedia(QUrl("qrc:/sounds/pong.wav"));
    colSound->setVolume(50);
    colSound->setPlaybackRate(2);
}

void OGLWidget::paintGL(){

    QDial * angleDial = this->window()->findChild<QDial*>("shootAngle");
    QSlider * powerSlider = this->window()->findChild<QSlider*>("power");
    QLabel * shootsLabel = this->window()->findChild<QLabel*>("shoots");

    float goalX = 7.0;
    float goalZ = 6.0;
    float goalTopRightX = goalX + 0.2;
    float goalTopLeftX = goalX - 0.2;
    float goalTopLeftZ = goalZ - 0.2;
    float goalBotLeftZ = goalZ + 0.2;

    if(sphereCoordX >= goalTopLeftX && sphereCoordX <= goalTopRightX){
        if(sphereCoordZ >= goalTopLeftZ && sphereCoordZ <= goalBotLeftZ){
            int tempShoots = shoots;
            sphereCoordZ = -7.0;
            sphereCoordX = -2.0;
            speed = 0;
            shootAngle = 0;
            shoots = 0;
            power = 50;
            angleDial->setValue(0);
            powerSlider->setValue(50);
            shootsLabel->setNum(0);
            //Zeichnet Kugel
            kugel.drawKugel(QVector3D( sphereCoordX, 0.4, sphereCoordZ), 0.2);

            //Messagebox erscheint
            QMessageBox msgBox;
            QString text = QString("Runde vorbei.\nAnzahl der Schüsse: %1").arg(tempShoots);
            msgBox.setWindowTitle("Runde vorbei");
            //msgBox.warning(this, "test", "text");
            msgBox.setText(text);
            msgBox.exec();
        }
    }

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
    glScalef( 2, 2, 2 ); // Scale along all axis
    //Farbbuffer und Tiefenpuffer entleeren
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //Legt die Hintergrundfarbe fest
    glClearColor(0, 0, 0, 1.0);

    glRotatef(rotx, 1.0f, 0.0f, 0.0f); // Rotate around x axis
    glRotatef(roty, 0.0f, 1.0f, 0.0f); // Rotate around y axis
    glRotatef(rotz, 0.0f, 0.0f, 1.0f); // Rotate around z axis

    //Multipliziert die aktuelle Matrix mit einer Verschiebungsmatrix.
    glTranslatef((transX),0,(transZ));

    //Bestimmt einen symbolischen Wert der eine Färbetechnik (Shadingtechnique) repräsentiert. Akzeptierte Werte sind GL_FLAT und GL_SMOOTH.
    glShadeModel(GL_FLAT);

    glPushMatrix();
    glTranslated(-4,0,-8);
    //Zeichnet Bahn
    miniGolfTrack.drawTrack();
    glPopMatrix();
    glPushMatrix();
    //drawLine();
    glPopMatrix();

    glColor3f(0.0, 0.0, 0.0);
    //Zeichnet Kugel
    kugel.drawKugel(QVector3D( sphereCoordX, 0.4, sphereCoordZ), 0.2);

    if(speed == 0){
        angleDial->setDisabled(false);
        powerSlider->setDisabled(false);
        glPushMatrix();
        //Zeichnet Richtungslinie
        drawDirectionLine();
        glPopMatrix();
    }

    if(speed > 0  ){
        angleDial->setDisabled(true);
        powerSlider->setDisabled(true);
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
    //Mauspositionen
    mouseXPos = ((float)lastpos.x()/this->width());
    mouseZPos = ((float)lastpos.y()/this->height());

    //Abfangen der Mauspositionswerte x
    if (mouseXPos >= 0.5) {
        xCoordinate = (-((0.5 - (1-mouseXPos))*(orthoX)) - (transX) ) ;
    } else {

        xCoordinate = (-((0.5 -mouseXPos) * ((-orthoX)) - (-transX))) ;
    }
    //Abfangen der Mauspositionswerte z
    if (mouseZPos >= 0.5) {
        zCoordinate = (-((0.5 - (1-mouseZPos))*(orthoZ)) - (transZ));
    } else {
        zCoordinate  = (-((0.5 -mouseZPos) * ((-orthoZ)) - (-transZ))) ;
    }

    qDebug() << "Maus Position: "  << "X ->" << xCoordinate  << "Verschiebung: " << transX ;
    qDebug() << "Maus Position: " <<  "Z ->" << zCoordinate << "Verschiebung: " << transZ ;

}

void OGLWidget::shootSphere() {

    QLabel * shootsLabel = this->window()->findChild<QLabel*>("shoots");

    if(xCoordinate >= (sphereCoordX - 0.2) && xCoordinate <= (sphereCoordX + 0.2) ) {
        if(zCoordinate >= (sphereCoordZ - 0.2) && zCoordinate <= (sphereCoordZ + 0.2) ) {
            speed = power;
            direction = speed;
            qDebug() << shoots;
            //Abfrage, ob Schusskraft gesetzt
            if(power != 0){
                shoots++;
            } else {
                QMessageBox msgBox;
                QString text = QString("Bitte erhöhen Sie ihre Schusskraft");
                msgBox.setWindowTitle("Hinweis");
                msgBox.setText(text);
                msgBox.exec();
            }
            shootsLabel->setNum(shoots);
        }
    }
}

void OGLWidget::mousePressEvent(QMouseEvent *event){

    // Upon mouse pressed, we store the current position...
    if(event->buttons() == Qt::LeftButton) {
        setLocalCoordninates(event);
    }

    shootSphere();
    update();
}

void OGLWidget::mouseMoveEvent(QMouseEvent *event) {

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


void OGLWidget::animateSphere(){

    //Kollision mit der X-Achse
    if(checkCollisionXAxis()) {
        shootAngle = shootAngle * (-1);
        colSound->play();
    }

    //Kollision mit der Y-Achse
    if(checkCollisionZAxis()) {
        if (shootAngle <= 180 && shootAngle >= 0) {
            shootAngle = (180-shootAngle);
        }
        if (shootAngle < 0 && shootAngle >= (-180)) {
            shootAngle = (-180 - (shootAngle));
        }
        colSound->play();
    }

    //Berechnet die x und z Werte in abhängikeit vom Winkel
    xDirection = -sin(shootAngle*M_PI/180)*(speed/500);
    zDirection = sin((90-shootAngle)*M_PI/180) * (speed/500);

    //Wenn die Winkel 90 bzw -90 sind muss z = 0 sein da nur noch auf der x Achse animiert werden darf.
    if (shootAngle == 90 || shootAngle == -90) {
        zDirection = 0;
    }

    sphereCoordZ = sphereCoordZ+(zDirection);
    sphereCoordX = sphereCoordX+(xDirection);

    //qDebug() << "X: " << sphereCoordX;
    //qDebug() << "Z:" << sphereCoordZ;
    //    qDebug() << "Speed: " << speed;
    speed--;
    //coordX = coordX+(speed/500);
    update();
}

//Richtungslinie
void OGLWidget::drawDirectionLine() {
    float xDirection = -sin(shootAngle*M_PI/180)*(power/40);
    float zDirection = sin((90-shootAngle)*M_PI/180) * (power/40);

    if (shootAngle == 90 || shootAngle == -90) {
        zDirection = 0;
    }

    if (shootAngle == 0) {
        zDirection = power/40;
    }

    glBegin(GL_LINES);
        //Legt die Breit für GL_Lines fest
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(sphereCoordX, 0.2, sphereCoordZ);
        glVertex3f(sphereCoordX + xDirection, 0.2, sphereCoordZ +zDirection);
    glEnd();
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

bool OGLWidget::checkCollisionZAxis(){

    float sphereToleranceZ = 0;

    if (shootAngle < 90 && shootAngle > -90) {
        sphereToleranceZ = sphereCoordZ + 0.2;
    } else {
        sphereToleranceZ = sphereCoordZ + (-0.2);
    }

    //Bottom Wall
    if((sphereToleranceZ) < -8  && sphereCoordX >= -4 && sphereCoordX <= 0){
        //Collision
        qDebug() << "Bottom Wall";
        return true;
    }

    //Top Wall
    if(sphereToleranceZ >= 8 && sphereCoordX <= 8 && sphereCoordX >= -4){
        //Collision
        qDebug() << "Top Wall";
        return true;
    }

    //Left Bottom Wall
    if(sphereCoordX >= -0.2  && sphereCoordX <= 8 && sphereToleranceZ >= 3.8  && sphereToleranceZ <= 4 ) {
        //Collision
        qDebug() << "Left Bottom Wall";
        return true;
    }

    //ZylinderTopWall
        if(sphereToleranceZ >= 5.4 && sphereToleranceZ <=5.6  && sphereCoordX <= 3.5 && sphereCoordX >= 2.4   ) {
        qDebug() << "ZylinderTopWall";
        return true;
    }

    //ZylinderTopTopWall
    if(sphereToleranceZ >= 7.4 && sphereToleranceZ <=7.6  && sphereCoordX <= 3.5 && sphereCoordX >= 2.4   ) {
        qDebug() << "ZylinderTopTopWall";
        return true;
    }

    //ZylinderBottomWall
    if(sphereToleranceZ >= 4.4 && sphereToleranceZ <=4.6 && sphereCoordX <= 3.5 && sphereCoordX >= 2.4  ) {
        qDebug() << "ZylinderBottomWall";
        return true;
    }

    //ZylinderTopBottomWall
    if(sphereToleranceZ >= 6.4 && sphereToleranceZ <=6.6 && sphereCoordX <= 3.5 && sphereCoordX >= 2.4  ) {
        qDebug() << "ZylinderTopBottomWall";
        return true;
    }

    //Pyramide Bottom Wall
    if(sphereToleranceZ <= 0.2  && sphereToleranceZ >=0 && sphereCoordX <= -0.8 && sphereCoordX >= -3.1){
        //Collision
        qDebug() << "Pyramide Bottom Wall";
        return true;
    }

    //Pyramide Top Wall
    if(sphereToleranceZ >= 1.8  && sphereToleranceZ <=2  && sphereCoordX <= -0.8 && sphereCoordX >= -3.1){
        //Collision
        qDebug() << "Pyramide Top Wall";
        return true;
    }

    return false;
}

bool OGLWidget::checkCollisionXAxis(){

    float sphereToleranceX = 0;

    if (shootAngle >0) {
        sphereToleranceX = sphereCoordX + (-0.2);
    } else {
        sphereToleranceX = sphereCoordX +(0.2);
    }

    //Rigth Wall
    if(sphereToleranceX <= -4 && sphereToleranceX >=-4.2 && sphereCoordZ <= 8 && sphereCoordZ >= -8){
        //Collision
        qDebug() << "Right Wall";
        return true;
    }

    //Top Left Wall
    if(sphereToleranceX >= 8  && sphereCoordZ <= 8 && sphereCoordZ >= 4){
        //Collision
        qDebug() << "Top Left Wall";
        return true;
    }

    //Bottom Left Wall
    if(sphereCoordZ >= -8 && sphereCoordZ < (4 - toleranceFactor) && sphereToleranceX >= 0 ){
        //Collision
        qDebug() << "Bottom Left Wall";
        return true;
    }


    //Pyramide Left Wall
    if(sphereToleranceX <= -0.8  && sphereToleranceX>-1 && (sphereCoordZ >= 0 ) && sphereCoordZ <= 2){
        //Collision
        qDebug() << "Pyramide Left Wall";
        return true;
    }

    //Pyramide Right Wall
    if(sphereToleranceX >= -3.1  && sphereToleranceX <=-2.9 && sphereCoordZ >=0 && sphereCoordZ <= 2){
        //Collision
        qDebug() << "Pyramide Right Wall";
        return true;
    }

    //ZylinderTopRightWall
    if(sphereCoordZ >= 6.4 && sphereCoordZ <=7.6 && sphereToleranceX <= 2.6 && sphereToleranceX >= 2.4  ) {
        qDebug() << "ZylinderTopRightWall";
        return true;
    }

    //ZylinderTopLeftWall
    if(sphereCoordZ >= 6.4 && sphereCoordZ <=7.6 && sphereToleranceX >= 3.4 && sphereToleranceX <= 3.6   ) {
        qDebug() << "ZylinderTopLeftWall";
        return true;
    }

    //ZylinderRightWall
    if(sphereCoordZ >= 4.4 && sphereCoordZ <=5.6 && sphereToleranceX <= 2.6 && sphereToleranceX >= 2.4  ) {
        qDebug() << "ZylinderRightWall";
        return true;
    }

    //ZylinderLeftWall
    if(sphereCoordZ >= 4.4 && sphereCoordZ <=5.6 && sphereToleranceX >= 3.4 && sphereToleranceX <= 3.6   ) {
        qDebug() << "ZylinderLeftWall";
        return true;
    }

    return false;
}
