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
	glColor3f(1.0, 1.0, 1.0);
	glutWireTorus(0.5, 3, 15, 30);

	// Draw a red x-axis, a green y-axis, and a blue z-axis.  Each of the
	// axes are ten units long.
	glBegin(GL_LINES);
	glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(10, 0, 0);
	glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 10, 0);
	glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 10);
	glEnd();

	//============================================== lets make cube
	float x = 4;
	float linelen = 0.2;
	int face[6][4][3] = {
		{{1,-1, -1},{1, -1, 1}, {-1, -1, 1}, {-1, -1, -1}},
		{{1, -1, -1}, {1, 1, -1}, {-1,1, -1}, {-1, -1, -1}},
		{{-1, -1, 1}, {-1, 1, 1}, {-1, 1, -1}, {-1, -1, -1}},
		{{1, -1, -1}, {1, 1, -1}, {1, 1, 1}, {1, -1, 1}},
		{{1,1, 1}, {1, 1, -1}, {-1, 1, -1}, {-1, 1, 1}},
		{{1, -1, 1}, {1, 1, 1}, {-1, 1, 1}, {-1, -1, 1}}
	};
	for (int z = 0; z < 3; z++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 6; k++) {
					glBegin(GL_POLYGON);
					for (int l = 0; l < 4; l++) {
						glColor3f(z/3.0, i/3.0, j/3.0);
						glVertex3f(x + linelen * face[k][l][0] + j * 0.45, linelen * face[k][l][1] + i * 0.45, linelen * face[k][l][2] + z * 0.45);
					}
					glEnd();
				}
				glFlush();
			}
		}
	}
	//==============================================
	
}

// Sets up global attributes like clear color and drawing color, and sets up
// the desired projection and modelview matrices.
void init() {

	// Set the current clear color to black and the current drawing color to
	// white.
	glClearColor(0.0, 0.0, 0.0, 1.0);
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
}

// Initializes GLUT, the display mode, and main window; registers callbacks;
// does application initialization; enters the main event loop.
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(80, 80);
	glutInitWindowSize(800, 600);
	glutCreateWindow("A Simple Torus");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}