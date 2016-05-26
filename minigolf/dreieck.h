#ifndef DREIECK_H
#define DREIECK_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class Dreieck : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    Dreieck(QWidget *parent = 0);
    ~Dreieck();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

};

#endif // DREIECK_H
