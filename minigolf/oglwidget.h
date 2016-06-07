#ifndef OGLWIDGET_H
#define OGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include "kugel.h"
#include "dreieck.h"

class OGLWidget : public QOpenGLWidget,
                  protected QOpenGLFunctions
{
    Q_OBJECT

public:
    OGLWidget(QWidget *parent = 0);
    ~OGLWidget();

public slots:
    void setParamA( int newa );
    void setParamB( int newb );
    void setParamC( int newc );

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    int parama;
    int paramb;
    int paramc;
    Kugel k;
    Dreieck d;

};


#endif // OGLWIDGET_H
