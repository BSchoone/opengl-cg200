#include "RandomObjects.hpp"

#include "tree1.h"
#include "fireplace.h"
#include "Duke.h"
#include "Controls.hpp"
#include <cmath>

void MuthaFuckinTree(double x, double y, double z){
	glPushMatrix();
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
	    glBindTexture(GL_TEXTURE_3D, 2);
	    glEnable(GL_TEXTURE_2D);

		glEnableClientState(GL_VERTEX_ARRAY);
		// set input data to arrays
		glVertexPointer(3, GL_FLOAT, 0, tree1Verts);
		glNormalPointer(GL_FLOAT, 0, tree1Normals);
		glTexCoordPointer(2, GL_FLOAT, 0, tree1TexCoords);

		glColor3f( 0.2, 0.5, 0.0 );
		glScalef(1.0f,2.0f,1.0f);
		glTranslatef(x, 0.0f, z);
		glRotated(5.0*sin(animation), 1.0f, 0.0f, 0.0f);
		
		//glTranslatef(x, y, z);
		glTranslatef(0.0f, y, 0.0f);

		
		//glTranslatef(x, 0.0f, z);
		
		//glTranslatef(30.0*sin(animation),0.0f , 0.0f);
		

		// draw data
		glDrawArrays(GL_TRIANGLES, 0, tree1NumVerts);

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Fireplace(){

	glPushMatrix();
		glEnableClientState(GL_VERTEX_ARRAY);
		// set input data to arrays
		glVertexPointer(3, GL_FLOAT, 0, fireplaceVerts);
		//glTexCoordPointer(2, GL_FLOAT, 0, fireplaceTexCoords);

		//texture
		glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
		// draw data
		glScalef(0.5f,0.5f,0.5f);
		glTranslatef(0.0f, 0.1f, 0.0f);

		glDrawArrays(GL_TRIANGLES, 0, fireplaceNumVerts);
		glDisableClientState(GL_VERTEX_ARRAY);
	glPopMatrix();
}

void DukeNukem(){
	
	
	glPushMatrix();
		glEnableClientState(GL_VERTEX_ARRAY);
		// set input data to arrays
		glVertexPointer(3, GL_FLOAT, 0, DukeVerts);
		//glTexCoordPointer(2, GL_FLOAT, 0, DukeTexCoords);
			
		// draw data
		glColor4f(1.0, 1.0, 0.0, 0.5);
		//glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS);
		glScalef(0.5f,0.5f,0.5f);
		glTranslatef(0.0f, 0.65f, -2.0f);
		glRotated(360*animation, 0.0f, 1.0f, 0.0f);
		glDrawArrays(GL_TRIANGLES, 0, DukeNumVerts);	

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisable(GL_TEXTURE_2D);
		glColor4f(1.0, 1.0, 0.0, 1.0);
	glPopMatrix();
}

void ground(){
	glPushMatrix();
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
     	//glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
		//glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
     	glBindTexture(GL_TEXTURE_2D, 1);
     	glEnable(GL_TEXTURE_2D);
	 	
        //glColor3f(1.0f, 1.0f, 1.0f);


		glBegin(GL_QUADS);
			
			glNormal3f(0,0,1); // the surface normal is pointing upwards
			glTexCoord2f(50.0f, 50.0f);
			//glColor3f(0.0, 1.0, 0.0);
			glVertex3f(50, 0, 50);
			glTexCoord2f(50.0f, -50.0f);
			glVertex3f(50, 0, -50);
			glTexCoord2f(-50.0f, -50.0f);
			glVertex3f(-50, 0, -50);
			glTexCoord2f(-50.0f, 50.0f);
			glVertex3f(-50, 0, 50);
		glEnd();

		glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}

void cube(){
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
 	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
 	glBindTexture(GL_TEXTURE_2D, 2);
 	glEnable(GL_TEXTURE_2D);

    glPushMatrix();
	    glColor3f(1.0f, 1.0f, 1.0f);
		
	    glScalef(1.5f,0.75f,1.5f);
		glTranslatef(-1.0f, 0.5f, 0.0f);


		// White side - BACK
		glBegin(GL_POLYGON);
			//glColor3f(   1.0,  1.0, 1.0 );
			glNormal3f(0,0,1);
			
			glTexCoord3f(0.5f, -0.5f, 0.5f);
			glVertex3f(  0.5, -0.5, 0.5 );
			
			glTexCoord3f(0.5f,  0.5f, 0.5f);
			glVertex3f(  0.5,  0.5, 0.5 );
			
			glTexCoord3f(-0.5f, 0.5f, 0.5f);
			glVertex3f( -0.5,  0.5, 0.5 );
			
			glTexCoord3f(-0.5f, -0.5f, 0.5f);
			glVertex3f( -0.5, -0.5, 0.5 );
		glEnd();
		
		// White side - FRONT
		glBegin(GL_POLYGON);
			//glColor3f(   1.0,  1.0, 1.0 );
			glTexCoord3f(-0.5f, 0.5f, -0.5f);
			glVertex3f(  -0.5, 0.5, -0.5 );
			
			glTexCoord3f(-0.5f, -0.5f, -0.5f);
			glVertex3f(  -0.5,  -0.5, -0.5 );
			
			glTexCoord3f(0.5f, -0.5f, -0.5f);
			glVertex3f( 0.5,  -0.5, -0.5 );
			
			glTexCoord3f(0.5f, 0.5f, -0.5f);
			glVertex3f( 0.5, 0.5, -0.5 );
			
		glEnd();

		// Purple side - RIGHT
		glBegin(GL_POLYGON);
			//glColor3f(  1.0,  0.0,  1.0 );
			glTexCoord3f(0.5f, -0.5f, -0.5f);
			glVertex3f( 0.5, -0.5, -0.5 );
			
			glTexCoord3f(0.5f, 0.5f, -0.5f);
			glVertex3f( 0.5,  0.5, -0.5 );
			
			glTexCoord3f(-0.5f, 0.5f, -0.5f);
			glVertex3f( 0.5,  0.5,  0.5 );
			
			glTexCoord3f(-0.5f, -0.5f, -0.5f);
			glVertex3f( 0.5, -0.5,  0.5 );
		glEnd();
		 
		// Green side - LEFT
		glBegin(GL_POLYGON);
			//glColor3f(   0.0,  1.0,  0.0 );
			glTexCoord3f(-0.5f, -0.5f, -0.5f);
			glVertex3f( -0.5, -0.5,  0.5 );
			
			glTexCoord3f(-0.5f, 0.5f, -0.5f);
			glVertex3f( -0.5,  0.5,  0.5 );
			
			glTexCoord3f(0.5f, 0.5f, -0.5f);
			glVertex3f( -0.5,  0.5, -0.5 );
			
			glTexCoord3f(0.5f, -0.5f, -0.5f);
			glVertex3f( -0.5, -0.5, -0.5 );
		glEnd();
		 
		// Blue side - TOP
		glBegin(GL_POLYGON);
			//glColor3f(   0.0,  0.0,  1.0 );
			glVertex3f(  0.5,  0.5,  0.5 );
			glVertex3f(  0.5,  0.5, -0.5 );
			glVertex3f( -0.5,  0.5, -0.5 );
			glVertex3f( -0.5,  0.5,  0.5 );
		glEnd();
		 
		// Red side - BOTTOM
		glBegin(GL_POLYGON);
			//glColor3f(   1.0,  0.0,  0.0 );
			glVertex3f(  0.5, -0.5, -0.5 );
			glVertex3f(  0.5, -0.5,  0.5 );
			glVertex3f( -0.5, -0.5,  0.5 );
			glVertex3f( -0.5, -0.5, -0.5 );
		glEnd();
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}

void logseat(double height, double width)
{



    glPushMatrix();
    
    glColor3f(0.4, 0.2, 0.0);
    
    glTranslatef(1.5f, 0.0f, 1.5f);
    glRotated(180, 0.0, 1.0, 0.0);
    GLUquadric* cylinder = gluNewQuadric();
    GLUquadric* top = gluNewQuadric();
    GLUquadric* bottom = gluNewQuadric();

	gluCylinder(cylinder, width, width, height, detail, detail);
	gluDisk(bottom,  0,  width,  detail,  detail);
	glTranslatef(0, 0, height);
	gluDisk(top, 0, width, detail, detail);

	//gluCylinder(GLU quadric* quad, GLdouble base, GLdouble top, GLdouble height, 
	//			GLint    slices, GLint    stacks);

    glPopMatrix();
}









void Arrow(GLdouble x1,GLdouble y1,GLdouble z1,GLdouble x2,GLdouble y2,GLdouble z2,GLdouble D)
{
  double x=x2-x1;
  double y=y2-y1;
  double z=z2-z1;
  double L=sqrt(x*x+y*y+z*z);

    GLUquadricObj *quadObj;

    glPushMatrix ();

      glTranslated(x1,y1,z1);

      if((x!=0.)||(y!=0.)) {
        glRotated(atan2(y,x)/RADPERDEG,0.,0.,1.);
        glRotated(atan2(sqrt(x*x+y*y),z)/RADPERDEG,0.,1.,0.);
      } else if (z<0){
        glRotated(180,1.,0.,0.);
      }

      glTranslatef(0,0,L-4*D);

      quadObj = gluNewQuadric ();
      gluQuadricDrawStyle (quadObj, GLU_FILL);
      gluQuadricNormals (quadObj, GLU_SMOOTH);
      gluCylinder(quadObj, 2*D, 0.0, 4*D, 32, 1);
      gluDeleteQuadric(quadObj);

      quadObj = gluNewQuadric ();
      gluQuadricDrawStyle (quadObj, GLU_FILL);
      gluQuadricNormals (quadObj, GLU_SMOOTH);
      gluDisk(quadObj, 0.0, 2*D, 32, 1);
      gluDeleteQuadric(quadObj);

      glTranslatef(0,0,-L+4*D);

      quadObj = gluNewQuadric ();
      gluQuadricDrawStyle (quadObj, GLU_FILL);
      gluQuadricNormals (quadObj, GLU_SMOOTH);
      gluCylinder(quadObj, D, D, L-4*D, 32, 1);
      gluDeleteQuadric(quadObj);

      quadObj = gluNewQuadric ();
      gluQuadricDrawStyle (quadObj, GLU_FILL);
      gluQuadricNormals (quadObj, GLU_SMOOTH);
      gluDisk(quadObj, 0.0, D, 32, 1);
      gluDeleteQuadric(quadObj);

    glPopMatrix ();

}
void drawAxes(GLdouble length)
{
    glPushMatrix();
    glTranslatef(-length,0,0);
    glColor3f(1.0, 0.0, 0.0);
    Arrow(0,0,0, 2*length,0,0, 0.01);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-length,0);
    glColor3f(0.0, 1.0, 0.0);
    Arrow(0,0,0, 0,2*length,0, 0.01);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,-length);
    glColor3f(0.0, 0.0, 1.0);
    Arrow(0,0,0, 0,0,2*length, 0.01);
    glPopMatrix();
}