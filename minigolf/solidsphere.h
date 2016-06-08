#ifndef SOLIDSPHERE_H
#define SOLIDSPHERE_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include <cmath>

class SolidSphere
{
public:
    SolidSphere(float radius, unsigned int rings, unsigned int sectors);
    void draw(GLfloat x, GLfloat y, GLfloat z);

protected:
    std::vector<GLfloat> vertices;
    std::vector<GLfloat> normals;
    std::vector<GLfloat> texcoords;
    std::vector<GLushort> indices;

};

#endif // SOLIDSPHERE_H
