#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#endif
#ifdef __linux__
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "main.hpp"
#include "RandomObjects.hpp"




double arry1[50];
double arry2[50];

int main (int argc, char **argv)
{
	
	fRand(-5.0, 5.0);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(1280,1280);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Barons OpenGL");
	init();
	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyPressed);
	glutMainLoop();
	
}

void display (void)
{       
	//printf("%lf\n", animationSpeed);
	glFogf(GL_FOG_DENSITY, density);
	//printf("Displaying\n");
	glClearColor(0.5f, 0.5f, 0.5f, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -10.0f);
	gluLookAt (5.0, 1.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    //camera position, x,y,z, looking at x,y,z,Up Positions of the camera   

    glPushMatrix();
		glRotatef(rotateY,0.0f,1.0f,0.0f);
		rotateY+=rotateYSpeed;
		glRotatef(rotateX,1.0f,0.0f,0.0f);
		rotateX+=rotateXSpeed;
		glScalef(zZoom,zZoom,zZoom);
		
		animation+=animationSpeed;

		logseat(1.0, 0.25);
		cube();
		drawAxes(5.0);
		
		
		for(int ii=0; ii<=40; ii++)
		{
			MuthaFuckinTree(arry1[ii], 0.5f, arry2[ii]);
		}
		Fireplace();
		DukeNukem();
		ground();

	glPopMatrix();

	glPushMatrix();
		glLoadIdentity();
			gluOrtho2D(-5.0, 5.0, 0.0, 15.0);
				glMatrixMode(GL_MODELVIEW);
					textToWrite();
	glPopMatrix();

	glFlush();
	glutSwapBuffers();
	    
}

void reshape (int w, int h)
{
	printf("Reshapping\n");
   	glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   	glMatrixMode (GL_PROJECTION);
   	glLoadIdentity ();
   	glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 100.0);
   	glMatrixMode (GL_MODELVIEW);
}



void init(void)
{
   	GLfloat light_position[] = { 5.0, 5.0, 5.0, 0.0 };
   	GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
   	GLfloat whiteDiffuseLight[] = {1.0, 1.0, 1.0};
   	glClearColor (0.0, 0.0, 0.0, 0.0);
   	glShadeModel (GL_SMOOTH);

   	GLfloat DiffuseLight[] = {dlr, dlg, dlb}; //set DiffuseLight[] to the specified values
    GLfloat AmbientLight[] = {alr, alg, alb}; //set AmbientLight[] to the specified values
    GLfloat LightPosition[] = {lx, ly, lz, lw}; //set the LightPosition to the specified values
    GLfloat LightPosition1[] = {lx1, ly1, lz1, lw1}; //set the LightPosition to the specified values
    glLightfv (GL_LIGHT0, GL_POSITION, LightPosition); //change the light accordingly
    glLightfv (GL_LIGHT1, GL_POSITION, LightPosition1);

    GLfloat lightColor1[] = {1.0f, 1.0f, 1.0f, 1.0f};

    glEnable (GL_BLEND); 
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

   	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
   	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);


   	glEnable(GL_LIGHTING);
   	glEnable(GL_LIGHT0);
   	glEnable(GL_DEPTH_TEST);
   	glEnable(GL_COLOR_MATERIAL);
   	glEnable (GL_FOG);

   	glFogi(GL_FOG_MODE, GL_EXP2); //set the fog mode to GL_EXP2

	glFogfv(GL_FOG_COLOR, fogColor); //set the fog color to our color chosen above
	glFogf(GL_FOG_DENSITY, density); //set the density to the value above

	glHint (GL_FOG_HINT, GL_NICEST); // set the fog to look the nicest, may slow down on older cards

   	Image* image1= loadBMP("park.bmp");
    _textureId = loadTexture(image1);
    printf("%d\n", _textureId);

    Image* image3= loadBMP("bricks.bmp");
    _textureId = loadTexture(image3);
    printf("%d\n", _textureId);

    Image* image2= loadBMP("duke.bmp");
    _textureId = loadTexture(image2);
    printf("%d\n", _textureId);


}


void fRand(double bot, double top)
{
    int n = 50;
    for(int i = 0 ; i < n ; i++ ) {
 		double f = (double)rand() / RAND_MAX;   
      	arry1[i] = bot + f * (top - bot);
      	//printf("%lf\n", arry1[i]);	
    }
    for(int i = 0 ; i < n ; i++ ) {
 		double f = (double)rand() / RAND_MAX;   
      	arry2[i] = bot + f * (top - bot);
      	//printf("%lf\n", arry2[i]);	
    }
}

// Texture loading function //
GLuint loadTexture(Image *image)
{
	GLuint textureId;
	glGenTextures(1, &textureId); //Make some room for the texture loading 1 texture at a time and using the textureId to decide which texture.
	glBindTexture(GL_TEXTURE_2D, textureId); //Bind the textures according to the textureId, textureId being an int.
	glTexImage2D(GL_TEXTURE_2D,
				0,
				GL_RGB,
				image->width, image->height,
				0,
				GL_RGB,
				GL_UNSIGNED_BYTE,
				image->pixels);
	return textureId;
}