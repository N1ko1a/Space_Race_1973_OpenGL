/*
 * SimpleDraw.c
 *
 * Example program illustrating a simple use
 * of OpenGL to draw straight lines in 2D, and
 * to draw overlapping triangles in 3D.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "GL/glut.h"	// OpenGL Graphics Utility Library
#include "kolokvijum_header.h"

bool isKeyAPressed = false;
bool isKeyDPressed = false;
bool isKeyWPressed = false;
bool isKeySPressed = false;

bool isKeyLeftPressed = false;
bool isKeyRightPressed = false;
bool isKeyUpPressed = false;
bool isKeyDownPressed = false;

float size= 0.07;

float Xsize1=9.63, Ysize1=11.27;
float Xsize2=3.89, Ysize2=7.31;
float Xsize3=5.72, Ysize3=8.95;
float Xsize4=11.13, Ysize4=10.14;
float Xsize5=5.48, Ysize5=6.28;
float Xsize6=4.17, Ysize6=4.57;
float Xsize7=6.04, Ysize7=5.76;
float Xsize8=8.82, Ysize8=3.95;
float Xsize9=10.92, Ysize9=7.09;
float Xsize10=5.15, Ysize10=11.41;
float Xsize11=3.29, Ysize11=12.00;
float Xsize12=9.10, Ysize12=9.72;
float Xsize13=11.98, Ysize13=3.01;
float Xsize14=3.41, Ysize14=8.48;
float Xsize15=7.55, Ysize15=5.36;
float Xsize16=6.57, Ysize16=9.32;
float Xsize17=8.37, Ysize17=6.07;
float Xsize18=10.24, Ysize18=5.47;
float Xsize19=4.93, Ysize19=10.74;
float Xsize20=7.99, Ysize20=7.58;
float Xsize21=11.51, Ysize21=4.15;
float Xsize22=3.75, Ysize22=6.96;
float Xsize23=9.83, Ysize23=8.01;
float Xsize24=5.30, Ysize24=9.58;
float Xsize25=6.87, Ysize25=7.70;
float Xsize26=8.06, Ysize26=5.93;
float Xsize27=10.56, Ysize27=3.81;
float Xsize28=3.09, Ysize28=11.87;
float Xsize29=11.21, Ysize29=6.40;
float Xsize30=3.15, Ysize30=10.82;


float XsizeP1= 0.0, YsizeP1= 0.0;
float XsizeP2= 0.0, YsizeP2= 0.0;

float Xspeed = 0.005;
float ug = 0.0;
float animation = 10;
int RunMode = 1;

void drawQuad(float Xsize, float Ysize) {
    int numOfCopies = 100;
    float distanceBetweenCopies = 08.0;
	

    glPushMatrix();
    glTranslatef(Xsize, Ysize, 0);

    // Draw the quad
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-size, -size / 2);
    glVertex2f(-size, size / 2);
    glVertex2f(size, size / 2);
    glVertex2f(size, -size / 2);
    glEnd();

    glPopMatrix();

    // Draw the seamless background
    for (int i = -numOfCopies / 2; i <= numOfCopies / 2; i++) {
        glPushMatrix();
        glTranslatef(i * distanceBetweenCopies + Xsize, Ysize, 0);

        // Draw the quad
        glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(-size, -size / 2);
        glVertex2f(-size, size / 2);
        glVertex2f(size, size / 2);
        glVertex2f(size, -size / 2);
        glEnd();

        glPopMatrix();
    }
}

void drawPlane2() {
    // plane 1
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(10.5 + XsizeP1, 1.0 + YsizeP1, 0.0);
    glVertex3f(11.0 + XsizeP1, 1.0 + YsizeP1, 0.0);
    glVertex3f(10.75 + XsizeP1, 1.25 + YsizeP1, 0.0);
    glEnd();
}

void drawPlane1() {
    // plane 1
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1.0 + XsizeP2, 1.0 + YsizeP2, 0.0);
    glVertex3f(1.5 + XsizeP2, 1.0 + YsizeP2, 0.0);
    glVertex3f(1.25 + XsizeP2, 1.25 + YsizeP2, 0.0);
    glEnd();
}

// These variables set the dimensions of the rectanglar region we wish to view.
// Kada se aktivira program pa onaj prozor sto se pojavi
const double Xmin = 0.0, Xmax = 13.0; //ovo odredjuje velicinu kordinatnog sistema
const double Ymin = 0.0, Ymax = 13.0;

// glutKeyboardFunc is called below to set this function to handle
//		all "normal" ascii key presses.
// Only space bar and escape key have an effect.
void myKeyboardFunc(unsigned char key, int x, int y) {
    float increment = 0.1; // Higher increment value for faster movement

    switch (key) {
    case 'a':
    case 'A':
        isKeyAPressed = true;
        break;
    case 'd':
    case 'D':
        isKeyDPressed = true;
        break;
    case 'w':
    case 'W':
        isKeyWPressed = true;
        break;
    case 's':
    case 'S':
        isKeySPressed = true;
        break;
    case ' ':
        // Toggle images or do any other action (if needed)
        break;
    case 27: // Escape key
        exit(0);
        break;
    }
}

void keyUp(unsigned char key, int x, int y) {
    switch (key) {
    case 'a':
    case 'A':
        isKeyAPressed = false;
        break;
    case 'd':
    case 'D':
        isKeyDPressed = false;
        break;
    case 'w':
    case 'W':
        isKeyWPressed = false;
        break;
    case 's':
    case 'S':
        isKeySPressed = false;
        break;
    }
}


void mySpecialKeyFunc(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        isKeyLeftPressed = true;
        break;
    case GLUT_KEY_RIGHT:
        isKeyRightPressed = true;
        break;
    case GLUT_KEY_UP:
        isKeyUpPressed = true;
        break;
    case GLUT_KEY_DOWN:
        isKeyDownPressed = true;
        break;
    }

    glutPostRedisplay();
}
void keyUpSpecial(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        isKeyLeftPressed = false;
        break;
    case GLUT_KEY_RIGHT:
        isKeyRightPressed = false;
        break;
    case GLUT_KEY_UP:
        isKeyUpPressed = false;
        break;
    case GLUT_KEY_DOWN:
        isKeyDownPressed = false;
        break;
    }
}


void handleMovement() {
    float increment = 0.005; // Higher increment value for faster movement

    if (isKeyAPressed)
        XsizeP2 -= increment; // Move left
    if (isKeyDPressed)
        XsizeP2 += increment; // Move right
    if (isKeyWPressed)
        YsizeP2 += increment; // Move up
    if (isKeySPressed)
        YsizeP2 -= increment; // Move down

        // Handling arrow keys
    if (isKeyLeftPressed)
        XsizeP1 -= increment; // Move left
    if (isKeyRightPressed)
        XsizeP1 += increment; // Move right
    if (isKeyUpPressed)
        YsizeP1 += increment; // Move up
    if (isKeyDownPressed)
        YsizeP1 -= increment; // Move down
}

/*
 * drawScene() handles the animation and the redrawing of the
 *		graphics window contents.
 */
