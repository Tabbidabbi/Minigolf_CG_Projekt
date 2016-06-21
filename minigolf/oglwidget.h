#ifndef OGLWIDGET_H
#define OGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QVector3D>
#include "kugel.h"
#include "dreieck.h"
#include "kreis.h"
#include <QMouseEvent>
#include "minigolftrack.h"
#include <Qtimer>
#include <QDebug>
#include <QOpenGLFunctions>


class OGLWidget : public QOpenGLWidget,
                  protected QOpenGLFunctions
{
    Q_OBJECT

public:
    OGLWidget(QWidget *parent = 0);
    ~OGLWidget();


    // Used to rotate object by mouse
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

    //Collision check
    bool checkCollisionXAxis();
      bool checkCollisionZAxis();

    // Draw a sphere with center pos, radius rad and nr_lat/nr_lon segments
    void drawSphere(const QVector3D &pos,
                    float rad = 1.f,
                    int nr_lat = 90, int nr_lon = 90 );




public slots:
    // Set zoom factor
    void setShootAngle( int newShootAngle );

    void setPower( int newpower);





protected:
    void setRotX( int newrx );
    void setRotY( int newry );
    void setRotZ( int newrz );

    void setTransZ(int newtz);
    void setTransX(int newtx);
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void setLocalCoordninates(QMouseEvent *event);
    void shootSphere();
    void drawDirectionLine();
    //void timerEvent(QTimerEvent *event);

    Kugel kugel;
    Dreieck d;
    Kreis kreis;

    int rotx;       // Rotation angles (0..360)
    int roty;
    int rotz;

    float transZ;
    float transX;
    float tolleranceFactor;

    float xCoordinate;
    float transXNegativ;
    float zCoordinate;
    float transZNegativ;
    float orthoX;
    float orthoZ;
     float orthoY;

    int shootAngle;
    float power;

    float xDirection;
    float zDirection;
    float direction;



    // Schussgeschwindigkeit
    float speed;

    // Koordinaten X und Y
    float sphereCoordZ;
    float sphereCoordX;



    minigolfTrack miniGolfTrack;
    //int light;      // Light position (0..360, around y axis)
    QPoint lastpos;  // Last position of mouse pressed, used for dragging
     float mouseXPos;
     float mouseZPos;



private:

    QBasicTimer timer;

private slots:
    void animateSphere();

};


#endif // OGLWIDGET_H
