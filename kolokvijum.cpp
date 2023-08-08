/*
 * SimpleDraw.c
 *
 * Example program illustrating a simple use
 * of OpenGL to draw straight lines in 2D, and
 * to draw overlapping triangles in 3D.
 *
 */

#include <stdlib.h>
#include <math.h>
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


float Xsize1=20.63, Ysize1=11.27;
float Xsize2=14.89, Ysize2=7.31;
float Xsize3=16.72, Ysize3=8.95;
float Xsize4=22.13, Ysize4=10.14;
float Xsize5=16.48, Ysize5=6.28;
float Xsize6=15.17, Ysize6=4.57;
float Xsize7=17.04, Ysize7=5.76;
float Xsize8=19.82, Ysize8=3.95;
float Xsize9=21.92, Ysize9=7.09;
float Xsize10=16.15, Ysize10=11.41;
float Xsize11=14.29, Ysize11=12.00;
float Xsize12=20.10, Ysize12=9.72;
float Xsize13=22.98, Ysize13=3.01;
float Xsize14=14.41, Ysize14=8.48;
float Xsize15=18.55, Ysize15=5.36;
float Xsize16=17.57, Ysize16=9.32;
float Xsize17=19.37, Ysize17=6.07;
float Xsize18=21.24, Ysize18=5.47;
float Xsize19=15.93, Ysize19=10.74;
float Xsize20=18.99, Ysize20=7.58;
float Xsize21=22.51, Ysize21=4.15;
float Xsize22=14.75, Ysize22=6.96;
float Xsize23=20.83, Ysize23=8.01;
float Xsize24=16.30, Ysize24=9.58;
float Xsize25=17.87, Ysize25=7.70;
float Xsize26=19.06, Ysize26=5.93;
float Xsize27=21.56, Ysize27=3.81;
float Xsize28=14.09, Ysize28=11.87;
float Xsize29=22.21, Ysize29=6.40;
float Xsize30=29.15, Ysize30=10.82;

float Xsize31 = 6.73, Ysize31 = 9.91;
float Xsize32 = 0.91, Ysize32 = 3.15;
float Xsize33 = 9.18, Ysize33 = 4.04;
float Xsize34 = 3.78, Ysize34 = 8.89;
float Xsize35 = 6.52, Ysize35 = 4.27;
float Xsize36 = 1.35, Ysize36 = 5.77;
float Xsize37 = 3.95, Ysize37 = 3.92;
float Xsize38 = 5.81, Ysize38 = 4.80;
float Xsize39 = 1.80, Ysize39 = 8.09;
float Xsize40 = 5.99, Ysize40 = 4.12;

float Xsize41 = 7.34, Ysize41 = 9.12;
float Xsize42 = 4.76, Ysize42 = 6.97;
float Xsize43 = 2.88, Ysize43 = 4.53;
float Xsize44 = 9.88, Ysize44 = 5.71;
float Xsize45 = 1.63, Ysize45 = 9.41;
float Xsize46 = 5.31, Ysize46 = 6.28;
float Xsize47 = 4.49, Ysize47 = 7.57;
float Xsize48 = 3.00, Ysize48 = 8.14;
float Xsize49 = 0.77, Ysize49 = 3.77;
float Xsize50 = 9.60, Ysize50 = 8.94;



float XsizeP1= 0.0, YsizeP1= 0.0;
float XsizeP2= 0.0, YsizeP2= 0.0;

float XsizeT =0.0, YsizeT = 13;
float XspeedT = 0.00005;

int counter1 = 0;
int counter2 = 0;
int countdown1 = 3;
int countdown2 = 3;

float Xspeed = 0.001;
float ug = 0.0;
float animation = 10;
int RunMode = 1;
#define NUM_RECTANGLES 50 // Update this value to match the total number of rectangles

float Xspeeds[NUM_RECTANGLES] = {0}; 





// These variables set the dimensions of the rectanglar region we wish to view.
// Kada se aktivira program pa onaj prozor sto se pojavi
const double Xmin = 0.0, Xmax = 24.0; //ovo odredjuje velicinu kordinatnog sistema
const double Ymin = 0.0, Ymax = 13.0;

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
    float increment = 0.001; // Higher increment value for faster movement

    // Handling AWSD keys
    if (isKeyAPressed) {
        XsizeP2 -= increment; // Move left
    }
    if (isKeyDPressed) {
        XsizeP2 += increment; // Move right
    }
    if (isKeyWPressed) {
        YsizeP2 += increment; // Move up
    }
    if (isKeySPressed) {
        YsizeP2 -= increment; // Move down
    }

    // Handling arrow keys
    if (isKeyLeftPressed) {
        XsizeP1 -= increment; // Move left
    }
    if (isKeyRightPressed) {
        XsizeP1 += increment; // Move right
    }
    if (isKeyUpPressed) {
        YsizeP1 += increment; // Move up
    }
    if (isKeyDownPressed) {
        YsizeP1 -= increment; // Move down
    }

    // Restarting to original positions
    if(YsizeP2 < -0.5){
        XsizeP2 = 0.0;
        YsizeP2 = 0.0;
    }

    if (YsizeP2 > 13.2) {
        XsizeP2 = 0.0;
        YsizeP2 = 0.0;
        counter1++;
        if(counter1 > 10){
            counter1 = 0;
            XsizeP1 = 0.0;
            YsizeP1 = 0.0;
            XsizeP2 = 0.0;
            YsizeP2 = 0.0;
            XsizeT = 0.0;
            YsizeT = 13.0;
        }
        
        
    }
    if(YsizeP1 < -0.5){
        XsizeP1 = 0.0;
        YsizeP1 = 0.0;
    }
    if(YsizeP1 > 13.2){
        XsizeP1 = 0.0;
        YsizeP1 = 0.0;
        counter2++;
        if(counter2 > 10){
            counter2 = 0;
            XsizeP1 = 0.0;
            YsizeP1 = 0.0;
            XsizeP2 = 0.0;
            YsizeP2 = 0.0;
            XsizeT = 0.0;
            YsizeT = 13.0;
        }
    }

   
   
 }