void drawScene(void) {
    if (RunMode == 1) {
        ug += animation;
        if (ug >= 360) {
            ug = ug * 0;
        }
    }

    // Clear the rendering window
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set drawing color to white
    Xsize21 = Xsize21 - Xspeed;
    drawQuad(Xsize21, Ysize21);
    Xsize1 = Xsize1 + Xspeed;
    drawQuad(Xsize1, Ysize1);
	 Xsize2 = Xsize2 + Xspeed;
    drawQuad(Xsize2, Ysize2);
	 Xsize3 = Xsize3 + Xspeed;
    drawQuad(Xsize3, Ysize3);
	Xsize4 = Xsize4 + Xspeed;
    drawQuad(Xsize4, Ysize4);
	Xsize5 = Xsize5 + Xspeed;
    drawQuad(Xsize5, Ysize5);
	Xsize6 = Xsize6 + Xspeed;
    drawQuad(Xsize6, Ysize6);
	Xsize7 = Xsize7 + Xspeed;
    drawQuad(Xsize7, Ysize7);
	Xsize8 = Xsize8 + Xspeed;
    drawQuad(Xsize8, Ysize8);
	Xsize9 = Xsize9 + Xspeed;
    drawQuad(Xsize9, Ysize9);
	Xsize10 = Xsize10 + Xspeed;
    drawQuad(Xsize10, Ysize10);
	Xsize11 = Xsize11 + Xspeed;
    drawQuad(Xsize11, Ysize11);
	Xsize12 = Xsize12 + Xspeed;
    drawQuad(Xsize12, Ysize12);
	Xsize13 = Xsize13 + Xspeed;
    drawQuad(Xsize13, Ysize13);
	Xsize14 = Xsize14 + Xspeed;
    drawQuad(Xsize14, Ysize14);
	Xsize15 = Xsize15 + Xspeed;
    drawQuad(Xsize15, Ysize15);

	Xsize16 = Xsize16 - Xspeed;
    drawQuad(Xsize16, Ysize16);
	Xsize17 = Xsize17 - Xspeed;
    drawQuad(Xsize17, Ysize17);
	Xsize18 = Xsize18 - Xspeed;
    drawQuad(Xsize18, Ysize18);
	Xsize19 = Xsize19 - Xspeed;
    drawQuad(Xsize19, Ysize19);
	Xsize20 = Xsize20 - Xspeed;
    drawQuad(Xsize20, Ysize20);
	Xsize22 = Xsize22 - Xspeed;
    drawQuad(Xsize22, Ysize22);
	Xsize23 = Xsize23 - Xspeed;
    drawQuad(Xsize23, Ysize23);
	Xsize24 = Xsize24 - Xspeed;
    drawQuad(Xsize24, Ysize24);
	Xsize25 = Xsize25 - Xspeed;
    drawQuad(Xsize25, Ysize25);
	Xsize26 = Xsize26 - Xspeed;
    drawQuad(Xsize26, Ysize26);
	Xsize27 = Xsize27 - Xspeed;
    drawQuad(Xsize27, Ysize27);
	Xsize28 = Xsize28 - Xspeed;
    drawQuad(Xsize28, Ysize28);
	Xsize29 = Xsize29 - Xspeed;
    drawQuad(Xsize29, Ysize20);
	Xsize30 = Xsize30 - Xspeed;
    drawQuad(Xsize30, Ysize30);

	drawPlane1();
	drawPlane2();
	handleMovement(); 

    // Flush the pipeline.  (Not usually necessary.)
    glFlush();
    glutSwapBuffers();

    if (RunMode == 1) {
        glutPostRedisplay();
    }
}


