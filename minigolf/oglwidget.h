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


class OGLWidget : public QOpenGLWidget,
                  protected QOpenGLFunctions
{
    Q_OBJECT

public:
    OGLWidget(QWidget *parent = 0);
    ~OGLWidget();

    void mousePressEvent(QMouseEvent *event);

public slots:
    // Set zoom factor
    void setZoom( int newzoom );
    void setPower( int newpower);




protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    //void timerEvent(QTimerEvent *event);

    Kugel kugel;
    Dreieck d;
    Kreis kreis;
    int zoom;       // Zoom factor (0..200, 100 for 1:1)
    int power;


    minigolfTrack miniGolfTrack;
    //int light;      // Light position (0..360, around y axis)
    //QPoint lastpos; // Last position of mouse pressed, used for dragging

private:

    QBasicTimer timer;

private slots:
    void animate();

};


#endif // OGLWIDGET_H