// glutKeyboardFunc is called below to set this function to handle
//		all "normal" ascii key presses.
// Only space bar and escape key have an effect.

/*
 * drawScene() handles the animation and the redrawing of the
 *		graphics window contents.
 */
void drawQuad(float Xsize, float Ysize) {

	
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
}
void drawPlane2() {
    // plane 1
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(16.5 + XsizeP1, 2.0 + YsizeP1, 0.0);
    glVertex3f(17.0 + XsizeP1, 2.0 + YsizeP1, 0.0);
    glVertex3f(16.75 + XsizeP1, 2.25 + YsizeP1, 0.0);
    glEnd();
    
}

void drawPlane1() {
    // plane 1
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(7.0 + XsizeP2, 2.0 + YsizeP2, 0.0);
    glVertex3f(7.5 + XsizeP2, 2.0 + YsizeP2, 0.0);
    glVertex3f(7.25 + XsizeP2, 2.25 + YsizeP2, 0.0);
    glEnd();
}
bool checkCollision(float quadX, float quadY, float quadSize,
                    float planeX, float planeY, int num) {
    // Calculate the bounding boxes for the quad and the plane
    float quadMinX = quadX - quadSize / 2;
    float quadMaxX = quadX + quadSize / 2;
    float quadMinY = quadY - quadSize / 2;
    float quadMaxY = quadY + quadSize / 2;

    float planeMinX = planeX - 0.25; // Adjust as per the actual bounding box of the plane
    float planeMaxX = planeX + 0.25; // Adjust as per the actual bounding box of the plane
    float planeMinY = planeY;
    float planeMaxY = planeY + 0.25; // Adjust as per the actual bounding box of the plane


   
    // Check for overlap
    if (quadMinX < planeMaxX && quadMaxX > planeMinX &&
        quadMinY < planeMaxY && quadMaxY > planeMinY) {
        if(num == 1){
        XsizeP1 = 0.0;
        YsizeP1= 0.0;
        countdown2--;
        }
        else{
        XsizeP2 = 0.0;
        YsizeP2 = 0.0;
        countdown1--;
        }
        if(countdown1 == 0 || countdown2 == 0){
            XsizeP1 = 0.0;
            YsizeP1= 0.0;
            XsizeP2 = 0.0;
            YsizeP2= 0.0;
            countdown1 = 3;
            countdown2 = 3;
            counter1 = 0;
            counter2 = 0;
            YsizeT = 13;
            XsizeT = 0;

        }
        
        // Collision detected
        return true;
    }

    // No collision
    return false;
}

