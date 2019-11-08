// This is a simple introductory program; its main window contains a static
// picture of a torus.  The program illustrates viewing by choosing a camera
// setup with gluLookAt(), which is conceptually simpler than transforming
// objects to move into a predefined view volume.

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// Clears the window and draws the torus.
void display() {

	glClear(GL_COLOR_BUFFER_BIT);

	// Draw a white torus of outer radius 3, inner radius 0.5 with 15 stacks
	// and 30 slices.
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex3f(0, 0, 0); glVertex3f(0, 0, 1); glVertex3f(0, 1, 1); glVertex3f(0, 1, 0);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(0, 0, 0); glVertex3f(0, 0, 1); glVertex3f(0, 1, 1); glVertex3f(0, 1, 0);
	glEnd();

	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex3f(0, 0, 0); glVertex3f(0, 0, 1); glVertex3f(1, 0, 1); glVertex3f(1, 0, 0);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(0, 0, 0); glVertex3f(0, 0, 1); glVertex3f(1, 0, 1); glVertex3f(1, 0, 0);
	glEnd();

	glColor3f(0.3, 0.3, 0.7);
	glBegin(GL_QUADS);
	glVertex3f(1, 0, 0); glVertex3f(1, 0, 1); glVertex3f(1, 1, 1); glVertex3f(1, 1, 0);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(1, 0, 0); glVertex3f(1, 0, 1); glVertex3f(1, 1, 1); glVertex3f(1, 1, 0);
	glEnd();

	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex3f(0.5, 1.5, 0); glVertex3f(0.5, 1.5, 1); glVertex3f(-0.1, 0.9, 1); glVertex3f(-0.1, 0.9, 0);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.5, 1.5, 0); glVertex3f(0.5, 1.5, 1); glVertex3f(-0.1, 0.9, 1); glVertex3f(-0.1, 0.9, 0);
	glEnd();

	glColor3f(0.3, 0.3, 0.7);
	glBegin(GL_QUADS);
	glVertex3f(0.5, 1.5, 0); glVertex3f(0.5, 1.5, 1); glVertex3f(1.1, 0.9, 1); glVertex3f(1.1, 0.9, 0);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.5, 1.5, 0); glVertex3f(0.5, 1.5, 1); glVertex3f(1.1, 0.9, 1); glVertex3f(1.1, 0.9, 0);
	glEnd();


	glFlush();
}

// Sets up global attributes like clear color and drawing color, and sets up
// the desired projection and modelview matrices.
void init() {

	// Set the current clear color to black and the current drawing color to
	// white.
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);

	// Set the camera lens to have a 60 degree (vertical) field of view, an
	// aspect ratio of 4/3, and have everything closer than 1 unit to the
	// camera and greater than 40 units distant clipped away.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, 4.0 / 3.0, 1, 40);

	// Position camera at (4, 6, 5) looking at (0, 0, 0) with the vector
	// <0, 1, 0> pointing upward.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(4, 6, 5, 0, 0, 0, 0, 1, 0);

	//gluLookAt, glOrtho, gluOrtho2D
}

// Initializes GLUT, the display mode, and main window; registers callbacks;
// does application initialization; enters the main event loop.
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