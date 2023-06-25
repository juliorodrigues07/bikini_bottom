#include "bikini_bottom.h"

void init(void)
{
    glClearColor(0.592156863f, 0.960784314f, 0.866666667f, 0.0);
    glShadeModel (GL_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);

    GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { 10.0, 10.0, -10.0, 0.0 };

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

    glColor3f(0.5, 1.0, 0.5);
}

void drawEllipsoid(unsigned int uiStacks, unsigned int uiSlices, float fA, float fB, float fC){

    float tStep = (M_PI) / (float)uiSlices;
    float sStep = (M_PI) / (float)uiStacks;

    for (float t = -M_PI / 2; t <= (M_PI / 2) + .0001; t += tStep)
    {
        glBegin(GL_TRIANGLE_STRIP);
        for (float s = -M_PI; s <= M_PI + .0001; s += sStep)
        {
            glVertex3f(fA * cos(t) * cos(s), fB * cos(t) * sin(s), fC * sin(t));
            glVertex3f(fA * cos(t + tStep) * cos(s), fB * cos(t + tStep) * sin(s), fC * sin(t + tStep));
        }
        glEnd();
    }
}

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0f, 30.0f, 50.0f, 0.0f, 20.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    // Ground
    glPushMatrix();
        glColor3f(0.91372549f, 0.964705882f, 0.854901961f);
        glTranslatef(0.0, -20, 0.0);
        glScalef(200.0, 40.0, 250.0);
        glutSolidCube(1.0);
    glPopMatrix();

    // Patrick's house
    glPushMatrix();
        glColor3f(0.218431373f, 0.124509804, 0.051960784f);
        glTranslatef(-50.0, 0.0, 0.0);
        drawEllipsoid(50, 50, 30, 36, 12);
    glPopMatrix();

    // SpongeBob's house
    glPushMatrix();
        // Orange
        glColor3f(0.878431373f, 0.474509804, 0.101960784f);

        // Pineapple
        glTranslatef(50.0, 10.0, 0.0);
        drawEllipsoid(50, 50, 25, 45, 12);

        // Silver
        glColor3f(0.662745098f, 0.850980392, 1.0f);

        // Upper window
        glTranslatef(-10.0, 25.0, 12.0);
        glutSolidTorus(1.0, 4.0, 20.0, 20.0);

        // Lower window
        glTranslatef(25.0, -20.0, 0.0);
        glutSolidTorus(1.0, 4.0, 20.0, 20.0);

        // Front door
        glTranslatef(-15.0, -20.0, 0.0);
        drawEllipsoid(50, 50, 8, 25, 3);

        // Green
        glColor3f(0.77254902f, 0.952941176f, 0.180392157f);

        int height_change = 20;
        int angle_change = 20;
        glTranslatef(-10.0, 55.0, -10.0);
        glRotatef(-90, 0, 1, 0);
        glRotatef(-45, 1, 0, 0);

        // Pineapple's crown
        for (int i = 0; i < 6; i++) {
            glutSolidCone(5.0, height_change, 20.0, 20.0);
            glTranslatef(5.0, 5.0, 0.0);
            glRotatef(-angle_change, 1, 0, 0);

            if (i < 3)
                height_change += 3;
            else
                height_change -= 3;
        }
    glPopMatrix();

    glFlush();
    glutPostRedisplay();
}

void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();

    if (w <= h)
        glOrtho(-50, 50, -50 * (GLfloat)h / (GLfloat)w, 50 * (GLfloat)h / (GLfloat)w, -100.0, 100.0);
    else
        glOrtho(-50 * (GLfloat)w / (GLfloat)h, 50 * (GLfloat)w / (GLfloat)h, -50, 50, -100.0, 100.0);
}