#include "Ground.h"
#include "../../Globals.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <GL/glut.h>

Ground::Ground() {}


void Ground::draw(int floorSize) {
    glColor3f(0.0f, 0.8f, 0.0f);

    glDisable(GL_LIGHTING);

    glBegin(GL_QUADS);
    glVertex3f(-floorSize, 0.0f, -floorSize);
    glVertex3f(floorSize, 0.0f, -floorSize);
    glVertex3f(floorSize, 0.0f, floorSize);
    glVertex3f(-floorSize, 0.0f, floorSize);
    glEnd();

    glEnable(GL_LIGHTING);
}