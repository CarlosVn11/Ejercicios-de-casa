/* Este programa dibuja un mario bros */

//Incluimos las librerias
//#include <GL/glut.h>
//#include <stdlib.h>
/*	Juan Carlos Salazar Santiago
	Ejercicio de casa 1
	Visual Studio 2017
*/
//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): SALAZAR SANTIAGO JUAN CARLOS ****//
//*************	Ejercicio de casa 1: Pixel art			******//
//*************	Fecha: 24/08/18							******//
//************************************************************//
#include "Main.h"
#include <stdio.h>

void InitGL(GLvoid)     // Inicializamos parametros
{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	//glClearDepth(1.0f);									// Configuramos Depth Buffer
	//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar


}

void display(void)   // Creamos la funcion donde se dibuja
{
	float i = 0;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview

	//Poner aqui codigo ha dibujar

	/*Primer figura*/

	glBegin(GL_QUADS);
	glColor3f(0.545f, 0.0f, 0.0f);//Rojo
	glVertex3f(-7.0f, 6.0f, -1.0f);
	glVertex3f(-2.0f, 6.0f, -1.0f);
	glVertex3f(-2.0f, 5.0f, -1.0f);
	glVertex3f(-7.0f, 5.0f, -1.0f);
	glEnd();


	/*Segundo rectangulo */
	glBegin(GL_QUADS);
	glColor3f(0.545f, 0.0f, 0.0f);//Rojo
	glVertex3f(-8.0f, 5.0f, -1.0f);
	glVertex3f(1.0f, 5.0f, -1.0f);
	glVertex3f(1.0f, 4.0f, -1.0f);
	glVertex3f(-8.0f, 4.0f, -1.0f);
	glEnd();


	/*Tercer rectangulo */
	glBegin(GL_QUADS);
	glColor3f(0.502, 0.502, 0.000); //Verde
	glVertex3f(-8.0f, 4.0f, -1.0f);
	glVertex3f(-5.0f, 4.0f, -1.0f);
	glVertex3f(-5.0f, 3.0f, -1.0f);
	glVertex3f(-8.0f, 3.0f, -1.0f);
	glEnd();

	/*Cuarto rectangulo */
	glBegin(GL_QUADS);
	glColor3f(0.502, 0.502, 0.000); //Verde
	glVertex3f(-7.0f, 4.0f, -1.0f);
	glVertex3f(-6.0f, 4.0f, -1.0f);
	glVertex3f(-6.0f, 1.0f, -1.0f);
	glVertex3f(-7.0f, 1.0f, -1.0f);
	glEnd();

	/* Despues de varios rectangulos perdi la cuenta por eso ya no puse que rectangulo era*/
	glBegin(GL_QUADS);
	glColor3f(0.502, 0.502, 0.000); //Verde
	glVertex3f(-6.0f, 2.0f, -1.0f);
	glVertex3f(-5.0f, 2.0f, -1.0f);
	glVertex3f(-5.0f, 1.0f, -1.0f);
	glVertex3f(-6.0f, 1.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.502, 0.502, 0.000); //Verde
	glVertex3f(-9.0f, 3.0f, -1.0f);
	glVertex3f(-8.0f, 3.0f, -1.0f);
	glVertex3f(-8.0f, 0.0f, -1.0f);
	glVertex3f(-9.0f, 0.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.502, 0.502, 0.000); //Verde
	glVertex3f(-9.0f, 1.0f, -1.0f);
	glVertex3f(-7.0f, 1.0f, -1.0f);
	glVertex3f(-7.0f, 0.0f, -1.0f);
	glVertex3f(-9.0f, 0.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.502, 0.502, 0.000); //Verde
	glVertex3f(-3.0f, 4.0f, -1.0f);
	glVertex3f(-2.0f, 4.0f, -1.0f);
	glVertex3f(-2.0f, 2.0f, -1.0f);
	glVertex3f(-3.0f, 2.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.502, 0.502, 0.000); //Verde
	glVertex3f(-2.0f, 2.0f, -1.0f);
	glVertex3f(-1.0f, 2.0f, -1.0f);
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-2.0f, 0.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.502, 0.502, 0.000); //Verde
	glVertex3f(-3.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 0.0f, -1.0f);
	glVertex3f(-3.0f, 0.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.000, 0.843, 0.000); //Amarillo
	glVertex3f(-5.0f, 4.0f, -1.0f);
	glVertex3f(-3.0f, 4.0f, -1.0f);
	glVertex3f(-3.0f, -1.0f, -1.0f);
	glVertex3f(-5.0f, -1.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.000, 0.843, 0.000); //Amarillo
	glVertex3f(-7.0f, 1.0f, -1.0f);
	glVertex3f(-3.0f, 1.0f, -1.0f);
	glVertex3f(-3.0f, -1.0f, -1.0f);
	glVertex3f(-7.0f, -1.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.000, 0.843, 0.000); //Amarillo
	glVertex3f(-3.0f, 0.0f, -1.0f);
	glVertex3f(0.0f, 0.0f, -1.0f);
	glVertex3f(0.0f, -1.0f, -1.0f);
	glVertex3f(-3.0f, -1.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.000, 0.843, 0.000); //Amarillo
	glVertex3f(-2.0f, 4.0f, -1.0f);
	glVertex3f(-1.0f, 4.0f, -1.0f);
	glVertex3f(-1.0f, 2.0f, -1.0f);
	glVertex3f(-2.0f, 2.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.000, 0.843, 0.000); //Amarillo
	glVertex3f(-1.0f, 3.0f, -1.0f);
	glVertex3f(1.0f, 3.0f, -1.0f);
	glVertex3f(1.0f, 2.0f, -1.0f);
	glVertex3f(-1.0f, 2.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.000, 0.843, 0.000); //Amarillo
	glVertex3f(-1.0f, 2.0f, -1.0f);
	glVertex3f(2.0f, 2.0f, -1.0f);
	glVertex3f(2.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.000, 0.843, 0.000); //Amarillo
	glVertex3f(-3.0f, 2.0f, -1.0f);
	glVertex3f(-2.0f, 2.0f, -1.0f);
	glVertex3f(-2.0f, 1.0f, -1.0f);
	glVertex3f(-3.0f, 1.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.000, 0.843, 0.000); //Amarillo
	glVertex3f(-8.0f, 3.0f, -1.0f);
	glVertex3f(-7.0f, 3.0f, -1.0f);
	glVertex3f(-7.0f, 1.0f, -1.0f);
	glVertex3f(-8.0f, 1.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.000, 0.843, 0.000); //Amarillo
	glVertex3f(-6.0f, 3.0f, -1.0f);
	glVertex3f(-5.0f, 3.0f, -1.0f);
	glVertex3f(-5.0f, 2.0f, -1.0f);
	glVertex3f(-6.0f, 2.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.502, 0.502, 0.000); //Verde
	glVertex3f(-8.0f, -1.0f, -1.0f);
	glVertex3f(-2.0f, -1.0f, -1.0f);
	glVertex3f(-2.0f, -2.0f, -1.0f);
	glVertex3f(-8.0f, -2.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.502, 0.502, 0.000); //Verde
	glVertex3f(-9.0f, -2.0f, -1.0f);
	glVertex3f(1.0f, -2.0f, -1.0f);
	glVertex3f(1.0f, -3.0f, -1.0f);
	glVertex3f(-9.0f, -3.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.502, 0.502, 0.000); //Verde
	glVertex3f(-10.0f, -3.0f, -1.0f);
	glVertex3f(2.0f, -3.0f, -1.0f);
	glVertex3f(2.0f, -4.0f, -1.0f);
	glVertex3f(-10.0f, -4.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.502, 0.502, 0.000); //Verde
	glVertex3f(-10.0f, -4.0f, -1.0f);
	glVertex3f(2.0f, -4.0f, -1.0f);
	glVertex3f(2.0f, -5.0f, -1.0f);
	glVertex3f(-10.0f, -5.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.502, 0.502, 0.000); //Verde
	glVertex3f(-10.0f, -5.0f, -1.0f);
	glVertex3f(2.0f, -5.0f, -1.0f);
	glVertex3f(2.0f, -6.0f, -1.0f);
	glVertex3f(-10.0f, -6.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.502, 0.502, 0.000); //Verde
	glVertex3f(-10.0f, -6.0f, -1.0f);
	glVertex3f(2.0f, -6.0f, -1.0f);
	glVertex3f(2.0f, -7.0f, -1.0f);
	glVertex3f(-10.0f, -7.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.545, 0.000, 0.000); //Rojo
	glVertex3f(-6.0f, -1.0f, -1.0f);
	glVertex3f(-5.0f, -1.0f, -1.0f);
	glVertex3f(-5.0f, -4.0f, -1.0f);
	glVertex3f(-6.0f, -4.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.545, 0.000, 0.000); //Rojo
	glVertex3f(-5.0f, -3.0f, -1.0f);
	glVertex3f(-2.0f, -3.0f, -1.0f);
	glVertex3f(-2.0f, -4.0f, -1.0f);
	glVertex3f(-5.0f, -4.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.545, 0.000, 0.000); //Rojo
	glVertex3f(-3.0f, -2.0f, -1.0f);
	glVertex3f(-2.0f, -2.0f, -1.0f);
	glVertex3f(-2.0f, -3.0f, -1.0f);
	glVertex3f(-3.0f, -3.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.545, 0.000, 0.000); //Rojo
	glVertex3f(-5.0f, -3.0f, -1.0f);
	glVertex3f(-3.0f, -3.0f, -1.0f);
	glVertex3f(-3.0f, -7.0f, -1.0f);
	glVertex3f(-5.0f, -7.0f, -1.0f);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(1.000, 0.843, 0.000); //Rojo
	glVertex3f(-10.0f, -4.0f, -1.0f);
	glVertex3f(-8.0f, -4.0f, -1.0f);
	glVertex3f(-8.0f, -7.0f, -1.0f);
	glVertex3f(-10.0f, -7.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.000, 0.843, 0.000); //Rojo
	glVertex3f(-8.0f, -5.0f, -1.0f);
	glVertex3f(-7.0f, -5.0f, -1.0f);
	glVertex3f(-7.0f, -6.0f, -1.0f);
	glVertex3f(-8.0f, -6.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.545, 0.000, 0.000); //Rojo
	glVertex3f(-8.0f, -7.0f, -1.0f);
	glVertex3f(-5.0f, -7.0f, -1.0f);
	glVertex3f(-5.0f, -8.0f, -1.0f);
	glVertex3f(-8.0f, -8.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.545, 0.000, 0.000); //Rojo
	glVertex3f(-8.0f, -6.0f, -1.0f);
	glVertex3f(-7.0f, -6.0f, -1.0f);
	glVertex3f(-7.0f, -8.0f, -1.0f);
	glVertex3f(-8.0f, -8.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.545, 0.000, 0.000); //Rojo
	glVertex3f(-7.0f, -4.0f, -1.0f);
	glVertex3f(-6.0f, -4.0f, -1.0f);
	glVertex3f(-6.0f, -8.0f, -1.0f);
	glVertex3f(-7.0f, -8.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.545, 0.000, 0.000); //Rojo
	glVertex3f(-7.0f, -5.0f, -1.0f);
	glVertex3f(-1.0f, -5.0f, -1.0f);
	glVertex3f(-1.0f, -7.0f, -1.0f);
	glVertex3f(-7.0f, -7.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.545, 0.000, 0.000); //Rojo
	glVertex3f(-3.0f, -7.0f, -1.0f);
	glVertex3f(0.0f, -7.0f, -1.0f);
	glVertex3f(0.0f, -8.0f, -1.0f);
	glVertex3f(-3.0f, -8.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.545, 0.000, 0.000); //Rojo
	glVertex3f(-1.0f, -6.0f, -1.0f);
	glVertex3f(0.0f, -6.0f, -1.0f);
	glVertex3f(0.0f, -7.0f, -1.0f);
	glVertex3f(-1.0f, -7.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.545, 0.000, 0.000); //Rojo
	glVertex3f(-2.0f, -4.0f, -1.0f);
	glVertex3f(-1.0f, -4.0f, -1.0f);
	glVertex3f(-1.0f, -5.0f, -1.0f);
	glVertex3f(-2.0f, -5.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.000, 0.843, 0.000); //amarillo
	glVertex3f(0.0f, -4.0f, -1.0f);
	glVertex3f(2.0f, -4.0f, -1.0f);
	glVertex3f(2.0f, -7.0f, -1.0f);
	glVertex3f(0.0f, -7.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.000, 0.843, 0.000); //amarillo
	glVertex3f(-1.0f, -5.0f, -1.0f);
	glVertex3f(0.0f, -5.0f, -1.0f);
	glVertex3f(0.0f, -6.0f, -1.0f);
	glVertex3f(-1.0f, -6.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.000, 0.843, 0.000); //amarillo
	glVertex3f(-6.0f, -4.0f, -1.0f);
	glVertex3f(-5.0f, -4.0f, -1.0f);
	glVertex3f(-5.0f, -5.0f, -1.0f);
	glVertex3f(-6.0f, -5.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.000, 0.843, 0.000); //amarillo
	glVertex3f(-3.0f, -4.0f, -1.0f);
	glVertex3f(-2.0f, -4.0f, -1.0f);
	glVertex3f(-2.0f, -5.0f, -1.0f);
	glVertex3f(-3.0f, -5.0f, -1.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.502, 0.502, 0.000); //verde
	glVertex3f(-9.0f, -9.0f, -1.0f);
	glVertex3f(-9.0f, -8.0f, -1.0f);
	glVertex3f(-6.0f, -8.0f, -1.0f);
	glVertex3f(-6.0f, -10.0f, -1.0f);
	glVertex3f(-10.0f, -10.0f, -1.0f);
	glVertex3f(-10.0f, -9.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.502, 0.502, 0.000); //verde
	glVertex3f(-2.0f, -8.0f, -1.0f);
	glVertex3f(1.0f, -8.0f, -1.0f);
	glVertex3f(1.0f, -9.0f, -1.0f);
	glVertex3f(-2.0f, -9.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.502, 0.502, 0.000); //verde
	glVertex3f(-2.0f, -9.0f, -1.0f);
	glVertex3f(2.0f, -9.0f, -1.0f);
	glVertex3f(2.0f, -10.0f, -1.0f);
	glVertex3f(-2.0f, -10.0f, -1.0f);
	glEnd();

	/*Ciclo para generar las lineas verticales*/
	for (i = -10; i <= 3; i++) {
		glBegin(GL_LINES);
		glColor3f(0.000, 0.000, 0.000); //Negro
		glVertex3f(i, 6.0f, -1.0f);
		glVertex3f(i, -11.0f, -1.0f);
		glEnd();

	}

	/*Ciclo para generar las lineas horizontales*/
	for (i = -11; i <= 6; i++) {
		glBegin(GL_LINES);
		glColor3f(0.000, 0.000, 0.000); //Negro
		glVertex3f(-11, i, -1.0f);
		glVertex3f(3, i, -1.0f);
		glEnd();

	}

	glFlush();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Ortogonal
	glOrtho(-10, 10, -10, 10, 0.1, 2);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: exit(0);
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 2"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutMainLoop();          // 

	return 0;
}


