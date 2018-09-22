//Semestre 2019 - 1
//**************************************************************************//
//*************************************************************************//
//************** Alumno (s): Salazar Santiago Juan Carlos*****************//
//*************	Ejercicio de casa 4: Robot con brazos que se mueven   ***//
//*************	Fecha: 24/09/2018 						          ******//
//*********************************************************************//
#include "Main.h"

float transZ = -5.0f;
float transY = 0.0f;
float transX = 0.0f;
/* Inicialmente una rotacion de cero grados*/
float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float angHombro = 0.0f;
float angAnte = 0.0f;
int screenW = 0.0;
int screenH = 0.0;


/*
		Para mover los brazos con la tecla H o h para adelante o atras respectivamente.

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

	//glScalef(scaleX, scaleY, 1);

	glBegin(GL_POLYGON);	//Front
	//glScalef(scaleX, scaleY, 1);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	//glScalef(scaleX, scaleY, 1);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	//glScalef(scaleX, scaleY, 1);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	//glScalef(scaleX, scaleY, 1);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	//glScalef(scaleX, scaleY, 1);
	glColor3f(0.4, 0.2, 0.6);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	//glScalef(scaleX, scaleY, 1);
	glColor3f(0.8, 0.2, 0.4);
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

	//glTranslatef(transX, transY, transZ);
	//Poner Código Aquí.
	/*Se dibujan las partes de la figura*/
	//glRotatef(angleX, 1, 0, 0);
	//glRotatef(angleY, 0, 1, 0);
	//glRotatef(angleZ, 0, 0, 1);

	glTranslatef(transX, 0.0f, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);


	glPushMatrix(); //Torso

	glTranslated(0, 3, 0);
	glScalef(18.0f, 8.0f, 1.0f);
	prisma();
	glPopMatrix();

	glPushMatrix(); //Cuello
	glTranslated(1, 9, 0);
	glScalef(6.0f, 4.0f, 1.0f);
	prisma();
	glPopMatrix();


	glPushMatrix(); //Cabeza
	glTranslatef(0, 13, 0);
	glScalef(18.0f, 6.0f, 1.0f);
	prisma();
	glPopMatrix();

	glPushMatrix(); //Oreja izquierda
	glTranslatef(-10, 13, 0);
	glScalef(4.0f, 2.0f, 1.0f);
	prisma();
	glPopMatrix();

	glPushMatrix(); //Oreja derecha
	glTranslatef(11, 13, 0);
	glScalef(4.0f, 2.0f, 1.0f);
	prisma();
	glPopMatrix();

	glPushMatrix(); //Pierna izquierda
	glTranslatef(-4.0f, -5.0f, 0);
	glScalef(4.0f, 8.0f, 1.0f);
	prisma();
	glPopMatrix();

	glPushMatrix(); //Pierna derecha
	glTranslatef(6.0f, -5.0f, 0);
	glScalef(4.0f, 8.0f, 1.0f);
	prisma();
	glPopMatrix();

	glPushMatrix(); //Pie izquierdo
	glTranslatef(-4.0f, -10.0f, 0);
	glScalef(8.0f, 2.0f, 1.0f);
	prisma();
	glPopMatrix();

	glPushMatrix(); //Pie derecho
	glTranslatef(6.0f, -10.0f, 0);
	glScalef(8.0f, 2.0f, 1.0f);
	prisma();
	glPopMatrix();

	/* Ante brazo*/
	glPushMatrix();

	glTranslatef(-8, 4, 0); //Antebrazo izquierdo 
	glRotatef(angHombro, 0, 1, 0);
	glPushMatrix();
	glTranslatef(-3.0, 0, 0); //
	glScalef(6, 4, 1.0f);
	prisma();
	glPopMatrix();

	//Antebrazo 2 izquierdp
	glTranslatef(-6, 0, 0);
	glRotatef(angHombro, 0, 1, 0);
	glPushMatrix();
	glTranslatef(-3.0, 0, 0); //
	glScalef(6, 4, 1.0f);
	prisma();
	glPopMatrix();

	//pinza uno izquierda

	glTranslatef(-6, 1, 0);
	glRotatef(angHombro, 0, 1, 0);
	glPushMatrix();
	glTranslatef(-1.45, 0, 0); //
	glScalef(3, 2, 1.0f);
	prisma();
	glPopMatrix();

	//pinza dos izquierda

	glTranslatef(-3.02, 0, 0);
	glRotatef(angHombro, 0, 1, 0);
	glPushMatrix();
	glTranslatef(-1.4, 0, 0); //
	glScalef(3, 2, 1.0f);
	prisma();
	glPopMatrix();


	//pinza una abajo
	glTranslatef(0, -2.14, 0);
	glRotatef(angHombro, 0, 1, 0);
	glPushMatrix();
	glTranslatef(-1.5, 0, 0); //
	glScalef(3, 2, 1.0f);
	prisma();
	glPopMatrix();

	//pinza dos abajo
	glTranslatef(3, 0, 0);
	glRotatef(angHombro, 0, 1, 0);
	glPushMatrix();
	glTranslatef(-1.5, 0, 0); //
	glScalef(3, 2, 1.0f);
	prisma();
	glPopMatrix();


	glPopMatrix();
	angAnte = -angHombro;

	glPushMatrix();
	glTranslatef(10, 4, 0);
	glRotatef(angAnte, 0, 1, 0);
	glPushMatrix();
	glTranslatef(2, 0, 0); //
	glScalef(6, 4, 1.0f);
	prisma();
	glPopMatrix();

	glTranslatef(5.3, 0, 0);
	glRotatef(angAnte, 0, 1, 0);
	glPushMatrix();
	glTranslatef(3, 0, 0); //
				glScalef(6, 4, 1.0f);
				prisma();
			glPopMatrix();

	glTranslatef(6, 1, 0); //PINZA 2 DERECHA ARRIBA -IZQUIERDA
	glRotatef(angAnte, 0, 1, 0);
		glPushMatrix();
			glTranslatef(1.5, 0, 0); //
			glScalef(3, 2, 1.0f);
			prisma();
		glPopMatrix();

	glTranslatef(3, 0, 0); //PINZA 2 DERECHA ARRIBA -DERECHA
	glRotatef(angAnte, 0, 1, 0);
		glPushMatrix();
			glTranslatef(1.5, 0, 0); //
			glScalef(3, 2, 1.0f);
			prisma();
		glPopMatrix();

	glTranslatef(0, -2.25, 0); //PINZA 2 DERECHA ABAJO -DERECHA
	glRotatef(angAnte, 0, 1, 0);
		glPushMatrix();
			glTranslatef(1.5, 0, 0.0); //
			glScalef(3, 2, 1.0f);
			prisma();
		glPopMatrix();
	
glTranslatef(-3, 0, 0); //PINZA 2 DERECHA ABAJO -DERECHA
	glRotatef(angAnte, 0, 1, 0);
		glPushMatrix();
			glTranslatef(1.5, 0, 0.0); //
			glScalef(3, 2, 1.0f);
			prisma();
		glPopMatrix();

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
	case 'w':
	case 'W':
		transZ += 0.2f;
		break;
	case 's':
	case 'S':
		transZ -= 0.2f;
		break;
	case 'a':
	case 'A':
		transX += 0.2f;
		break;
	case 'd':
	case 'D':
		transX -= 0.2f;
		break;
	case 'H':
		if (angHombro < 90) {
			angHombro += 2.0f;

		}
		break;
	case 'h':
		if (angHombro > 0)
			angHombro -= 2.0f;
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
	case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX += 2.0f;
		break;
	case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -= 2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY += 2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 2.0f;
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
	glutCreateWindow("Ejercicio 4"); // Nombre de la Ventana
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
