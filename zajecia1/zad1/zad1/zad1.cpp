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
	/// Przekazanie polecenia czyszczenia do wykonania
	glFlush();
}
// Ustalenie stanu rendrowania  
void SetupRC(void) {
	glClearColor(0.6f, 0.4f, 0.12f, 1.0f);
}
// Główny punki wejścia programu  
void main(int argc, char **argv) {
	//this is init function
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Mój pierwszy program w GLUT");
	glutDisplayFunc(RenderScene);
	SetupRC();
	glutMainLoop();
}