// Initialize OpenGL's rendering modes
void initRendering()
{

	glEnable ( GL_DEPTH_TEST );

	// Uncomment out the first block of code below, and then the second block,
	//		to see how they affect line and point drawing.
/*
	// The following commands should cause points and line to be drawn larger
	//	than a single pixel width.
	glPointSize(8);
	glLineWidth(5);



	// The following commands should induce OpenGL to create round points and 
	//	antialias points and lines.  (This is implementation dependent unfortunately).
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);	// Make round points, not square points
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);		// Antialias the lines
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
*/

}

// Called when the window is resized
//		w, h - width and height of the window in pixels.
void resizeWindow(int w, int h)
{
	double scale, center;
	double windowXmin, windowXmax, windowYmin, windowYmax;

	// Define the portion of the window used for OpenGL rendering.
	glViewport( 0, 0, w, h );	// View port uses whole window

	// Set up the projection view matrix: orthographic projection
	// Determine the min and max values for x and y that should appear in the window.
	// The complication is that the aspect ratio of the window may not match the
	//		aspect ratio of the scene we want to view.
	w = (w==0) ? 1 : w;
	h = (h==0) ? 1 : h;
	if ( (Xmax-Xmin)/w < (Ymax-Ymin)/h ) {
		scale = ((Ymax-Ymin)/h)/((Xmax-Xmin)/w);
		center = (Xmax+Xmin)/2;
		windowXmin = center - (center-Xmin)*scale;
		windowXmax = center + (Xmax-center)*scale;
		windowYmin = Ymin;
		windowYmax = Ymax;
	}
	else {
		scale = ((Xmax-Xmin)/w)/((Ymax-Ymin)/h);
		center = (Ymax+Ymin)/2;
		windowYmin = center - (center-Ymin)*scale;
		windowYmax = center + (Ymax-center)*scale;
		windowXmin = Xmin;
		windowXmax = Xmax;
	}
	
	// Now that we know the max & min values for x & y that should be visible in the window,
	//		we set up the orthographic projection.
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho( windowXmin, windowXmax, windowYmin, windowYmax, -1, 1 );

}


// Main routine
// Set up OpenGL, define the callbacks and start the main loop
int main( int argc, char** argv )
{
	glutInit(&argc,argv);

	// The image is not animated so single buffering is OK. 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH );

	// Window position (from top corner), and size (width and hieght)
	glutInitWindowPosition( 20, 60 );
	glutInitWindowSize( 360, 360 );
	glutCreateWindow( "SimpleDraw - Press space bar to toggle images" );

	// Initialize OpenGL as we like it..
	initRendering();

	// Set up callback functions for key presses
	glutKeyboardFunc(myKeyboardFunc);     // Handles "normal" ascii symbols
glutKeyboardUpFunc(keyUp);            // Handles key release
glutSpecialFunc(mySpecialKeyFunc);    // Handles arrow keys
glutSpecialUpFunc(keyUpSpecial);

	// Set up the callback function for resizing windows
	glutReshapeFunc( resizeWindow );

	// Call this for background processing
	// glutIdleFunc( myIdleFunction );

	// call this whenever window needs redrawing
	glutDisplayFunc( drawScene );

	fprintf(stdout, "Press space bar to toggle images; escape button to quit.\n");
	
	// Start the main loop.  glutMainLoop never returns.
	glutMainLoop(  );

	return(0);	// This line is never reached.
}
