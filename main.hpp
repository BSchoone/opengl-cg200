#include "ScreenText.hpp"
#include "imageloader.h"
#include "Controls.hpp"

GLuint _textureId; // The id of the texture is an integer which is used to determine which texture is which
// LIGHTS //



//diffuse light color variables
GLfloat dlr = 1.0;
GLfloat dlg = 1.0;
GLfloat dlb = 1.0;

//ambient light color variables
GLfloat alr = 1.0;
GLfloat alg = 1.0;
GLfloat alb = 1.0;

//light0 position variables
GLfloat lx = 0.0;
GLfloat ly = 10.0;
GLfloat lz = -5.0;
GLfloat lw = 1.0;

GLfloat lx1 = 0.0;
GLfloat ly1 = 0.0;
GLfloat lz1 = 0.0;
GLfloat lw1 = 1.0;


GLfloat fogColor[4] = {0.5, 0.5, 0.5, 1.0}; //set the forcolor to grey



void display (void);
void keyPressed (unsigned char, int, int);
void init(void);
void draw();
void reshape (int, int);
void fRand(double, double);
GLuint loadTexture(Image*);