#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	float bogan = 0.003f;

	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex3f(0, 0, 0); glVertex3f(0, 0, 1); glVertex3f(0, 1, 1); glVertex3f(0, 1, 0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(0, 0, 0); glVertex3f(0, 0, 1); glVertex3f(1, 0, 1); glVertex3f(1, 0, 0);
	glEnd();

	glColor3f(0.3, 0.3, 0.7);
	glBegin(GL_QUADS);
	glVertex3f(1, 0, 0); glVertex3f(1, 0, 1); glVertex3f(1, 1, 1); glVertex3f(1, 1, 0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.5, 1.5, 0); glVertex3f(0.5, 1.5, 1); glVertex3f(1.1, 0.9, 1); glVertex3f(1.1, 0.9, 0);
	glEnd();

	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex3f(0.5, 1.5, 0); glVertex3f(0.5, 1.5, 1); glVertex3f(-0.1, 0.9, 1); glVertex3f(-0.1, 0.9, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.5, 1.5, 1); glVertex3f(1, 1, 1); glVertex3f(1, 0, 1); glVertex3f(0, 0, 1); glVertex3f(0, 1, 1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0.5, 1.5, 0); glVertex3f(1, 1, 0); glVertex3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(0, 1, 0);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(0 - bogan, 0 - bogan, 0 - bogan); glVertex3f(0 - bogan, 0 - bogan, 1 + bogan); glVertex3f(1 + bogan, 0 - bogan, 1 + bogan); glVertex3f(1 + bogan, 0 - bogan, 0 - bogan);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(0, 1 - bogan, 0); glVertex3f(0, 1 - bogan, 1);
	glVertex3f(1, 1 - bogan, 0); glVertex3f(1, 1 - bogan, 1);
	glVertex3f(0 - bogan, 0, 0 - bogan); glVertex3f(0 - bogan, 1 - bogan, 0 - bogan);
	glVertex3f(1, 0, 0 - bogan); glVertex3f(1, 1 - bogan, 0 - bogan);
	glVertex3f(0 - bogan, 0, 1 + bogan); glVertex3f(0 - bogan, 1 - bogan, 1 + bogan);
	glVertex3f(1, 0, 1 + bogan); glVertex3f(1, 1 - bogan, 1 + bogan);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.5, 1.5 + bogan, 0 - bogan); glVertex3f(0.5, 1.5 + bogan, 1 + bogan); glVertex3f(-0.1 - bogan, 0.9 - bogan, 1 + bogan); glVertex3f(-0.1 - bogan, 0.9 - bogan, 0 - bogan);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.5, 1.5 + bogan, 0 - bogan); glVertex3f(0.5, 1.5 + bogan, 1 + bogan); glVertex3f(1.1 + bogan, 0.9 - bogan, 1 + bogan); glVertex3f(1.1 + bogan, 0.9 - bogan, 0 - bogan);
	glEnd();

	glFlush();
}
void init() {
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);

	glViewport(0, 0, 1, 1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2, 2, -2, 2, 1, 5);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	gluLookAt(-2, 0, 2, 0, 0, 0, 0, 1, 0);

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(80, 80);
	glutInitWindowSize(800, 600);
	glutCreateWindow("201511779 °­Âù¿ì");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}