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


    // Draw a sphere with center pos, radius rad and nr_lat/nr_lon segments
    void drawSphere(const QVector3D &pos,
                    float rad = 1.f,
                    int nr_lat = 90, int nr_lon = 90 );


public slots:
    // Set zoom factor
    void setZoom( int newzoom );
    // Set the rotation angles





protected:
    void setRotX( int newrx );
    void setRotY( int newry );
    void setRotZ( int newrz );

    void setTransZ(int newtz);
    void setTransX(int newtx);
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    Kugel kugel;
    Dreieck d;
    Kreis kreis;
    int rotx;       // Rotation angles (0..360)
    int roty;
    int rotz;
    int transZ;
    int transX;

     int zoom;       // Zoom factor (0..200, 100 for 1:1)
    minigolfTrack miniGolfTrack;
    //int light;      // Light position (0..360, around y axis)
    QPoint lastpos;  // Last position of mouse pressed, used for dragging

};


#endif // OGLWIDGET_H
