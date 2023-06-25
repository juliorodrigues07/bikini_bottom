#include "bikini_bottom.h"

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_DEPTH | GLUT_RGB);

    glutInitWindowSize (1280, 720);
    glutInitWindowPosition (10, 10);
    glutCreateWindow(argv[0]);

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
