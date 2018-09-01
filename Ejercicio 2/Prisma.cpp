//Semestre 2019 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): Salazar Santiago Juan Carlos*****//
//*************	Ejercicio de casa 3: Creacion de un prisma***//
//*************	Fecha: 01/09/2018						******//
//************************************************************//

//#include <gl/gl.h>     // The GL Header File
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
//#include <stdlib.h>
#include "Main.h"
/* 
					LA FUNCION PRISMA ESTA POR LA LINEA 120
					COMO PARAMETRO ACEPTA UN VALOR FLOTANTE POSITIVO
					
*/

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = -10.0f;


void InitGL(GLvoid)     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
														//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
														//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}
void prisma(float x)
{
	/* Cambiamos los elementos de la matriz para que sea un prisma con lados iguales y tenga la misma distancia
	del eje z positivo al eje z negativo ademas su posicion estara en el centro */
	GLfloat vertice[8][3] = {
				{x ,-x, x},    //Coordenadas Vértice 0 V0
				{-x ,-x, x},    //Coordenadas Vértice 1 V1
				{-x ,-x, -x},    //Coordenadas Vértice 2 V2
				{x ,-x, -x},    //Coordenadas Vértice 3 V3
				{x ,x, x},    //Coordenadas Vértice 4 V4
				{x ,x, -x},    //Coordenadas Vértice 5 V5
				{-x ,x, -x},    //Coordenadas Vértice 6 V6
				{-x ,x,x},    //Coordenadas Vértice 7 V7
	};


	glBegin(GL_POLYGON);	//Cara frontal
	glColor3f(0.545, 0.000, 0.000); //Color rojo
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Cara derecha
	glColor3f(1.000, 1.000, 0.000); //Color amarillo
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Cara de atras
	glColor3f(0.294, 0.000, 0.510); //Color indigo
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Cara izquierda
	glColor3f(0.000, 0.392, 0.000); //Color verde
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Cara de abajo

	glColor3f(0.000, 0.502, 0.502); //Color teal
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Cara de arriba
	glColor3f(0.000, 0.000, 1.000); //Color azul
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}



void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Poner Código Aquí.
	/*Para la respectiva traslacion de las figuras*/
	glTranslatef(transX, transY, transZ);
	/*Para indicar la posicion del prisma*/
	glTranslatef(0, 0, 0);

	/* Se crea primer un prisma y a partir del valor 50 ya no es posible verlo y con un valor de 0.1 se aprecia
	Insertamos un valor y se crea un prisma con todos los lados iguales, el parametro debe ser positivo*/
	prisma(1.7);
	glutSwapBuffers();
	glFlush();
	// Swap The Buffers
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

	// Tipo de Vista
	//glOrtho(-5, 5, -5, 5, 0.1, 20);
	//glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);
	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':
	case 'W':
		/* Aumenta la vision del eje Z*/
		transZ += 0.2f;
		printf("Posicion en Z: %f\n", transZ);
		break;
	case 's':
	case 'S':
		/*Aleja la vision del eje Z*/
		transZ -= 0.2f;
		printf("Posicion en Z: %f\n", transZ);
		break;
	case 'a':
	case 'A':
		/*Lo mueve hacia la izquierda*/
		transX -= 0.2f;
		break;
	case 'b':
	case 'B':
		/*Lo mueve hacia la derecha*/
		transX += 0.2f;
		break;
	case 'r':
	case 'R':
		/*Lo mueve hacia arriba*/
		transY += 0.2f;
		break;
	case 't':
		/*Lo mueve hacia abajo*/
		transY -= 0.2f;
		break;
	case 'y':
	case 'Y':
		/*Lo mueve hacia arriba*/
		transY += 0.2f;
		break;
	case 'Z':
	case 'z':
		/*Rota de arriba hacia abajo*/
		angleX += 0.5;
		break;
	case 'O':
	case 'o':
		/*Rota de abajo hacia arriba*/
		angleX -= 0.5;
		break;
		/*
		case 'P':
		case 'p':
			angleY += 0.5;
			break;
		case 'K':
		case 'k':
			angleY -= 0.5;
			break;
		case 'L':
		case 'l':
			angleZ += 0.5;
			break;
		case 'J':
		case 'j':
			angleZ -= 0.5;
			break;
		*/
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angleX += 1.0f;
		break;
		//glutFullScreen ( ); // Full Screen Mode
		//break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angleX -= 1.0f;
		break;
		//glutReshapeWindow ( 500, 500 ); // Cambiamos tamano de Ventana
		//break;
	case GLUT_KEY_LEFT:
		angleY += 1.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 1.0f;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
						   //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 3"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutMainLoop();          // 

	return 0;
}
