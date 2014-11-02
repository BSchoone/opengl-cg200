#ifndef _CONTROLS_
#define _CONTROLS_

void keyPressed (unsigned char, int, int);
#define ZOOM 0.1
#define MAXZOOM 10.0
#define	CUBE_SIZE 1.0


//Dirty Globals
// CAMERA //

extern GLfloat xpos, ypos, zpos, xrot, yrot, angle;

// ANIMATION //

extern GLfloat rotateY;
extern GLfloat rotateYSpeed;
extern GLfloat rotateX;
extern GLfloat rotateXSpeed;
extern GLfloat zZoom;
extern GLfloat density;
extern GLfloat animationVal;
extern GLfloat animation, animationSpeed, detail;
extern int paused;

#endif