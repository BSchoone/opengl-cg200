#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include "Controls.hpp"

	GLfloat rotateY;
	GLfloat rotateYSpeed;
	GLfloat rotateX;
	GLfloat rotateXSpeed;
	GLfloat zZoom = 5.0f;

	GLfloat animationVal = 0;
	GLfloat xpos = 0.0, ypos = 0.0, zpos = 0.0, xrot = 0.0, yrot = 0.0, angle=0.0;
	GLfloat density = 0.05; //set the density to 0.3 which is acctually quite thick
	GLfloat animation = 0.0, animationSpeed=0.0, detail=500.0, pauseAni, pauseSpeed;
	int paused;

void keyPressed (unsigned char key, int x, int y)
{
	
//This switch statement is how the keyboard input works
//it basically check if you have pressed a certain key
//then it performs the code inside that case
	printf("pressing Key\n");
	switch (key)
	{
		break;
		//When key f is pressed it makes the animation speed up as per specifications
		case 'f':
			if(animationSpeed != 0.1)
				animationSpeed = animationSpeed + 0.01;
		break;
		case 'F':
			if(animationSpeed != 0.1)
				animationSpeed = animationSpeed + 0.01;
		break;

		// When the s key is pressed it cause the animation to slow down
		case 's':
			if(animationSpeed > 0.01)
				animationSpeed = animationSpeed - 0.01;
		break;
		case 'S':
			if(animationSpeed > 0.01)
				animationSpeed = animationSpeed - 0.01;
		break;
		// Pressing the y key will cause the scene to rotate on the y-axis clockwise
		
		case 'y':
			if (rotateYSpeed < 0.3f){ // This limits how fast you can make the scene spin on the y-axis
				rotateYSpeed += 0.1f;
			}
			if (rotateY > 360.0f){ // If we have rotated beyond 360 degrees (a full rotation)  
				rotateY -= 360.0f; // Subtract 360 degrees off of our rotation
			}  
		break;
		// Pressing the Y key will cause the scene to rotate on the y-axis anti-clockwise
		
		case 'Y':
			if (rotateYSpeed > -0.3f){
				rotateYSpeed -= 0.1f;
			}
			if (rotateY > 360.0f){ // If we have rotated beyond 360 degrees (a full rotation)  
				rotateY -= 360.0f; // Subtract 360 degrees off of our rotation
			}  
		break;
		// Pressing the x key will rotate the entire scene on the x-axis clockwise
		case 'x':
			if (rotateXSpeed < 0.3f){ // Limits how fast you can rotate the scene
				rotateXSpeed += 0.1f;
			}
		break;
		
		// Pressing the X key will rotate the entire scene on the x-axis clockwise
		case 'X':
			if (rotateXSpeed > -0.3f){
				rotateXSpeed -= 0.1f;
			}
		break;
		
		// Pressing the a key will begin the animation
		case 'a':
			if(animationSpeed == 0.0)
				animationSpeed = 0.05;
		break;

		case 'A':
			if(animationSpeed != 0.0)
				animationSpeed = 0.0;
		break;
		
		// Lower case z zooms into the scene
		case 'z': 
			if (zZoom < MAXZOOM){
				detail+=20;
				zZoom = zZoom + ZOOM;
			}
        break;
        //Upper case z zooms out of the scene
        case 'Z': 
	        if (zZoom > 2.7f){
	        	detail-=20;
				zZoom = zZoom - ZOOM;
			}
        break;
		// Pressing p changes the shader model to smooth
		case 'p':
			glShadeModel (GL_SMOOTH); 			
		break;
		// Pressing P changes the shader model to flat
		case 'P':
			glShadeModel (GL_FLAT); 			
		break;
		// Pressing t or T causes the animation to pause
		case 't':
			pauseSpeed = animationSpeed;
			
			animationSpeed=0.0;
		break;
		case 'T':
			pauseSpeed = animationSpeed;
			animationSpeed=0.0;
		break;
		// Pressing c or C causes the animation to resume
		case 'c':
			animationSpeed = pauseSpeed;
		break;
		case 'C':
			animationSpeed=pauseSpeed;		
		break;
		case 'd':
			if(density>0.0)
				density = density - 0.05;
		break;
		case 'D':
			if(density<0.3)
				density = density + 0.05;		
		break;
		case 'q':
			exit(0);
		break;		
	}
}