//Semestre 2019 - 1
//**************************************************************************//
//*************************************************************************//
//************** Alumno (s): Salazar Santiago Juan Carlos*****************//
//*************	Ejercicio de casa 4: Figura animal con prismas     ******//
//*************	Fecha: 14/09/2018 						          ******//
//*********************************************************************//
#include "Main.h"

float transZ = -5.0f;
float transY = 0.0f;
float transX = 0.0f;
/* Inicialmente una rotacion de cero grados*/
float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;

int screenW = 0.0;
int screenH = 0.0;


/*
		Para trasladar hacia la izquierda con la tecla de flecha hacia la izquierda <-
		Para trasladar hacia la derecha con la tecla de flecha hacia la derecha ->
		Para trasladar hacia arriba con la tecla de flecha hacia arriba
		Para trasladar hacia abajo con la tecla de flecha hacia la abajo
		Para trasladar hacia enfrente con la tecla w o W
		Para trasladar hacia atras con la tecla s o S
		Para rotar en el eje X con la tecla x o X (+) o a o A (-)
		Para rotar en el eje Y con la tecla y o Y (+) o b o B (-)
		Para rotar en el eje Z con la tecla z o Z (+) o c o C (-)
*/

void InitGL(void)     // Inicializamos parametros
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

void prisma(/*float scaleX , float scaleY*/)
{
	GLfloat vertice[8][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0
		{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1
		{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2
		{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3
		{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V4
		{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V5
		{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V6
		{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V7
	};

	//Se dibuja un elefante

	glBegin(GL_POLYGON);	//Front
	//glScalef(scaleX, scaleY, 1);
	glColor3f(0.412, 0.412, 0.412);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	//glScalef(scaleX, scaleY, 1);
	glColor3f(0.827, 0.827, 0.827); //Color gris oscuro
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	//glScalef(scaleX, scaleY, 1);
	glColor3f(0.827, 0.827, 0.827); //Color gris
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	//glScalef(scaleX, scaleY, 1);
	glColor3f(0.827, 0.827, 0.827);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	//glScalef(scaleX, scaleY, 1);
	glColor3f(0.827, 0.827, 0.827);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	//glScalef(scaleX, scaleY, 1);
	glColor3f(0.827, 0.827, 0.827);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
														//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, transY, transZ);
	//Poner Código Aquí.
	/*Se dibujan las partes de la figura*/
	glRotatef(angleX, 1, 0, 0);
	glRotatef(angleY, 0, 1, 0);
	glRotatef(angleZ, 0, 0, 1);


	glPushMatrix(); //Panza
	glTranslatef(0.0f, -1.5, 0);
	glScalef(6.0f, 3.0f, 3.0f);
	prisma();
	glPopMatrix();

	glPushMatrix(); //Panza
	glTranslatef(0.5, 1.0f, 0);
	glScalef(5.0f, 2.0f, 3.0f);
	prisma();
	glPopMatrix();

	glPushMatrix(); //Cabeza
	glTranslatef(-3.5, 2.5, 0);
	glScalef(3.0f, 5.0f, 3.0f);
	prisma();
	glPopMatrix();

	glPushMatrix(); //Trompa
	glTranslatef(-4.5, -2.5, 1.0f);
	glScalef(1.0f, 5.0f, 1.0f);
	prisma();
	glPopMatrix();

	glPushMatrix(); //Pata izquierda
	glTranslatef(-2.5, -5.5, 1.0f);
	glScalef(1.0f, 5.0f, 1.0f);
	prisma();
	glPopMatrix();

	glPushMatrix(); //Pata derecha
	glTranslatef(2.5f, -5.5, 1.0f);
	glScalef(1.0f, 5.0f, 1.0f);
	prisma();
	glPopMatrix();

	//Patas de atras
	glPushMatrix(); //Pata izquierda
	glTranslatef(-2.5, -5.5, -1.0f);
	glScalef(1.0f, 5.0f, 1.0f);
	prisma();
	glPopMatrix();

	glPushMatrix(); //Pata derecha
	glTranslatef(2.5f, -5.5, -1.0f);
	glScalef(1.0f, 5.0f, 1.0f);
	prisma();
	glPopMatrix();

	//////////////////////////////////

	glPushMatrix(); //Cola
	glTranslatef(4.5, -0.5, 0.0f);
	glScalef(3.0f, 1.0f, 1.0f);
	prisma();
	glPopMatrix();

	glPushMatrix(); //Cola otra
	glTranslatef(5.5, -1.5, 0.0f);
	prisma();
	glPopMatrix();

	glPushMatrix(); //Trompa
	glTranslatef(-6.0f, -4.5, 1.0f);
	glScalef(2.0f, 1.0f, 1.0f);
	prisma();
	glPopMatrix();

	glutSwapBuffers();
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
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum(-0.8, 0.8, -0.8, 0.8, 0.3, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
		//Trasladar en el eje Z (+)
	case 'w':
	case 'W':
		transZ += 0.3f;
		break;
		//Trasladar en el eje Z (-)
	case 's':
	case 'S':
		transZ -= 0.3f;
		break;
		//Rotar en el eje X (+)
	case 'x':
	case 'X':
		angleX += 0.5f;
		break;
		//Rotar en el eje Y (+)
	case 'y':
	case 'Y':
		angleY += 0.5f;
		break;
		//Rotar en el eje Z (+)
	case 'z':
	case 'Z':
		angleZ += 0.5f;
		break;
		//Rotar en el eje X (-)
	case 'a':
	case 'A':
		angleX -= 0.5f;
		break;
		//Rotar en el eje Y (-)
	case 'b':
	case 'B':
		angleY -= 0.5f;
		break;
		//Rotar en el eje Z (-)
	case 'c':
	case 'C':
		angleZ -= 0.5f;
		break;
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
	case GLUT_KEY_UP:
		transY += 0.3f;		// Trasladar hacia arriba
		break;
	case GLUT_KEY_DOWN:	// Trasladar hacia abajo
		transY -= 0.3f;
		break;
	case GLUT_KEY_LEFT:	// Trasladar hacia la izquierda
		transX -= 0.3f;
		break;
	case GLUT_KEY_RIGHT:	// Trasladar hacia la derecha
		transX += 0.3f;
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
	screenW = glutGet(GLUT_SCREEN_WIDTH);
	screenH = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 4"); // Nombre de la Ventana
	printf("Resolution H: %i \n", screenW);
	printf("Resolution V: %i \n", screenH);
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutMainLoop();          // 

	return 0;
}