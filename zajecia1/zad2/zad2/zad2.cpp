#include "stdafx.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
// Funkcja wywoływana w celu narysowania sceny
void RenderScene(void) {
	// Wyczyszczenie okna aktualnym kolorem czyszczącym
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	// Narysowanie prostokta wypełnionego aktualnym kolorem  
	glRectf(-25.0f, 25.0f, 25.0f, -25.0f);

	/// Przekazanie polecenia czyszczenia do wykonania
	glFlush();
}
// Ustalenie stanu rendrowania  
void SetupRC(void) {
	glClearColor(0.6f, 0.4f, 0.12f, 1.0f);
}

void ChangeSize(int w, int h) {
	GLfloat aspectRatio;
	// Zabezpieczenie przed dzieleniem przez zero  
	if (h == 0)   h = 1;
	// Ustawienie wielkości widoku na równą wielkości okna     
	glViewport(0, 0, w, h);
	// Ustalenie układu współrzędnych  
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Wyznaczenie przestrzeni ograniczającej (lewy, prawy, dolny, górny, bliski, odległy)  
	aspectRatio = (GLfloat)w / (GLfloat)h;
	if (w <= h)    glOrtho(-100.0, 100.0, -100 / aspectRatio, 100.0 / aspectRatio, 1.0, -1.0);
	else    glOrtho(-100.0 * aspectRatio, 100.0 * aspectRatio, -100.0, 100.0, 1.0, -1.0);
	glMatrixMode(GL_MODELVIEW);  glLoadIdentity();
}


// Główny punki wejścia programu  
void main(int argc, char **argv) {
	//this is init function
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Mój pierwszy program w GLUT");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	SetupRC();	
	glutMainLoop();
}