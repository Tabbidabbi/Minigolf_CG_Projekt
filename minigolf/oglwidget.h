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


public slots:
    // Set zoom factor
    void setZoom( int newzoom );




protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    Kugel kugel;
    Dreieck d;
    Kreis kreis;
     int zoom;       // Zoom factor (0..200, 100 for 1:1)

protected:

    minigolfTrack miniGolfTrack;
    //int light;      // Light position (0..360, around y axis)
    //QPoint lastpos; // Last position of mouse pressed, used for dragging

};


#endif // OGLWIDGET_H