void livesone(int counter){
    switch (counter) {
        case 1:
            glBegin(GL_POLYGON);
            glVertex2f(0.25, 12.25f);
            glVertex2f(0.5, 12.5f);
            glVertex2f(0.40, 12.75f);
            glVertex2f(0.30, 12.75f);
            glVertex2f(0.25, 12.65f);
            glVertex2f(0.20, 12.75f);
            glVertex2f(0.10, 12.75f);
            glVertex2f(0.0, 12.5f);
            glEnd();
            break;
        case 2:
            glBegin(GL_POLYGON);
            glVertex2f(0.25, 12.25f);
            glVertex2f(0.5, 12.5f);
            glVertex2f(0.40, 12.75f);
            glVertex2f(0.30, 12.75f);
            glVertex2f(0.25, 12.65f);
            glVertex2f(0.20, 12.75f);
            glVertex2f(0.10, 12.75f);
            glVertex2f(0.0, 12.5f);
            glEnd();
            glBegin(GL_POLYGON);
            glVertex2f(1.25, 12.25f);
            glVertex2f(1.5, 12.5f);
            glVertex2f(1.40, 12.75f);
            glVertex2f(1.30, 12.75f);
            glVertex2f(1.25, 12.65f);
            glVertex2f(1.20, 12.75f);
            glVertex2f(1.10, 12.75f);
            glVertex2f(1.0, 12.5f);
            glEnd();
            break;
        case 3:
            glBegin(GL_POLYGON);
            glVertex2f(0.25, 12.25f);
            glVertex2f(0.5, 12.5f);
            glVertex2f(0.40, 12.75f);
            glVertex2f(0.30, 12.75f);
            glVertex2f(0.25, 12.65f);
            glVertex2f(0.20, 12.75f);
            glVertex2f(0.10, 12.75f);
            glVertex2f(0.0, 12.5f);
            glEnd();
            glBegin(GL_POLYGON);
            glVertex2f(1.25, 12.25f);
            glVertex2f(1.5, 12.5f);
            glVertex2f(1.40, 12.75f);
            glVertex2f(1.30, 12.75f);
            glVertex2f(1.25, 12.65f);
            glVertex2f(1.20, 12.75f);
            glVertex2f(1.10, 12.75f);
            glVertex2f(1.0, 12.5f);
            glEnd();
            glBegin(GL_POLYGON);
            glVertex2f(2.25, 12.25f);
            glVertex2f(2.5, 12.5f);
            glVertex2f(2.40, 12.75f);
            glVertex2f(2.30, 12.75f);
            glVertex2f(2.25, 12.65f);
            glVertex2f(2.20, 12.75f);
            glVertex2f(2.10, 12.75f);
            glVertex2f(2.0, 12.5f);
            glEnd();
            break;
        default:
            break;
    }
}
void livestwo(int counter){
    switch (counter) {
        case 1:
            glBegin(GL_POLYGON);
            glVertex2f(21.65, 12.25f);
            glVertex2f(21.9, 12.5f);
            glVertex2f(21.80, 12.75f);
            glVertex2f(21.70, 12.75f);
            glVertex2f(21.65, 12.65f);
            glVertex2f(21.60, 12.75f);
            glVertex2f(21.50, 12.75f);
            glVertex2f(21.40, 12.5f);
            glEnd();
            break;
        case 2:
            glBegin(GL_POLYGON);
            glVertex2f(21.65, 12.25f);
            glVertex2f(21.9, 12.5f);
            glVertex2f(21.80, 12.75f);
            glVertex2f(21.70, 12.75f);
            glVertex2f(21.65, 12.65f);
            glVertex2f(21.60, 12.75f);
            glVertex2f(21.50, 12.75f);
            glVertex2f(21.40, 12.5f);
            glEnd();
            glBegin(GL_POLYGON);
            glVertex2f(22.65, 12.25f);
            glVertex2f(22.9, 12.5f);
            glVertex2f(22.80, 12.75f);
            glVertex2f(22.70, 12.75f);
            glVertex2f(22.65, 12.65f);
            glVertex2f(22.60, 12.75f);
            glVertex2f(22.50, 12.75f);
            glVertex2f(22.40, 12.5f);
            glEnd();
            break;
        case 3:
            glBegin(GL_POLYGON);
            glVertex2f(21.65, 12.25f);
            glVertex2f(21.9, 12.5f);
            glVertex2f(21.80, 12.75f);
            glVertex2f(21.70, 12.75f);
            glVertex2f(21.65, 12.65f);
            glVertex2f(21.60, 12.75f);
            glVertex2f(21.50, 12.75f);
            glVertex2f(21.40, 12.5f);
            glEnd();
            glBegin(GL_POLYGON);
            glVertex2f(22.65, 12.25f);
            glVertex2f(22.9, 12.5f);
            glVertex2f(22.80, 12.75f);
            glVertex2f(22.70, 12.75f);
            glVertex2f(22.65, 12.65f);
            glVertex2f(22.60, 12.75f);
            glVertex2f(22.50, 12.75f);
            glVertex2f(22.40, 12.5f);
            glEnd();
            glBegin(GL_POLYGON);
            glVertex2f(23.65, 12.25f);
            glVertex2f(23.9, 12.5f);
            glVertex2f(23.80, 12.75f);
            glVertex2f(23.70, 12.75f);
            glVertex2f(23.65, 12.65f);
            glVertex2f(23.60, 12.75f);
            glVertex2f(23.50, 12.75f);
            glVertex2f(23.40, 12.5f);
            glEnd();
        default:
            break;
    }
}
void Counter1(int counter){
    switch (counter) {
        case 0:
            glBegin(GL_LINE_LOOP);
            glVertex2f(7.0, 0.5);
            glVertex2f(7.5, 0.5);
            glVertex2f(7.5, 1.5);
            glVertex2f(7.0, 1.5);
            glEnd();
            break;
        case 1:
            glBegin(GL_LINES);
            glVertex2f(7.25, 0.5f);
            glVertex2f(7.25f, 1.5f);
            glEnd();
            break;
        case 2:
            glBegin(GL_LINE_STRIP);
            glVertex2f(7.5f, 0.5f);
            glVertex2f(7.0f, 0.5f);
            glVertex2f(7.0f, 1.0f);
            glVertex2f(7.5f, 1.0f);
            glVertex2f(7.5f, 1.5f);
            glVertex2f(7.0f, 1.5f);
            glEnd();
            break;
        case 3:
            glBegin(GL_LINE_STRIP);
            glVertex2f(7.0f, 0.5f);
            glVertex2f(7.5f, 0.5f);
            glVertex2f(7.5f, 1.5f);
            glVertex2f(7.0f, 1.5f);
            glEnd();
            glBegin(GL_LINES);
            glVertex2f(7.0f, 1.0f);
            glVertex2f(7.5f, 1.0f);
            glEnd();
            break;
        case 4:
            glBegin(GL_LINE_STRIP);
            glVertex2f(7.5f, 0.5f);
            glVertex2f(7.5f, 1.0f);
            glVertex2f(7.0f, 1.0f);
            glVertex2f(7.0f, 1.5f);
            glEnd();
            glBegin(GL_LINES);
            glVertex2f(7.5f, 1.0f);
            glVertex2f(7.5f, 1.5f);
            glEnd();
            break;
        case 5:
            glBegin(GL_LINE_STRIP);
            glVertex2f(7.0f, 0.5f);
            glVertex2f(7.5f, 0.5f);
            glVertex2f(7.5f, 1.0f);
            glVertex2f(7.0f, 1.0f);
            glVertex2f(7.0f, 1.5f);
            glVertex2f(7.5f, 1.5f);
            glEnd();
            break;
        case 6:
            glBegin(GL_LINE_LOOP);
            glVertex2f(7.0f, 0.5f);
            glVertex2f(7.5f, 0.5f);
            glVertex2f(7.5f, 1.0f);
            glVertex2f(7.0f, 1.0f);
            glEnd();
            glBegin(GL_LINES);
            glVertex2f(7.0f, 1.0f);
            glVertex2f(7.0f, 1.5f);
            glEnd();
            break;
        case 7:
            glBegin(GL_LINE_STRIP);
            glVertex2f(7.5, 0.5);
            glVertex2f(7.5, 1.5);
            glVertex2f(7.0, 1.5);
            glEnd();
            break;
        case 8:
            glBegin(GL_LINE_LOOP);
            glVertex2f(7.0, 0.5);
            glVertex2f(7.5f, 0.5f);
            glVertex2f(7.5f, 1.5f);
            glVertex2f(7.0f, 1.5f);
            glEnd();
            glBegin(GL_LINES);
            glVertex2f(7.0f, 1.0f);
            glVertex2f(7.5f, 1.0f);
            glEnd();
            break;
        case 9:
            glBegin(GL_LINE_LOOP);
            glVertex2f(7.0f, 1.0f);
            glVertex2f(7.5f, 1.0f);
            glVertex2f(7.5f, 1.5f);
            glVertex2f(7.0f, 1.5f);
            glEnd();
            glBegin(GL_LINES);
            glVertex2f(7.5f, 1.0f);
            glVertex2f(7.5f, 0.5f);
            glEnd();
            break;
        case 10:
            glBegin(GL_LINES);
            glVertex2f(7.0, 0.5f);
            glVertex2f(7.0f, 1.5f);
            glEnd();
            glBegin(GL_LINE_LOOP);
            glVertex2f(7.25, 0.5);
            glVertex2f(7.75, 0.5);
            glVertex2f(7.75, 1.5);
            glVertex2f(7.25, 1.5);
            glEnd();
            break;
        default:
            break;
    }
}
void Counter2(int counter){
    switch (counter) {
        case 0:
            glBegin(GL_LINE_LOOP);
            glVertex2f(16.5, 0.5);
            glVertex2f(17, 0.5);
            glVertex2f(17, 1.5);
            glVertex2f(16.5, 1.5);
            glEnd();
            break;
        case 1:
            glBegin(GL_LINES);
            glVertex2f(16.75, 0.5f);
            glVertex2f(16.75f, 1.5f);
            glEnd();
            break;
        case 2:
            glBegin(GL_LINE_STRIP);
            glVertex2f(17, 0.5f);
            glVertex2f(16.5, 0.5f);
            glVertex2f(16.5, 1.0f);
            glVertex2f(17, 1.0f);
            glVertex2f(17, 1.5f);
            glVertex2f(16.5, 1.5f);
            glEnd();
            break;
        case 3:
            glBegin(GL_LINE_STRIP);
            glVertex2f(16.5, 0.5f);
            glVertex2f(17, 0.5f);
            glVertex2f(17, 1.5f);
            glVertex2f(16.5, 1.5f);
            glEnd();
            glBegin(GL_LINES);
            glVertex2f(16.5, 1.0f);
            glVertex2f(17, 1.0f);
            glEnd();
            break;
        case 4:
            glBegin(GL_LINE_STRIP);
            glVertex2f(17, 0.5f);
            glVertex2f(17, 1.0f);
            glVertex2f(16.5, 1.0f);
            glVertex2f(16.5, 1.5f);
            glEnd();
            glBegin(GL_LINES);
            glVertex2f(17, 1.0f);
            glVertex2f(17, 1.5f);
            glEnd();
            break;
        case 5:
            glBegin(GL_LINE_STRIP);
            glVertex2f(16.5, 0.5f);
            glVertex2f(17, 0.5f);
            glVertex2f(17, 1.0f);
            glVertex2f(16.5, 1.0f);
            glVertex2f(16.5, 1.5f);
            glVertex2f(17, 1.5f);
            glEnd();
            break;
        case 6:
            glBegin(GL_LINE_LOOP);
            glVertex2f(16.5, 0.5f);
            glVertex2f(17, 0.5f);
            glVertex2f(17, 1.0f);
            glVertex2f(16.5, 1.0f);
            glEnd();
            glBegin(GL_LINES);
            glVertex2f(16.5, 1.0f);
            glVertex2f(16.5, 1.5f);
            glEnd();
            break;
        case 7:
            glBegin(GL_LINE_STRIP);
            glVertex2f(17, 0.5);
            glVertex2f(17, 1.5);
            glVertex2f(16.5, 1.5);
            glEnd();
            break;
        case 8:
            glBegin(GL_LINE_LOOP);
            glVertex2f(16.5, 0.5);
            glVertex2f(17, 0.5f);
            glVertex2f(17, 1.5f);
            glVertex2f(16.5, 1.5f);
            glEnd();
            glBegin(GL_LINES);
            glVertex2f(16.5, 1.0f);
            glVertex2f(17, 1.0f);
            glEnd();
            break;
        case 9:
            glBegin(GL_LINE_LOOP);
            glVertex2f(16.5, 1.0f);
            glVertex2f(17, 1.0f);
            glVertex2f(17, 1.5f);
            glVertex2f(16.5, 1.5f);
            glEnd();
            glBegin(GL_LINES);
            glVertex2f(17, 1.0f);
            glVertex2f(17, 0.5f);
            glEnd();
            break;
        case 10:
            glBegin(GL_LINES);
            glVertex2f(16.5, 0.5f);
            glVertex2f(16.5, 1.5f);
            glEnd();
            glBegin(GL_LINE_LOOP);
            glVertex2f(16.75, 0.5);
            glVertex2f(17.25, 0.5);
            glVertex2f(17.25, 1.5);
            glVertex2f(16.75, 1.5);
            glEnd();
            break;
        default:
            break;
    }
}

