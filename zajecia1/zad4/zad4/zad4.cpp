#include "stdafx.h"
#include <cmath>
#include <GL/glut.h>
#define GL_PI 3.1415926535f

GLfloat vertices[10][2];
GLfloat rsize = 2.0f, polygonCenterPosition[2]{ 0.5f,0.5f };

void resize(GLsizei w, GLsizei h)
{
	if (h == 0)
		h = 1;

	GLfloat ratio = w * 1.0 / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, w, h);
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
}

GLfloat angle = 0.0f;

void renderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	glLoadIdentity();

	gluLookAt(0.0f, 0.0f, 10.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);

	glRotatef(angle, 0.0f, 1.0f, 0.0f);

	glBegin(GL_POLYGON);
	for (int i = 0; i < 10; i++)
		glVertex2f(vertices[i][0], vertices[i][1]);

	glEnd();

	angle += 0.5f;
	glClearColor(0.6f, 0.4f, 0.12f, 1.0f);
	glutSwapBuffers();
}

void main(int argc, char *argv[])
{

	for (size_t i = 0; i < 10; i++)
	{
		vertices[i][0] = polygonCenterPosition[0] + rsize * std::sinf(2 * GL_PI * ((GLfloat)i / 9));
		vertices[i][1] = polygonCenterPosition[1] + rsize * std::cosf(2 * GL_PI * ((GLfloat)i / 9));
	}

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1000, 800);
	glutCreateWindow("Wielokat");
	glutDisplayFunc(renderScene);
	glutReshapeFunc(resize);
	glutIdleFunc(renderScene);
	glutMainLoop();
}