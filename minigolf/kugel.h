#ifndef KUGEL_H
#define KUGEL_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMouseEvent>
#include <QVector3D>

class Kugel : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    Kugel(QWidget *parent = 0);
    ~Kugel();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL(const QVector3D& pos, float rad, int nr_lat, int nr_lon);
};

#endif // KUGEL_H
