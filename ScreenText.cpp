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
#include <math.h>
#include <string.h>
#include "ScreenText.hpp"


void textToScreen(char *text, float x, float y)
{

	int len, i;
	
	glColor3f(0.0f,0.0f,0.0f);
	glRasterPos3f(x,y,0);
	len=strlen(text);
	
	glPushMatrix();
	for(i=0;i<len;i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,text[i]);
		}
	glPopMatrix();
}

void textToWrite()
{
	glDisable(GL_LIGHTING);
	glPushMatrix();
		glTranslatef(-1.75f,17.5f, 5.0f);
		textToScreen((char *)"~~~~~Commands~~~~~",-14.0,14.0);
		textToScreen((char*)"<z/Z> : Zoom +/-",-14.0,13.0);
		textToScreen((char*)"<x/X> : X-Axis Rotate +/-",-14.0,12.0);
		textToScreen((char*)"<y/Y> : Y-axis Rotate +/-",-14.0,11.0);
		textToScreen((char*)"<p> : Turn On Smooth Shading",-14.0,10.0);
		textToScreen((char*)"<P> : Turn on Flat Shading",-14.0,9.0);
		textToScreen((char*)"<a>/<A> : Start animation",-14.0,8.0);
		textToScreen((char*)"<t>/<T> : Pause animation",-14.0,7.0);
		textToScreen((char*)"<c>/<C> : Resume Animation",-14.0,6.0);
		textToScreen((char*)"<d/D> : -/+ Fog Levels",-14.0,5.0);
		textToScreen((char*)"<q> : Quit the program",-14.0,4.0);
		textToScreen((char*)"",-14.0,3.0);
		textToScreen((char*)"",-14.0,2.0);
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

void output(float x, float y, float r, float g, float b, char *string)
{
  glColor3f( r, g, b );
  glRasterPos2i(x, y);
  glTranslatef(x,y,0);
  int len, i;
  len = (int)strlen(string);
  for (i = 0; i < len; i++) {
    glutStrokeCharacter(GLUT_STROKE_ROMAN, string[i]);
  }
}
