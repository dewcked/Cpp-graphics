void RenderWindow::OnSize(WPARAM wParam, LPARAM lParam)
{
	GLsizei width = LOWORD(lParam);
	GLsizei height = HIWORD(lParam);

	if (height == 0)
		height = 1;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-3.0f, 3.0f, -3.0f, 3.0, 1.0f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

BOOL RenderWindow::InitGL(void)
{
	Window::InitGL();

	glEnable(GL_LIGHTING);

	GLfloat lightPos[4] = { 0.5f, 0.5f, 0.5f, 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glEnable(GL_LIGHT0);

	return TRUE;
}

void RenderWindow::RenderGLScene(void)
{
	Window::RenderGLScene();

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -2.0f);
	glRotatef(33.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(33.0f, 0.0f, 1.0f, 0.0f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glutSolidTeapot(0.4f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.0f, 0.0f, -4.0f);
	glRotatef(33.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(33.0f, 0.0f, 1.0f, 0.0f);
	glColor3f(0.3f, 0.3f, 0.3f);
	glutSolidTeapot(0.4f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.0f, 0.0f, -6.0f);
	glRotatef(33.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(33.0f, 0.0f, 1.0f, 0.0f);
	glColor3f(0.1f, 0.1f, 0.1f);
	glutSolidTeapot(0.4f);
	glPopMatrix();
}