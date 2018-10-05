// Semestre 2019 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): Salazar Santiago Juan Carlos ****//
//*************	 Visual Studio 2017						  ****//
//*************	 Ejercicio de casa 6: Sistema solar completo *//
//*************  con materiales y fuente de iluminacion  *****//
//*************  Fecha: 8/10/2018                        ****//
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

int sol = 0;

float camaraZ = 0.0;
float camaraX = 0.0;
/* Arreglo para las variables de los planetas*/
float posicion[8] = { 0.0f };
/*Arreglo para las lunas*/
float lunas[5] = { 0.0 };
float angleX = 0.0f; //Para rotar la vista en el eje X


GLfloat LuzAmbientalSol[] = { 0.5, 0.5, 0.5, 1.0 };			// Diffuse Light Values
GLfloat LuzDifusaSol[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat LuzEspecularSol[] = { 1.0, 1.0, 1.0, 1.0 };			// Light Position
GLfloat LuzPosicionSol[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Diffuse Light Values

/*Mercurio*/
GLfloat MercurioAmbiente[] = { 0.0f,0.1f,0.06f,1.0f };
GLfloat MercurioDifuso[] = { 1.0f,0.509804f,0.509804f,1.0f };
GLfloat MercurioEspecular[] = { 0.501961f,0.501961f,1.0f,1.0f };
GLfloat MarsShininess[] = { 32.0 };


/*Venus*/

GLfloat VenusAmbiente[] = { 0.19125f,0.0735f,0.0225f,1.0f };
GLfloat VenusDifuso[] = { 0.7038f,0.27048f,0.0828f,1.0f };
GLfloat VenusEspecular[] = { 0.256777f,0.137622f,0.086014f,1.0f };
GLfloat VenusShininess[] = { 12.8 };

/*Tierra*/

GLfloat TierraAmbiente[] = { 0.0f,0.0f,0.74f,1.0f };
GLfloat TierraDifuso[] = { 0.35f,0.53f,0.82f,1.0f };
GLfloat TierraEspecular[] = { 0.0f,0.75f,1.0f,1.0f };
GLfloat TierraShininess[] = { 10.0 };

/*Luna*/
GLfloat LunaAmbiente[] = { 0.19225f,0.19225f,0.19225f,1.0f };
GLfloat LunaDifuso[] = { 0.50754f,0.50754f,0.50754f,1.0f };
GLfloat LunaEspecular[] = { 0.508273f,0.508273f,0.508273f,1.0f };
GLfloat LunaShininess[] = { 51.2 };

/*Marte*/
GLfloat MarteAmbiente[] = { 0.33f,0.0f,0.0f,1.0f };
GLfloat MarteDifuso[] = { 0.87f,0.0f,0.0f,1.0f };
GLfloat MarteEspecular[] = { 1.0f,0.82,0.75f,1.0f };
GLfloat MarteShininess[] = { 18.0 };

/*Jupiter*/
GLfloat JupiterAmbiente[] = { 0.54f,0.34f,0.27f,1.0f };
GLfloat JupiterDifuso[] = { 0.76f,0.66f,0.3f,1.0f };
GLfloat JupiterEspecular[] = { 0.2f,0.2f,0.4f,1.0f };
GLfloat JupiterShininess[] = { 10.0 };

/*Saturno*/
GLfloat SaturnoAmbiente[] = { 1.0f,0.54f,0.29f,1.0f };
GLfloat SaturnoDifuso[] = { 0.73f,0.73f,0.24f,1.0f };
GLfloat SaturnoEspecular[] = { 0.51f,0.44f,0.56f,1.0f };
GLfloat SaturnoShininess[] = { 10.0 };

/*Anillo*/
GLfloat AnilloAmbiente[] = { 0.19225f,0.19225f,0.19225f,1.0f };
GLfloat AnilloDifuso[] = { 0.50754f,0.50754f,0.50754f,1.0f };
GLfloat AnilloEspecular[] = { 0.508273f,0.508273f,0.508273f,1.0 };
GLfloat AnilloShininess[] = { 51.2 };

/*Urano*/
GLfloat UranoAmbiente[] = { 0.48f,0.67f,0.97f,1.0f };
GLfloat UranoDifuso[] = { 0.61f,0.87f,1.0f,1.0f };
GLfloat UranoEspecular[] = { 0.63f,0.33f,0.61f,1.0f };
GLfloat UranoShininess[] = { 9.0 };

/*Neptuno*/
GLfloat NeptunoAmbiente[] = { 0.0f,1.0f,1.0f,1.0f };
GLfloat NeptunoDifuso[] = { 1.0f,1.0f,1.0f,1.0f };
GLfloat NeptunoEspecular[] = { 0.53f,0.48f,0.34f,1.0f };
GLfloat NeptunoShininess[] = { 54.0 };

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


	glLightfv(GL_LIGHT0, GL_AMBIENT, LuzAmbientalSol);				// Setup The Ambient Light
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LuzDifusaSol);				// Setup The Diffuse Light
	glLightfv(GL_LIGHT0, GL_SPECULAR, LuzEspecularSol);				// Setup The Diffuse Light
	//glLightfv(GL_LIGHT1, GL_POSITION, LuzPosicionSol);															//glLightfv(GL_LIGHT1, GL_POSITION,LightPosition);			// Position The Light
																	//glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION,LightDirection);			// Direction Of The Light
																	//glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);							// Enable Light One							//glEnable(GL_LIGHT0);


}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara

	glLightfv(GL_LIGHT0, GL_POSITION, LuzPosicionSol);
	glEnable(GL_LIGHTING);


	glPushMatrix(); //Sistema solar
	glRotatef(angleX, 1, 0, 0);
	glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje GIRAR todos

	glPushMatrix(); //Sol
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
	glutSolidSphere(2.0, 200, 200);  //Draw Sun (radio,H,V);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	/*Mercurio*/
	glPushMatrix();
	glRotatef(posicion[0], 0, 1, 0); //traslacion
	glTranslatef(3.5, 0, 0);
	glRotatef(posicion[0], 0, 1, 0); //rotacion
	/*Materiales */ /*Color cyan plastico*/
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, MercurioAmbiente);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MercurioDifuso);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MercurioEspecular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, MarsShininess);
	glutSolidSphere(0.3, 500, 500); //Esfera
	glPopMatrix();


	/*Venus*/

	glPushMatrix();
	glRotatef(-posicion[1], 0, 1, 0); //traslacion
	glTranslatef(5, 0, 0);
	glRotatef(posicion[1], 0, 1, 0); //rotacion
	/*Materiales */ /*Color cooper*/
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, VenusAmbiente);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, VenusDifuso);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, VenusEspecular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, VenusShininess);
	glutSolidSphere(0.5, 500, 500);
	glPopMatrix();


	/*Tierra*/
	glPushMatrix();
	glRotatef(posicion[2], 0, 1, 0); //traslacion
	glTranslatef(7.5, 0, 0);
	glRotatef(posicion[2], 0, 1, 0); //rotacion
	//color azul
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, TierraAmbiente);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, TierraDifuso);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, TierraEspecular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, TierraShininess);
	glutSolidSphere(0.7, 500, 500);
	/*Luna*/
	glPushMatrix();
	glRotatef(lunas[0], 0, 1, 0); //traslacion
	glTranslatef(1.0, 0, 0);
	glRotatef(lunas[0], 0, 1, 0); //rotacion
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, LunaAmbiente);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, LunaDifuso);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, LunaEspecular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, LunaShininess);
	glutSolidSphere(0.2, 500, 500); //Esfera
	glPopMatrix();
	glPopMatrix();

	/*Marte*/
	glPushMatrix();
	glRotatef(-posicion[3], 0, 1, 0); //traslacion
	glTranslatef(10.5, 0, 0);
	glRotatef(posicion[3], 0, 1, 0); //rotacion
	//Color rojo
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, MarteAmbiente);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MarteDifuso);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MarteEspecular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, MarteShininess);
	glutSolidSphere(0.4, 500, 500);

	/*Luna 1*/
	glPushMatrix();
	glRotatef(lunas[1], 0, 1, 0); //traslacion
	glTranslatef(0.6, 0, 0);
	glRotatef(lunas[1], 0, 1, 0); //rotacion
	//color gris
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, LunaAmbiente);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, LunaDifuso);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, LunaEspecular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, LunaShininess);

	glutSolidSphere(0.2, 500, 500);
	glPopMatrix();
	/*Luna 2*/
	glPushMatrix();
	glRotatef(-lunas[2], 0, 1, 0); //traslacion
	glTranslatef(1.0, 0, 0);
	glRotatef(lunas[2], 0, 1, 0); //rotacion
	//color gris
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, LunaAmbiente);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, LunaDifuso);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, LunaEspecular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, LunaShininess);
	glutSolidSphere(0.2, 500, 500);
	glPopMatrix();
	glPopMatrix();

	/*Jupiter*/

	glPushMatrix();
	glRotatef(posicion[4], 0, 1, 0); //traslacion
	glTranslatef(15.2, 0, 0);
	glRotatef(posicion[4], 0, 1, 0); //rotacion
	//color beige
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, JupiterAmbiente);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, JupiterDifuso);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, JupiterEspecular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, JupiterShininess);
	glutSolidSphere(1.0, 500, 500);

	/*Luna 1*/
	glPushMatrix();
	glRotatef(lunas[3], 0, 1, 0); //traslacion
	glTranslatef(1.4, 0, 0);
	glRotatef(lunas[3], 0, 1, 0); //rotacion
	//color gris
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, LunaAmbiente);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, LunaDifuso);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, LunaEspecular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, LunaShininess);
	glutSolidSphere(0.3, 500, 500);
	glPopMatrix();

	/*Luna 2*/
	glPushMatrix();
	glRotatef(-lunas[3], 0, 1, 0); //traslacion
	glTranslatef(2.05, 0, 0);
	glRotatef(lunas[3], 0, 1, 0); //rotacion
	//color gris
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, LunaAmbiente);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, LunaDifuso);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, LunaEspecular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, LunaShininess);
	glutSolidSphere(0.2, 500, 500);
	glPopMatrix();

	/*Luna 3*/
	glPushMatrix();
	glRotatef(lunas[4], 0, 1, 0); //traslacion
	glTranslatef(2.8, 0, 0);
	glRotatef(lunas[4], 0, 1, 0); //rotacion
	//color gris
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, LunaAmbiente);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, LunaDifuso);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, LunaEspecular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, LunaShininess);
	glutSolidSphere(0.4, 500, 500);
	glPopMatrix();
	glPopMatrix();

	/*Saturno*/
	glPushMatrix();
	glRotatef(-posicion[5], 0, 1, 0); //traslacion
	glTranslatef(23.5, 0, 0);
	glRotatef(posicion[5], 0, 1, 0); //rotacion
	//Color amarillo palido
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, SaturnoAmbiente);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, SaturnoDifuso);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, SaturnoEspecular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, SaturnoShininess);
	glutSolidSphere(0.85, 500, 500);

	/*Anillo 1*/
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	//color gris
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,AnilloAmbiente );
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, AnilloDifuso);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, AnilloEspecular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, AnilloShininess);
	glutSolidTorus(0.5, 2.0, 30, 30);
	glPopMatrix();

	/*Anillo 2*/
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	//color gris
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, AnilloAmbiente);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, AnilloDifuso);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, AnilloEspecular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, AnilloShininess);
	glutSolidTorus(0.5, 3.5, 30, 30);
	glPopMatrix();
	glPopMatrix();

	/*Urano*/
	glPushMatrix();
	glRotatef(posicion[6], 0, 1, 0); //traslacion
	glTranslatef(30.0, 0, 0);
	glRotatef(posicion[6], 0, 1, 0); //rotacion
	//color azul
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, UranoAmbiente);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, UranoDifuso);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, UranoEspecular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, UranoShininess);
	glutSolidSphere(0.8, 500, 500);
	glPopMatrix();

	/*Neptuno*/

	glPushMatrix();
	glRotatef(-posicion[7], 0, 1, 0); //traslacion
	glTranslatef(34.0, 0, 0);
	glRotatef(posicion[7], 0, 1, 0); //rotacion
	//color azul
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, NeptunoAmbiente);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, NeptunoDifuso);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, NeptunoEspecular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, NeptunoShininess);
	glutSolidSphere(0.7, 500, 500);
	glPopMatrix();

	glPopMatrix(); //Fin sistema solar

	glutSwapBuffers();

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 70)
	{
		sol = (sol - 1) % 360; //Define movimiento
		posicion[0] = fmod(posicion[0] - 8.5, 360); //Mercurio
		posicion[1] = fmod(posicion[1] - 7.5, 360); //Venus
		posicion[2] = fmod(posicion[2] - 6.5, 360); //Tierra
		posicion[3] = fmod(posicion[3] - 5.5, 360); //Marte
		posicion[4] = fmod(posicion[4] - 4.5, 360); //Jupiter
		posicion[5] = fmod(posicion[5] - 3.5, 360); //Saturno
		posicion[6] = fmod(posicion[6] - 2.5, 360); //Urano
		posicion[7] = fmod(posicion[7] - 1.5, 360); //Neptuno
		/*Para las lunas*/
		lunas[0] = fmod(lunas[0] - 1.5, 360); //Luna de la tierra
		lunas[1] = fmod(lunas[1] - 15, 360); //Luna de marte
		lunas[2] = fmod(lunas[2] - 20, 360); //Luna 2 de marte 
		lunas[3] = fmod(lunas[3] - 20.5, 360); //Luna 1 de jupiter
		lunas[4] = fmod(lunas[4] - 23.5, 360); //Luna 2 de jupiter
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
	glutCreateWindow("Ejercicio de casa 6"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}