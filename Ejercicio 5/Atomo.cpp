// Semestre 2019 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): Salazar Santiago Juan Carlos ****//
//*************	 Visual Studio 2017						  ****//
//*************	 Ejercicio de casa 5: Atomo				 ****//
//*************  Fecha: 01/10/2018                       ****//
//************************************************************//
#include "Main.h"


/* Para ver desde arriba con la tecla de arriba en el teclado y para abajo con la tecla de abajo.
	Para alejarse con la tecla s o S y para acercarse con la tecla w o W
*/


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int centro = 0;
float camaraZ = 0.0;
float camaraX = 0.0;
/* Variable para el movimiento de los electrones*/
float posicion = 0.0f;
float angleX = 0.0f; //Para rotar la vista en el eje X

GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara

	glPushMatrix(); //Sistema de atomo
	
	glRotatef(angleX, 1, 0, 0);
	//El Sol gira sobre su eje GIRAR todos

		glPushMatrix(); //Protones
			glRotatef(centro, 0, 1, 0);
			glColor3f(0.8, 0.0, 0.0);	
			glTranslatef(-1.0,0.0,0.0); //Proton 1
			glutSolidSphere(1.0, 20, 200); 
			glTranslatef(2.0,0.0,0.0);
			glutSolidSphere(1.0, 200, 200); //Proton 2
		glPopMatrix();

		glPushMatrix(); //Neutrones
			glRotatef(centro, 1, 0, 0);
			glColor3f(0.2, 0.4, 0.8);
			glTranslatef(0, 1.77, 0.0); //Neutron 1
			glutSolidSphere(1.0, 20, 20);
			glTranslatef(0.0, -3.5, 0.0);
			glutSolidSphere(1.0, 200, 200); //Neutron 2
		glPopMatrix();


	
	/*Electrones*/

	/*Rotacion sobre el eje X*/
	glPushMatrix();
		glRotatef(posicion, 1, 0, 0); //traslacion
		glTranslatef(0, 4.0, 0); //centro
		glColor3d(0.1, 0.3, 0.0); //Color verde
		glutSolidSphere(1.0, 500, 500);
	glPopMatrix();

	/*Rotacion sobre el eje Y*/
	glPushMatrix();
		glRotatef(posicion, 0, 1, 0); //traslacion
		glTranslatef(7, 0, 0); //centro
		glColor3d(0.1, 0.3, 0.0); //Color verde
		glutSolidSphere(1.0, 500, 500);
	glPopMatrix();


	/*Sobre el eje Z*/
	glPushMatrix();
			glRotatef(posicion, 0, 0, 1);//traslacion 
			glTranslatef(10, 0, 0); //centro
			glColor3d(0.1, 0.3, 0.0); //Color verde
			glutSolidSphere(1.0, 500, 500);
	glPopMatrix();

	/*Rotacion inclinada*/
	
	glPushMatrix();
		glRotatef(posicion, -1, -1, 0);//traslacion 
		glTranslatef(-8.19, 10.09, 0); //centro
		glColor3d(0.1, 0.3, 0.0); //Color verde
		glutSolidSphere(1.0, 500, 500);
	glPopMatrix();



	/*Rotacion inclinada 2*/

	glPushMatrix();
		glRotatef(posicion, 1, -1, 0); //traslacion 
		glTranslatef(10.7, 11.89, 0); //centro
		glColor3d(0.1, 0.3, 0.0); //Color verde
		glutSolidSphere(1.0, 500, 500);
	glPopMatrix();
	

	glPopMatrix(); //Fin atomo

	glutSwapBuffers();

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 50)
	{
		centro = (centro - 1) % 360; //Define movimiento del centro del atomo
		posicion = fmod(posicion - 5.5, 360); //Movimiento para los electrones

		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
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

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
														//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		camaraZ += 0.5f;
		break;
	case 's':
	case 'S':
		camaraZ -= 0.5f;
		break;
	case 'a':
	case 'A':
		camaraX -= 0.5f;
		break;
	case 'd':
	case 'D':
		camaraX += 0.5f;
		break;

	case 'i':		//Movimientos de Luz
	case 'I':

		break;
	case 'k':
	case 'K':

		break;

	case 'l':   //Activamos/desactivamos luz
	case 'L':
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
	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angleX += 1.5;    //Mueve la camara hacia arriba
		break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angleX -= 1.5f;		//Mueve la camara hacia abajo
		break;
	case GLUT_KEY_LEFT:

		break;
	case GLUT_KEY_RIGHT:

		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(20, 60);	//Posicion de la Ventana
	glutCreateWindow("Casa 5"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}