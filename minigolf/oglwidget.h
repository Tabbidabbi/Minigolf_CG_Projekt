#ifndef OGLWIDGET_H
#define OGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
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
     int zoom;       // Zoom factor (0..200, 100 for 1:1)

protected:

    minigolfTrack miniGolfTrack;

};


#endif // OGLWIDGET_H