void timer(float XsizeT, float YsizeT){
    glBegin(GL_QUADS);
    glVertex2f(XsizeT+11.95, YsizeT -13 );
    glVertex2f(XsizeT + 12.05, YsizeT -13);
    glVertex2f(XsizeT + 12.05, YsizeT );
    glVertex2f(XsizeT + 11.95, YsizeT );
    glEnd();

    

}
void drawScene(void) {
     if (RunMode == 1) {
        ug += animation;
        if (ug >= 360) {
            ug = ug * 0;
        }
    }

    // Clear the rendering window
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	

    Xsize1 = Xsize1 - Xspeeds[0];
    if (Xsize1 - size <= Xmin-1 || Xsize1 + size >= Xmax+1) Xspeeds[0] = -Xspeeds[0]; // Reverse the direction
    drawQuad(Xsize1, Ysize1);
    Xsize2 = Xsize2 - Xspeeds[1];
    if (Xsize2 - size <= Xmin-1 || Xsize2 + size >= Xmax+1) Xspeeds[1] = -Xspeeds[1]; // Reverse the direction
    drawQuad(Xsize2, Ysize2);

	Xsize3 = Xsize3 - Xspeeds[2];
    if (Xsize3 - size <= Xmin-1 || Xsize3 + size >= Xmax+1) Xspeeds[2] = -Xspeeds[2]; // Reverse the direction
    drawQuad(Xsize3, Ysize3);

	Xsize4 = Xsize4 - Xspeeds[3];
    if (Xsize4 - size <= Xmin-1 || Xsize4 + size >= Xmax+1) Xspeeds[3] = -Xspeeds[3]; // Reverse the direction
    drawQuad(Xsize4, Ysize4);

	Xsize5 = Xsize5 - Xspeeds[4];
    if (Xsize5 - size <= Xmin-1 || Xsize5 + size >= Xmax+1) Xspeeds[4] = -Xspeeds[4]; // Reverse the direction
    drawQuad(Xsize5, Ysize5);

	Xsize6 = Xsize6 - Xspeeds[5];
    if (Xsize6 - size <= Xmin-1 || Xsize6 + size >= Xmax+1) Xspeeds[5] = -Xspeeds[5]; // Reverse the direction
    drawQuad(Xsize6, Ysize6);

	Xsize7 = Xsize7 - Xspeeds[6];
    if (Xsize7 - size <= Xmin-1 || Xsize7 + size >= Xmax+1) Xspeeds[6] = -Xspeeds[6]; // Reverse the direction
    drawQuad(Xsize7, Ysize7);

	Xsize8 = Xsize8 - Xspeeds[7];
    if (Xsize8 - size <= Xmin-1 || Xsize8 + size >= Xmax+1) Xspeeds[7] = -Xspeeds[7]; // Reverse the direction
    drawQuad(Xsize8, Ysize8);
	
	Xsize9 = Xsize9 - Xspeeds[8];
    if (Xsize9 - size <= Xmin-1 || Xsize9 + size >= Xmax+1) Xspeeds[8] = -Xspeeds[8]; // Reverse the direction
    drawQuad(Xsize9, Ysize9);
	Xsize10 = Xsize10 - Xspeeds[9];
    if (Xsize10 - size <= Xmin-1 || Xsize10 + size >= Xmax+1) Xspeeds[9] = -Xspeeds[9]; // Reverse the direction
    drawQuad(Xsize10, Ysize10);
	Xsize11 = Xsize11 + Xspeeds[10];
    if (Xsize11 - size <= Xmin-1 || Xsize11 + size >= Xmax+1) Xspeeds[10] = -Xspeeds[10]; // Reverse the direction
    drawQuad(Xsize11, Ysize11);

	Xsize12 = Xsize12 + Xspeeds[11];
    if (Xsize12 - size <= Xmin-1 || Xsize12 + size >= Xmax+1) Xspeeds[11] = -Xspeeds[11]; // Reverse the direction
    drawQuad(Xsize12, Ysize12);

	Xsize13 = Xsize13 + Xspeeds[12];
    if (Xsize13 - size <= Xmin-1 || Xsize13 + size >= Xmax+1) Xspeeds[12] = -Xspeeds[12]; // Reverse the direction
    drawQuad(Xsize12, Ysize12);

	Xsize14 = Xsize14 + Xspeeds[13];
    if (Xsize14 - size <= Xmin-1 || Xsize14 + size >= Xmax+1) Xspeeds[13] = -Xspeeds[13]; // Reverse the direction
    drawQuad(Xsize14, Ysize14);

	Xsize15 = Xsize15 + Xspeeds[14];
    if (Xsize15 - size <= Xmin-1 || Xsize15 + size >= Xmax+1) Xspeeds[14] = -Xspeeds[14]; // Reverse the direction
    drawQuad(Xsize15, Ysize15);

	Xsize16 = Xsize16 + Xspeeds[15];
    if (Xsize16 - size <= Xmin-1 || Xsize16 + size >= Xmax+1) Xspeeds[15] = -Xspeeds[15]; // Reverse the direction
    drawQuad(Xsize16, Ysize16);

	Xsize17 = Xsize17 + Xspeeds[16];
    if (Xsize17 - size <= Xmin-1 || Xsize17 + size >= Xmax+1) Xspeeds[16] = -Xspeeds[16]; // Reverse the direction
    drawQuad(Xsize17, Ysize17);

	Xsize18 = Xsize18 + Xspeeds[17];
    if (Xsize18 - size <= Xmin-1 || Xsize18 + size >= Xmax+1) Xspeeds[17] = -Xspeeds[17]; // Reverse the direction
    drawQuad(Xsize18, Ysize18);

	Xsize19 = Xsize19 + Xspeeds[18];
    if (Xsize19 - size <= Xmin-1 || Xsize19 + size >= Xmax+1) Xspeeds[18] = -Xspeeds[18]; // Reverse the direction
    drawQuad(Xsize19, Ysize19);

	Xsize20 = Xsize20 + Xspeeds[19];
    if (Xsize20 - size <= Xmin-1 || Xsize20 + size >= Xmax+1) Xspeeds[19] = -Xspeeds[19]; // Reverse the direction
    drawQuad(Xsize20, Ysize20);


	Xsize21 = Xsize21 - Xspeeds[20];
    if (Xsize21 - size <= Xmin-1 || Xsize21 + size >= Xmax+1) Xspeeds[20] = -Xspeeds[20]; // Reverse the direction
    drawQuad(Xsize21, Ysize21);

	Xsize22 = Xsize22 - Xspeeds[21];
    if (Xsize22 - size <= Xmin-1 || Xsize22 + size >= Xmax+1) Xspeeds[21] = -Xspeeds[21]; // Reverse the direction
    drawQuad(Xsize22, Ysize22);

	Xsize23 = Xsize23 - Xspeeds[22];
    if (Xsize23 - size <= Xmin-1 || Xsize23 + size >= Xmax+1) Xspeeds[22] = -Xspeeds[22]; // Reverse the direction
    drawQuad(Xsize23, Ysize23);

	Xsize24 = Xsize24 - Xspeeds[23];
    if (Xsize24 - size <= Xmin-1 || Xsize24 + size >= Xmax+1) Xspeeds[23] = -Xspeeds[23]; // Reverse the direction
    drawQuad(Xsize24, Ysize24);

	Xsize25 = Xsize25 - Xspeeds[24];
    if (Xsize25 - size <= Xmin-1 || Xsize25 + size >= Xmax+1) Xspeeds[24] = -Xspeeds[24]; // Reverse the direction
    drawQuad(Xsize25, Ysize25);

	Xsize26 = Xsize26 - Xspeeds[25];
    if (Xsize26 - size <= Xmin-1 || Xsize26 + size >= Xmax+1) Xspeeds[25] = -Xspeeds[25]; // Reverse the direction
    drawQuad(Xsize26, Ysize26);

	Xsize27 = Xsize27 - Xspeeds[26];
    if (Xsize27 - size <= Xmin-1 || Xsize27 + size >= Xmax+1) Xspeeds[26] = -Xspeeds[26]; // Reverse the direction
    drawQuad(Xsize27, Ysize27);

	Xsize28 = Xsize28 - Xspeeds[27];
    if (Xsize28 - size <= Xmin-1 || Xsize28 + size >= Xmax+1) Xspeeds[27] = -Xspeeds[27]; // Reverse the direction
    drawQuad(Xsize28, Ysize28);

	Xsize29 = Xsize29 - Xspeeds[28];
    if (Xsize29 - size <= Xmin-1 || Xsize29 + size >= Xmax+1) Xspeeds[28] = -Xspeeds[28]; // Reverse the direction
    drawQuad(Xsize29, Ysize29);

	Xsize30 = Xsize30 - Xspeeds[29];
    if (Xsize30 - size <= Xmin-1 || Xsize30 + size >= Xmax+1) Xspeeds[29] = -Xspeeds[29]; // Reverse the direction
    drawQuad(Xsize30, Ysize30);

	Xsize31 = Xsize31 + Xspeeds[30];
    if (Xsize31 - size <= Xmin-1 || Xsize31 + size >= Xmax+1) Xspeeds[30] = -Xspeeds[30]; // Reverse the direction
    drawQuad(Xsize31, Ysize31);

	Xsize32 = Xsize32 + Xspeeds[31];
    if (Xsize32 - size <= Xmin-1 || Xsize32 + size >= Xmax+1) Xspeeds[31] = -Xspeeds[31]; // Reverse the direction
    drawQuad(Xsize32, Ysize32);

	Xsize33 = Xsize33 + Xspeeds[32];
    if (Xsize33 - size <= Xmin-1 || Xsize33 + size >= Xmax+1) Xspeeds[32] = -Xspeeds[32]; // Reverse the direction
    drawQuad(Xsize33, Ysize33);

	Xsize34 = Xsize34 + Xspeeds[33];
    if (Xsize34 - size <= Xmin-1 || Xsize34 + size >= Xmax+1) Xspeeds[33] = -Xspeeds[33]; // Reverse the direction
    drawQuad(Xsize34, Ysize34);

	Xsize35 = Xsize35 + Xspeeds[34];
    if (Xsize35 - size <= Xmin-1 || Xsize35 + size >= Xmax+1) Xspeeds[34] = -Xspeeds[34]; // Reverse the direction
    drawQuad(Xsize35, Ysize35);

	Xsize36 = Xsize36 + Xspeeds[35];
    if (Xsize36 - size <= Xmin-1 || Xsize36 + size >= Xmax+1) Xspeeds[35] = -Xspeeds[35]; // Reverse the direction
    drawQuad(Xsize36, Ysize36);

	Xsize37 = Xsize37 + Xspeeds[36];
    if (Xsize37 - size <= Xmin-1 || Xsize37 + size >= Xmax+1) Xspeeds[36] = -Xspeeds[36]; // Reverse the direction
    drawQuad(Xsize37, Ysize37);

	Xsize38 = Xsize38 + Xspeeds[37];
    if (Xsize38 - size <= Xmin-1 || Xsize38 + size >= Xmax+1) Xspeeds[37] = -Xspeeds[37]; // Reverse the direction
    drawQuad(Xsize38, Ysize38);

	Xsize39 = Xsize39 + Xspeeds[38];
    if (Xsize39 - size <= Xmin-1 || Xsize39 + size >= Xmax+1) Xspeeds[38] = -Xspeeds[38]; // Reverse the direction
    drawQuad(Xsize39, Ysize39);

	Xsize40 = Xsize40 + Xspeeds[39];
    if (Xsize40 - size <= Xmin-1 || Xsize40 + size >= Xmax+1) Xspeeds[39] = -Xspeeds[39]; // Reverse the direction
    drawQuad(Xsize40, Ysize40);

	Xsize41 = Xsize41 + Xspeeds[40];
    if (Xsize41 - size <= Xmin-1 || Xsize41 + size >= Xmax+1) Xspeeds[40] = -Xspeeds[40]; // Reverse the direction
    drawQuad(Xsize41, Ysize41);

	Xsize42 = Xsize42 + Xspeeds[41];
    if (Xsize42 - size <= Xmin-1 || Xsize42 + size >= Xmax+1) Xspeeds[41] = -Xspeeds[41]; // Reverse the direction
    drawQuad(Xsize42, Ysize42);

	Xsize43 = Xsize43 + Xspeeds[42];
    if (Xsize43 - size <= Xmin-1 || Xsize43 + size >= Xmax+1) Xspeeds[42] = -Xspeeds[42]; // Reverse the direction
    drawQuad(Xsize43, Ysize43);

	Xsize44 = Xsize44 + Xspeeds[43];
    if (Xsize44 - size <= Xmin-1 || Xsize44 + size >= Xmax+1) Xspeeds[43] = -Xspeeds[43]; // Reverse the direction
    drawQuad(Xsize44, Ysize44);

	Xsize45 = Xsize45 + Xspeeds[44];
    if (Xsize45 - size <= Xmin-1 || Xsize45 + size >= Xmax+1) Xspeeds[44] = -Xspeeds[44]; // Reverse the direction
    drawQuad(Xsize45, Ysize45);

	Xsize46 = Xsize46 - Xspeeds[45];
    if (Xsize46 - size <= Xmin-1 || Xsize46 + size >= Xmax+1) Xspeeds[45] = -Xspeeds[45]; // Reverse the direction
    drawQuad(Xsize46, Ysize46);

	Xsize47 = Xsize47 - Xspeeds[46];
    if (Xsize47 - size <= Xmin-1 || Xsize47 + size >= Xmax+1) Xspeeds[46] = -Xspeeds[46]; // Reverse the direction
    drawQuad(Xsize47, Ysize47);

	Xsize48 = Xsize48 - Xspeeds[47];
    if (Xsize48 - size <= Xmin-1 || Xsize48 + size >= Xmax+1) Xspeeds[47] = -Xspeeds[47]; // Reverse the direction
    drawQuad(Xsize48, Ysize48);

	Xsize49 = Xsize49 - Xspeeds[48];
    if (Xsize49 - size <= Xmin-1 || Xsize49 + size >= Xmax+1) Xspeeds[48] = -Xspeeds[48]; // Reverse the direction
    drawQuad(Xsize49, Ysize49);

	Xsize50 = Xsize50 - Xspeeds[49];
    if (Xsize50 - size <= Xmin-1 || Xsize50 + size >= Xmax+1) Xspeeds[49] = -Xspeeds[49]; // Reverse the direction
    drawQuad(Xsize50, Ysize50);


	drawPlane1();
    drawPlane2();
    handleMovement();
    Counter1(counter1);
    Counter2(counter2);
    

    YsizeT = YsizeT - XspeedT;
    timer(XsizeT, YsizeT);
    if(YsizeT < -0.2){
        YsizeT = 13;
        XsizeT = 0;
        XsizeP1 = 0.0;
        XsizeP2 = 0.0;
        YsizeP1 = 0.0;
        YsizeP2 = 0.0;
        counter1 = 0;
        counter2 = 0;
        countdown1 = 3;
        countdown2 = 3;
    }
    checkCollision(Xsize1, Ysize1, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize1, Ysize1, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize2, Ysize2, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize2, Ysize2, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize3, Ysize3, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize3, Ysize3, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize4, Ysize4, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize4, Ysize4, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize5, Ysize5, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize5, Ysize5, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize6, Ysize6, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize6, Ysize6, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize7, Ysize7, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize7, Ysize7, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize8, Ysize8, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize8, Ysize8, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize9, Ysize9, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize9, Ysize9, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize10, Ysize10, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize10, Ysize10, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize11, Ysize11, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize11, Ysize11, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize12, Ysize12, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize12, Ysize12, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize13, Ysize13, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize13, Ysize13, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize14, Ysize14, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize14, Ysize14, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize15, Ysize15, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize15, Ysize15, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize16, Ysize16, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize16, Ysize16, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize17, Ysize17, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize17, Ysize17, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize18, Ysize18, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize18, Ysize18, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize19, Ysize19, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize19, Ysize19, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize20, Ysize20, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize20, Ysize20, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize21, Ysize21, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize21, Ysize21, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize22, Ysize22, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize22, Ysize22, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize23, Ysize23, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize23, Ysize23, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize24, Ysize24, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize24, Ysize24, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize25, Ysize25, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize25, Ysize25, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize26, Ysize26, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize26, Ysize26, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);
    
    checkCollision(Xsize27, Ysize27, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize27, Ysize27, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize28, Ysize28, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize28, Ysize28, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize29, Ysize29, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize29, Ysize29, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize30, Ysize30, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize30, Ysize30, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize31, Ysize31, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize31, Ysize31, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize32, Ysize32, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize32, Ysize32, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize33, Ysize33, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize33, Ysize33, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize34, Ysize34, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize34, Ysize34, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize35, Ysize35, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize35, Ysize35, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize36, Ysize36, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize36, Ysize36, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize37, Ysize37, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize37, Ysize37, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize38, Ysize38, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize38, Ysize38, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize39, Ysize39, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize39, Ysize39, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize40, Ysize40, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize40, Ysize40, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize41, Ysize41, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize41, Ysize41, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize42, Ysize42, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize42, Ysize42, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize43, Ysize43, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize43, Ysize43, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize44, Ysize44, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize44, Ysize44, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize45, Ysize45, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize45, Ysize45, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize46, Ysize46, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize46, Ysize46, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize47, Ysize47, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize47, Ysize47, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize48, Ysize48, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize48, Ysize48, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize49, Ysize49, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize49, Ysize49, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);

    checkCollision(Xsize50, Ysize50, size, 7.25 + XsizeP2, 2.0 + YsizeP2, 2);
    checkCollision(Xsize50, Ysize50, size, 16.75 + XsizeP1, 2.0 + YsizeP1, 1);
    livesone(countdown1);
    livestwo(countdown2);
    

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
int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    // Get the monitor's resolution
    int screenWidth = 1920; // Replace with the actual screen width of your monitor
    int screenHeight = 1080; // Replace with the actual screen height of your monitor

    // Calculate the window's aspect ratio
    double aspectRatio = (double)screenWidth / screenHeight;
	for(int i=0; i<=50; i++){
		Xspeeds[i] = Xspeed;
	}
	
    // The image is not animated so single buffering is OK.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

    // Window position (from top corner), and size (width and height)
    glutInitWindowPosition(0, 0); // Set window position to top-left corner
    glutInitWindowSize(screenWidth, screenHeight); // Set window size to screen resolution
    glutCreateWindow("SimpleDraw - Press space bar to toggle images");

    // Initialize OpenGL as we like it..
    initRendering();
	glutKeyboardFunc(myKeyboardFunc);     // Handles "normal" ascii symbols
glutKeyboardUpFunc(keyUp);            // Handles key release
glutSpecialFunc(mySpecialKeyFunc);    // Handles arrow keys
glutSpecialUpFunc(keyUpSpecial);
    // Set up the callback function for resizing windows
    glutReshapeFunc(resizeWindow);

    // Call this for background processing
    // glutIdleFunc( myIdleFunction );

    // call this whenever window needs redrawing
    glutDisplayFunc(drawScene);

    fprintf(stdout, "Press space bar to toggle images; escape button to quit.\n");

    // Start the main loop.  glutMainLoop never returns.
    glutMainLoop();

    return (0); // This line is never reached.
}
