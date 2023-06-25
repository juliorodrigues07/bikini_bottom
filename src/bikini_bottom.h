#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

void init(void);
void display(void);
void reshape (int w, int h);
void drawEllipsoid(unsigned int uiStacks, unsigned int uiSlices, float fA, float fB, float fC);
