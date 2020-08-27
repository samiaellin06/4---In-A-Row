#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include <windows.h>
#include <glut.h>
#include <MMSystem.h>

#define PI (2*acos(0.0))

double CloudX = 0, CloudY;
double ClockA = 0;
int CloudState = 0;
int cpidx;

int gamestart=0;
int turn = 2;

int a[8][8];

int x[5] = {0,0,0,0,0};
int z[5] = {0,0,0,0,0};
int q[5] = {0,0,0,0,0};
int r[5] = {0,0,0,0,0};
int s[5] = {0,0,0,0,0};
int t[5] = {0,0,0,0,0};
int u[5] = {0,0,0,0,0};

int red=0;
int yellow=0;

int r5c1 = 0,r5c2 = 0, r5c3 = 0, r5c4 = 0, r5c5 = 0, r5c6 = 0, r5c7 = 0;
int r4c1 = 0,r4c2 = 0, r4c3 = 0, r4c4 = 0, r4c5 = 0, r4c6 = 0, r4c7 = 0;
int r3c1 = 0,r3c2 = 0, r3c3 = 0, r3c4 = 0, r3c5 = 0, r3c6 = 0, r3c7 = 0;
int r2c1 = 0,r2c2 = 0, r2c3 = 0, r2c4 = 0, r2c5 = 0, r2c6 = 0, r2c7 = 0;
int r1c1 = 0,r1c2 = 0, r1c3 = 0, r1c4 = 0, r1c5 = 0, r1c6 = 0, r1c7 = 0;

struct point
{
	double mx,y,z;
};

struct point2d
{
    double mx, y;
};

struct point2d cp[400];

void showTextLarge(char text[], double r, double g, double b, int x, int y, int z)
{
    glColor3f(r, g, b);
    glRasterPos3f( x , y , z);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
}

void Board()
{
    glBegin(GL_QUADS);
    glColor3f(83/255.0, 123/255.0, 189/255.0);
    glVertex2i(-165,-167);
    glVertex2i(125,-167);
    glColor3f(156/255.0, 180/255.0, 219/255.0);
    glVertex2i(125,117);
    glVertex2i(-165,117);

    glColor3f(83/255.0, 123/255.0, 189/255.0);
    glVertex2i(-200,-220);
    glVertex2i(-200,-200);
    glVertex2i(155,-200);
    glVertex2i(155,-220);

    glColor3f(156/255.0, 180/255.0, 219/255.0);
    glVertex2i(-200,-220);
    glVertex2i(-200,-200);
    glVertex2i(-165,-147);
    glVertex2i(-165,-167);

    glColor3f(156/255.0, 180/255.0, 219/255.0);
    glVertex2i(155,-200);
    glVertex2i(155,-220);
    glVertex2i(125,-167);
    glVertex2i(125,-147);

    glColor3f(0/255.0, 0/255.0, 100/255.0);
    glVertex2i(-165,-167);
    glVertex2i(125,-167);
    glVertex2i(155,-220);
    glVertex2i(-200,-220);
    glEnd();
}

void Hole(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;

	glBegin(GL_POLYGON); {
		for(i = 0; i < 100; i++)
		{
			angle = 2 * PI * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}
    } glEnd();
}

void Coin()
{
    glColor3f(1,1,0.0);
    Hole(10,4);
    glPushMatrix();
    glTranslatef(0,-1,0);
    Hole(10,4);
    glTranslatef(0,-1,0);
    Hole(10,4);
    glTranslatef(0,-1,0);
    Hole(10,4);
    glPopMatrix();
}

void Game()
{
    glPushMatrix();
    glTranslatef(-7,30,0);
    glScalef(0.65,0.65,0);

    //1st Column
    if (r5c1 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(-145,-135,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(x[0] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(-145,-135,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(-145,-135,0);
        Hole(18,25);
        glPopMatrix();
	}

	if (r4c1 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(-145,-80,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(x[1] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(-145,-80,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(-145,-80,0);
        Hole(18,25);
        glPopMatrix();
	}

	if (r3c1 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(-145,-25,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(x[2] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(-145,-25,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(-145,-25,0);
        Hole(18,25);
        glPopMatrix();
	}

	if (r2c1 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(-145,30,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(x[3] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(-145,30,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(-145,30,0);
        Hole(18,25);
        glPopMatrix();
	}

	if (r1c1 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(-145,85,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(x[4] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(-145,85,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(-145,85,0);
        Hole(18,25);
        glPopMatrix();
	}

	//2nd column
    if (r5c2 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(-105,-135,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(z[0] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(-105,-135,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(-105,-135,0);
        Hole(18,25);
        glPopMatrix();
	}

	if (r4c2 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(-105,-80,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(z[1] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(-105,-80,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(-105,-80,0);
        Hole(18,25);
        glPopMatrix();
	}

	if (r3c2 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(-105,-25,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(z[2] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(-105,-25,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(-105,-25,0);
        Hole(18,25);
        glPopMatrix();
	}

	if (r2c2 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(-105,30,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(z[3] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(-105,30,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(-105,30,0);
        Hole(18,25);
        glPopMatrix();
	}

	if (r1c2 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(-105,85,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(z[4] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(-105,85,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(-105,85,0);
        Hole(18,25);
        glPopMatrix();
	}

	//3rd Column
	if (r5c3 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(-65,-135,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(q[0] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(-65,-135,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(-65,-135,0);
        Hole(18,25);
        glPopMatrix();
	}

	if (r4c3 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(-65,-80,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(q[1] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(-65,-80,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(-65,-80,0);
        Hole(18,25);
        glPopMatrix();
	}

	if (r3c3 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(-65,-25,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(q[2] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(-65,-25,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(-65,-25,0);
        Hole(18,25);
        glPopMatrix();
	}

	if (r2c3 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(-65,30,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(q[3] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(-65,30,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(-65,30,0);
        Hole(18,25);
        glPopMatrix();
	}

	if (r1c3 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(-65,85,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(q[4] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(-65,85,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(-65,85,0);
        Hole(18,25);
        glPopMatrix();
	}

	//4th Column
	if (r5c4 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(-25,-135,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(r[0] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(-25,-135,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(-25,-135,0);
        Hole(18,25);
        glPopMatrix();
	}

	if (r4c4 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(-25,-80,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(r[1] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(-25,-80,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(-25,-80,0);
        Hole(18,25);
        glPopMatrix();
	}

	if (r3c4 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(-25,-25,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(r[2] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(-25,-25,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(-25,-25,0);
        Hole(18,25);
        glPopMatrix();
	}

	if (r2c4 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(-25,30,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(r[3] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(-25,30,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(-25,30,0);
        Hole(18,25);
        glPopMatrix();
	}

	if (r1c4 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(-25,85,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(r[4] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(-25,85,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(-25,85,0);
        Hole(18,25);
        glPopMatrix();
	}

	//5th Column
	if (r5c5 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(15,-135,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(s[0] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(15,-135,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(15,-135,0);
        Hole(18,25);
        glPopMatrix();
	}

	if (r4c5 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(15,-80,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(s[1] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(15,-80,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(15,-80,0);
        Hole(18,25);
        glPopMatrix();
	}

	if (r3c5 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(15,-25,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(s[2] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(15,-25,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(15,-25,0);
        Hole(18,25);
        glPopMatrix();
	}

	if (r2c5 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(15,30,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(s[3] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(15,30,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(15,30,0);
        Hole(18,25);
        glPopMatrix();
	}

	if (r1c5 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(15,85,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(s[4] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(15,85,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(15,85,0);
        Hole(18,25);
        glPopMatrix();
	}

	//6th Column
	if (r5c6 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(55,-135,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(t[0] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(55,-135,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(55,-135,0);
        Hole(18,25);
        glPopMatrix();
	}

	if (r4c6 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(55,-80,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(t[1] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(55,-80,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(55,-80,0);
        Hole(18,25);
        glPopMatrix();
	}

	if (r3c6 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(55,-25,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(t[2] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(55,-25,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(55,-25,0);
        Hole(18,25);
        glPopMatrix();
	}

	if (r2c6 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(55,30,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(t[3] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(55,30,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(55,30,0);
        Hole(18,25);
        glPopMatrix();
	}

	if (r1c6 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(55,85,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(t[4] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(55,85,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(55,85,0);
        Hole(18,25);
        glPopMatrix();
	}

	//7th Column
	if (r5c7 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(95,-135,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(u[0] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(95,-135,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(95,-135,0);
        Hole(18,25);
        glPopMatrix();
	}

	if (r4c7 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(95,-80,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(u[1] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(95,-80,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(95,-80,0);
        Hole(18,25);
        glPopMatrix();
	}

	if (r3c7 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(95,-25,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(u[2] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(95,-25,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(95,-25,0);
        Hole(18,25);
        glPopMatrix();
	}

	if (r2c7 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(95,30,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(u[3] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(95,30,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(95,30,0);
        Hole(18,25);
        glPopMatrix();
	}

	if (r1c7 == 0)
    {
        glPushMatrix();
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glTranslatef(95,85,0);
        Hole(18,25);
        glPopMatrix();
	}

	else if(u[4] == 1)
    {
		glPushMatrix();
		glColor3f(1, 0, 0);
        glTranslatef(95,85,0);
        Hole(18,25);
        glPopMatrix();
	}

	else
    {
		glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslatef(95,85,0);
        Hole(18,25);
        glPopMatrix();
	}

    glPopMatrix();

    glPushMatrix();
    glTranslatef(-109,-80,0);
    Coin();
    glTranslatef(21,0,0);
    Coin();
    glTranslatef(21,0,0);
    Coin();
    glTranslatef(21,0,0);
    Coin();
    glTranslatef(21,0,0);
    Coin();
    glTranslatef(21,0,0);
    Coin();
    glTranslatef(21,0,0);
    Coin();
    glTranslatef(21,0,0);
    Coin();
    glTranslatef(21,0,0);
    Coin();
    glTranslatef(11,-11,0);
    Coin();
    glTranslatef(-21,0,0);
    Coin();
    glTranslatef(-21,0,0);
    Coin();
    glTranslatef(-21,0,0);
    Coin();
    glTranslatef(-21,0,0);
    Coin();
    glTranslatef(-21,0,0);
    Coin();
    glTranslatef(-21,0,0);
    Coin();
    glTranslatef(-21,0,0);
    Coin();
    glTranslatef(-21,0,0);
    Coin();
    glTranslatef(-21,0,0);
    Coin();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,30,0);
    glScalef(0.65,0.65,0);
    Board();
    glPopMatrix();
}

void Table()
{
    glBegin(GL_QUADS);
        glColor3f(204/255.0, 51/255.0, 0/255.0);
        glVertex2d(-160,-130);
        glVertex2d(-120,-70);
        glVertex2d(120,-70);
        glVertex2d(160,-130);

        glColor3f(87/255.0, 36/255.0, 16/255.0);
        glVertex2d(-160,-130);
        glVertex2d(160,-130);
        glVertex2d(160,-150);
        glVertex2d(-160,-150);

        glColor3f(204/255.0, 51/255.0, 0/255.0);
        glVertex2d(-160,-150);
        glVertex2d(-140,-150);
        glVertex2d(-140,-180);
        glVertex2d(-160,-180);

        glColor3f(87/255.0, 36/255.0, 16/255.0);
        glVertex2d(-140,-150);
        glVertex2d(-135,-150);
        glVertex2d(-135,-180);
        glVertex2d(-140,-180);

        glColor3f(204/255.0, 51/255.0, 0/255.0);
        glVertex2d(160,-150);
        glVertex2d(140,-150);
        glVertex2d(140,-180);
        glVertex2d(160,-180);

        glColor3f(87/255.0, 36/255.0, 16/255.0);
        glVertex2d(140,-150);
        glVertex2d(135,-150);
        glVertex2d(135,-180);
        glVertex2d(140,-180);
    glEnd();
}

void Circle (float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;

	glBegin(GL_POLYGON);
    {
		for(i = 0; i < 100; i++)
		{
			angle = 2 * PI * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}
    }
	glEnd();
}

void Cloud()
{
    glColor3f(1, 1, 1);
    Circle(8, 10);
    glPushMatrix();
    glTranslatef(9, -6, 0);
    Circle(8, 10);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(9, -16, 0);
    Circle(8, 10);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(16, -12, 0);
    Circle(8, 10);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-5, -15, 0);
    Circle(8, 10);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-9, -6, 0);
    Circle(8, 10);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-16, -12, 0);
    Circle(8, 10);
    glPopMatrix();
}

void Window()
{
    glBegin(GL_QUADS);
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glVertex2d(10,20);
        glVertex2d(10,150);
        glVertex2d(68,150);
        glVertex2d(68,20);

        glColor3f(204/255.0, 51/255.0, 0/255.0);
        glVertex2d(115,20);
        glVertex2d(115,160);
        glVertex2d(118,160);
        glVertex2d(118,20);

        glVertex2d(68,20);
        glVertex2d(68,160);
        glVertex2d(72,160);
        glVertex2d(72,20);

        glVertex2d(163,20);
        glVertex2d(163,160);
        glVertex2d(170,160);
        glVertex2d(170,20);

        glVertex2d(68,85);
        glVertex2d(68,88);
        glVertex2d(168,88);
        glVertex2d(168,85);
    glEnd();

    glPushMatrix();
    glTranslatef(CloudX, CloudY, 0);
    glPushMatrix();
    glTranslatef(98, 120, 0);
    glColor3f(1, 1, 128/255.0);
    Cloud();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(90, 120, 0);
    glColor3f(1, 1, 128/255.0);
    Circle (17,20);
    glPopMatrix();

    glBegin(GL_POINTS);
    glVertex2d(130,130);
    glVertex2d(142,121);
    glVertex2d(130,30);
    glVertex2d(134,50);
    glVertex2d(140,65);
    glVertex2d(125,70);
    glVertex2d(100,120);
    glVertex2d(151,100);
    glVertex2d(147,135);
    glVertex2d(132,100);
    glVertex2d(153,60);
    glVertex2d(146,37);
    glVertex2d(80,50);
    glVertex2d(92,67);
    glVertex2d(100,44);
    glVertex2d(90,35);
    glVertex2d(105,60);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0, 0, 64/255.0);
        glVertex2d(72,25);
        glVertex2d(72,155);
        glVertex2d(163,155);
        glVertex2d(163,25);

        glColor3f(204/255.0, 51/255.0, 0/255.0);
        glVertex2d(68,20);
        glVertex2d(68,160);
        glVertex2d(168,160);
        glVertex2d(168,20);
    glEnd();
}

void Room()
{
    glLineWidth(5.0);
    glBegin(GL_LINES);
        glColor3f(204/255.0, 51/255.0, 0/255.0);
        glVertex2d(-130,-80);
        glVertex2d(170,-80);

        glVertex2d(-130,-80);
        glVertex2d(-130,170);

        glVertex2d(-130,-80);
        glVertex2d(-170,-140);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glVertex2d(-170,-140);
        glColor3f(51/255.0, 51/255.0, 10/255.0);
        glVertex2d(-170,170);
        glColor3f(255/255.0, 255/255.0, 185/255.0);
        glVertex2d(-130,170);
        glVertex2d(-130,-80);

        glVertex2d(-130,-80);
        glVertex2d(-130,170);
        glVertex2d(170,170);
        glVertex2d(170,-80);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(49/255.0, 49/255.0, 49/255.0);
        glVertex2d(-130,-80);
        glColor3f(89/255.0, 89/255.0, 89/255.0);
        glVertex2d(-170,-140);
        glVertex2d(-170,-200);
        glVertex2d(170,-200);
        glColor3f(49/255.0, 49/255.0, 49/255.0);
        glVertex2d(170,-80);
    glEnd();
}

void ClockHand()
{
    glColor3f(0, 0, 0);
    glLineWidth(0.9);
    glBegin(GL_LINES);
        glVertex2d(0,12);
        glVertex2d(0,-12);
    glEnd();
}

void ClockHandRotate()
{
    glPushMatrix();
    glTranslatef(-90, 130, 0);
    glRotatef(ClockA,0,0 ,1);
    ClockHand();
    glPopMatrix();
}

void Clock()
{
    glPushMatrix();
    glTranslatef(-90, 130, 0);
    glBegin(GL_LINES);
        glColor3f(0, 0, 0);
        glVertex2d(0,13);
        glVertex2d(0,17);

        glVertex2d(0,-13);
        glVertex2d(0,-17);

        glVertex2d(13,0);
        glVertex2d(15,0);

        glVertex2d(-13,0);
        glVertex2d(-15,0);
    glEnd();

    glColor3f(1, 1, 1);
    Circle(16,18);
    glColor3f(0, 0, 64/255.0);
    Circle(20,22);
    glPopMatrix();
}

void RedWins()
{
    glPushMatrix();
    glTranslated(-50,-15,0);
    showTextLarge("Player Red Wins", 1, 1, 1, 16, 22, 0);

    glColor3f(1,1,1);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2d(12,10);
    glVertex2d(62,10);

    glVertex2d(12,40);
    glVertex2d(62,40);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex2i(0,4);
    glVertex2i(78,4);
    glVertex2i(78,50);
    glVertex2i(0,50);

    glColor3f(148/255.0,12/255.0,18/255.0);
    glVertex2i(0,0);
    glVertex2i(80,0);
    glVertex2i(80,50);
    glVertex2i(0,50);
    glEnd();
    glPopMatrix();
}

void YelowWins()
{
    glPushMatrix();
    glTranslated(-50,-15,0);
    showTextLarge("Player Yellow Wins", 1, 1, 1, 12, 22, 0);

    glColor3f(1,1,1);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2d(12,10);
    glVertex2d(62,10);

    glVertex2d(12,40);
    glVertex2d(62,40);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex2i(0,4);
    glVertex2i(78,4);
    glVertex2i(78,50);
    glVertex2i(0,50);

    glColor3f(185/255.0,175/255.0,0/255.0);
    glVertex2i(0,0);
    glVertex2i(80,0);
    glVertex2i(80,50);
    glVertex2i(0,50);
    glEnd();
    glPopMatrix();
}

void DrawGame()
{
    glPushMatrix();
    glTranslated(-50,-15,0);
    showTextLarge("Game Drawn", 1, 1, 1, 20, 22, 0);

    glColor3f(1,1,1);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2d(12,10);
    glVertex2d(62,10);

    glVertex2d(12,40);
    glVertex2d(62,40);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex2i(0,4);
    glVertex2i(78,4);
    glColor3f(1,0,0);
    glVertex2i(78,50);
    glVertex2i(0,50);

    glColor3f(185/255.0,175/255.0,0/255.0);
    glVertex2i(0,0);
    glVertex2i(80,0);
    glColor3f(1,0,0);
    glVertex2i(80,50);
    glVertex2i(0,50);
    glEnd();
    glPopMatrix();
}

void background()
{
    //PlaySound(TEXT("SoundTrack.wav"), NULL, SND_SYNC);

    if (//row
		r5c1== 1 && r4c1 == 1 && r3c1 == 1 && r2c1 == 1 || r4c1 == 1 && r3c1 == 1 && r2c1 == 1 && r1c1==1 ||
		r5c2== 1 && r4c2 == 1 && r3c2 == 1 && r2c2 == 1 || r4c2 == 1 && r3c2 == 1 && r2c2 == 1 && r1c2==1 ||
		r5c3== 1 && r4c3 == 1 && r3c3 == 1 && r2c3 == 1 || r4c3 == 1 && r3c3 == 1 && r2c3 == 1 && r1c3==1 ||
		r5c4== 1 && r4c4 == 1 && r3c4 == 1 && r2c4 == 1 || r4c4 == 1 && r3c4 == 1 && r2c4 == 1 && r1c4==1 ||
		r5c5== 1 && r4c5 == 1 && r3c5 == 1 && r2c5 == 1 || r4c5 == 1 && r3c5 == 1 && r2c5 == 1 && r1c5==1 ||
		r5c6== 1 && r4c6 == 1 && r3c6 == 1 && r2c6 == 1 || r4c6 == 1 && r3c6 == 1 && r2c6 == 1 && r1c6==1 ||
		r5c7== 1 && r4c7 == 1 && r3c7 == 1 && r2c7 == 1 || r4c7 == 1 && r3c7 == 1 && r2c7 == 1 && r1c7==1 ||
		//column
		r1c1== 1 && r1c2 == 1 && r1c3 == 1 && r1c4 == 1 || r1c2 == 1 && r1c3 == 1 && r1c4 == 1 && r1c5==1 || r1c3== 1 && r1c4 == 1 && r1c5 == 1 && r1c6 == 1 || r1c4 == 1 && r1c5 == 1 && r1c6 == 1 && r1c7==1 ||
		r2c1== 1 && r2c2 == 1 && r2c3 == 1 && r2c4 == 1 || r2c2 == 1 && r2c3 == 1 && r2c4 == 1 && r2c5==1 || r2c3== 1 && r2c4 == 1 && r2c5 == 1 && r2c6 == 1 || r2c4 == 1 && r2c5 == 1 && r2c6 == 1 && r2c7==1 ||
		r3c1== 1 && r3c2 == 1 && r3c3 == 1 && r3c4 == 1 || r3c2 == 1 && r3c3 == 1 && r3c4 == 1 && r3c5==1 || r3c3== 1 && r3c4 == 1 && r3c5 == 1 && r3c6 == 1 || r3c4 == 1 && r3c5 == 1 && r3c6 == 1 && r3c7==1 ||
		r4c1== 1 && r4c2 == 1 && r4c3 == 1 && r4c4 == 1 || r4c2 == 1 && r4c3 == 1 && r4c4 == 1 && r4c5==1 || r4c3== 1 && r4c4 == 1 && r4c5 == 1 && r4c6 == 1 || r4c4 == 1 && r4c5 == 1 && r4c6 == 1 && r4c7==1 ||
        r5c1== 1 && r5c2 == 1 && r5c3 == 1 && r5c4 == 1 || r5c2 == 1 && r5c3 == 1 && r5c4 == 1 && r5c5==1 || r5c3== 1 && r5c4 == 1 && r5c5 == 1 && r5c6 == 1 || r5c4 == 1 && r5c5 == 1 && r5c6 == 1 && r5c7==1 ||
		//crisscross
		r2c1== 1 && r3c2 == 1 && r4c3 == 1 && r5c4 == 1 || r1c1== 1 && r2c2 == 1 && r3c3 == 1 && r4c4 ==1 || r2c2== 1 && r3c3 == 1 && r4c4 == 1 && r5c5 == 1 || r1c2== 1 && r2c3 == 1 && r3c4 == 1 && r4c5 ==1 ||
		r2c3== 1 && r3c4 == 1 && r4c5 == 1 && r5c6 == 1 || r1c3== 1 && r2c4 == 1 && r3c5 == 1 && r4c6 ==1 || r2c4== 1 && r3c5 == 1 && r4c6 == 1 && r5c7 == 1 || r1c4== 1 && r2c5 == 1 && r3c6 == 1 && r4c7 ==1 ||
		r2c7== 1 && r3c6 == 1 && r4c5 == 1 && r5c4 == 1 || r1c7== 1 && r2c6 == 1 && r3c5 == 1 && r4c4 ==1 || r2c6== 1 && r3c5 == 1 && r4c4 == 1 && r5c3 == 1 || r1c6== 1 && r2c5 == 1 && r3c4 == 1 && r4c3 ==1 ||
		r2c5== 1 && r3c4 == 1 && r4c3 == 1 && r5c2 == 1 || r1c5== 1 && r2c4 == 1 && r3c3 == 1 && r4c2 ==1 || r2c4== 1 && r3c3 == 1 && r4c2 == 1 && r5c1 == 1 || r1c4== 1 && r2c3 == 1 && r3c2 == 1 && r4c1 ==1
		)
	{
			red=1;
	}

	if (//row
		r5c1== 2 && r4c1 == 2 && r3c1 == 2 && r2c1 == 2 || r4c1 == 2 && r3c1 == 2 && r2c1 == 2 && r1c1==2 ||
		r5c2== 2 && r4c2 == 2 && r3c2 == 2 && r2c2 == 2 || r4c2 == 2 && r3c2 == 2 && r2c2 == 2 && r1c2==2 ||
		r5c3== 2 && r4c3 == 2 && r3c3 == 2 && r2c3 == 2 || r4c3 == 2 && r3c3 == 2 && r2c3 == 2 && r1c3==2 ||
		r5c4== 2 && r4c4 == 2 && r3c4 == 2 && r2c4 == 2 || r4c4 == 2 && r3c4 == 2 && r2c4 == 2 && r1c4==2 ||
		r5c5== 2 && r4c5 == 2 && r3c5 == 2 && r2c5 == 2 || r4c5 == 2 && r3c5 == 2 && r2c5 == 2 && r1c5==2 ||
		r5c6== 2 && r4c6 == 2 && r3c6 == 2 && r2c6 == 2 || r4c6 == 2 && r3c6 == 2 && r2c6 == 2 && r1c6==2 ||
		r5c7== 2 && r4c7 == 2 && r3c7 == 2 && r2c7 == 2 || r4c7 == 2 && r3c7 == 2 && r2c7 == 2 && r1c7==2 ||
		//column
		r1c1== 2 && r1c2 == 2 && r1c3 == 2 && r1c4 == 2 || r1c2 == 2 && r1c3 == 2 && r1c4 == 2 && r1c5==2 || r1c3== 2 && r1c4 == 2 && r1c5 == 2 && r1c6 == 2 || r1c4 == 2 && r1c5 == 2 && r1c6 == 2 && r1c7==2 ||
		r2c1== 2 && r2c2 == 2 && r2c3 == 2 && r2c4 == 2 || r2c2 == 2 && r2c3 == 2 && r2c4 == 2 && r2c5==2 || r2c3== 2 && r2c4 == 2 && r2c5 == 2 && r2c6 == 2 || r2c4 == 2 && r2c5 == 2 && r2c6 == 2 && r2c7==2 ||
		r3c1== 2 && r3c2 == 2 && r3c3 == 2 && r3c4 == 2 || r3c2 == 2 && r3c3 == 2 && r3c4 == 2 && r3c5==2 || r3c3== 2 && r3c4 == 2 && r3c5 == 2 && r3c6 == 2 || r3c4 == 2 && r3c5 == 2 && r3c6 == 2 && r3c7==2 ||
		r4c1== 2 && r4c2 == 2 && r4c3 == 2 && r4c4 == 2 || r4c2 == 2 && r4c3 == 2 && r4c4 == 2 && r4c5==2 || r4c3== 2 && r4c4 == 2 && r4c5 == 2 && r4c6 == 2 || r4c4 == 2 && r4c5 == 2 && r4c6 == 2 && r4c7==2 ||
        r5c1== 2 && r5c2 == 2 && r5c3 == 2 && r5c4 == 2 || r5c2 == 2 && r5c3 == 2 && r5c4 == 2 && r5c5==2 || r5c3== 2 && r5c4 == 2 && r5c5 == 2 && r5c6 == 2 || r5c4 == 2 && r5c5 == 2 && r5c6 == 2 && r5c7==2 ||
		//crisscross
		r2c1== 2 && r3c2 == 2 && r4c3 == 2 && r5c4 == 2 || r1c1== 2 && r2c2 == 2 && r3c3 == 2 && r4c4 ==2 || r2c2== 2 && r3c3 == 2 && r4c4 == 2 && r5c5 == 2 || r1c2== 2 && r2c3 == 2 && r3c4 == 2 && r4c5 ==2 ||
		r2c3== 2 && r3c4 == 2 && r4c5 == 2 && r5c6 == 2 || r1c3== 2 && r2c4 == 2 && r3c5 == 2 && r4c6 ==2 || r2c4== 2 && r3c5 == 2 && r4c6 == 2 && r5c7 == 2 || r1c4== 2 && r2c5 == 2 && r3c6 == 2 && r4c7 ==2 ||
		r2c7== 2 && r3c6 == 2 && r4c5 == 2 && r5c4 == 2 || r1c7== 2 && r2c6 == 2 && r3c5 == 2 && r4c4 ==2 || r2c6== 2 && r3c5 == 2 && r4c4 == 2 && r5c3 == 2 || r1c6== 2 && r2c5 == 2 && r3c4 == 2 && r4c3 ==2 ||
		r2c5== 2 && r3c4 == 2 && r4c3 == 2 && r5c2 == 2 || r1c5== 2 && r2c4 == 2 && r3c3 == 2 && r4c2 ==2 || r2c4== 2 && r3c3 == 2 && r4c2 == 2 && r5c1 == 2 || r1c4== 2 && r2c3 == 2 && r3c2 == 2 && r4c1 ==2
		)
	{

			yellow=1;
	}

	if (r5c1 != 0 && r5c2 != 0 && r5c3 != 0 && r5c4 != 0 && r5c5 != 0 && r5c6 != 0 && r5c7 != 0 &&
        r4c1 != 0 && r4c2 != 0 && r4c3 != 0 && r4c4 != 0 && r4c5 != 0 && r4c6 != 0 && r4c7 != 0 &&
        r3c1 != 0 && r3c2 != 0 && r3c3 != 0 && r3c4 != 0 && r3c5 != 0 && r3c6 != 0 && r3c7 != 0 &&
        r2c1 != 0 && r2c2 != 0 && r2c3 != 0 && r2c4 != 0 && r2c5 != 0 && r2c6 != 0 && r2c7 != 0 &&
        r1c1 != 0 && r1c2 != 0 && r1c3 != 0 && r1c4 != 0 && r1c5 != 0 && r1c6 != 0 && r1c7 != 0)
        {
            DrawGame();
            glBegin(GL_QUADS);
            glColor3f(0,0,0);
            glVertex2i(-170,-170);
            glVertex2i(170,-170);
            glVertex2i(170,170);
            glVertex2i(-170,170);
            glEnd();
            gamestart = 2;
        }


	if (red == 1)
    {
        //PlaySound("Winning.wav", NULL, SND_FILENAME| SND_ASYNC);
        RedWins();
        glBegin(GL_QUADS);
        glColor3f(0,0,0);
        glVertex2i(-170,-170);
        glVertex2i(170,-170);
        glVertex2i(170,170);
        glVertex2i(-170,170);
        glEnd();
        gamestart = 2;
    }

    if (yellow == 1)
    {
        //PlaySound("Winning.wav", NULL, SND_FILENAME| SND_ASYNC);
        YelowWins();
        glBegin(GL_QUADS);
        glColor3f(0,0,0);
        glVertex2i(-170,-170);
        glVertex2i(170,-170);
        glVertex2i(170,170);
        glVertex2i(-170,170);
        glEnd();
        gamestart = 2;
    }

    showTextLarge("RED", 1, 0, 0, -50, 150, 0);
    showTextLarge("(Left Click)", 1, 0, 0, -58, 140, 0);
    showTextLarge("VS", 0, 0, 1, -7, 150, 0);
    showTextLarge("YELLOW", 1, 1, 0, 25, 150, 0);
    showTextLarge("(Right Click)", 1, 1, 0, 21, 140, 0);
    showTextLarge("***Choose The Column You Want To Put Your Color And Match 4 Colors Vertically, Horizontally Or Diagonally To Win***", 1, 1, 1, -160, -142, 0);

    Game();
    ClockHandRotate();
    Clock();
    Table();
    Window();
    Room();
}

void CoverHole()
{
    glPushMatrix();
    glTranslatef(53,-25,0);
    glScalef(0.6,0.6,0);

    //1st column
    glPushMatrix();
    glTranslatef(-145,85,0);
    glColor3f(255/255.0, 255/255.0, 185/255.0);
    Hole(18,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-145,30,0);
    glColor3f(255/255.0, 255/255.0, 185/255.0);
    Hole(18,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-145,-25,0);
    glColor3f(255/255.0, 255/255.0, 185/255.0);
    Hole(18,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-145,-80,0);
    glColor3f(255/255.0, 255/255.0, 185/255.0);
    Hole(18,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-145,-135,0);
    glColor3f(1,1,0);
    Hole(18,25);
    glPopMatrix();

    //2nd column
    glPushMatrix();
    glTranslatef(-105,85,0);
    glColor3f(255/255.0, 255/255.0, 185/255.0);
    Hole(18,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-105,30,0);
    glColor3f(255/255.0, 255/255.0, 185/255.0);
    Hole(18,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-105,-25,0);
    glColor3f(255/255.0, 255/255.0, 185/255.0);
    Hole(18,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-105,-80,0);
    glColor3f(1,0,0);
    Hole(18,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-105,-135,0);
    glColor3f(1,1,0);
    Hole(18,25);
    glPopMatrix();

    //3rd column
    glPushMatrix();
    glTranslatef(-65,85,0);
    glColor3f(255/255.0, 255/255.0, 185/255.0);
    Hole(18,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-65,30,0);
    glColor3f(255/255.0, 255/255.0, 185/255.0);
    Hole(18,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-65,-25,0);
    glColor3f(1,0,0);
    Hole(18,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-65,-80,0);
    glColor3f(1,1,0);
    Hole(18,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-65,-135,0);
    glColor3f(1,0,0);
    Hole(18,25);
    glPopMatrix();

    //4th column
    glPushMatrix();
    glTranslatef(-25,85,0);
    glColor3f(255/255.0, 255/255.0, 185/255.0);
    Hole(18,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-25,30,0);
    glColor3f(1,1,0);
    Hole(18,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-25,-25,0);
    glColor3f(1,0,0);
    Hole(18,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-25,-80,0);
    glColor3f(1,0,0);
    Hole(18,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-25,-135,0);
    glColor3f(1,1,0);
    Hole(18,25);
    glPopMatrix();

    //5th column
    glPushMatrix();
    glTranslatef(15,85,0);
    glColor3f(255/255.0, 255/255.0, 185/255.0);
    Hole(18,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(15,30,0);
    glColor3f(255/255.0, 255/255.0, 185/255.0);
    Hole(18,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(15,-25,0);
    glColor3f(1,1,0);
    Hole(18,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(15,-80,0);
    glColor3f(1,0,0);
    Hole(18,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(15,-135,0);
    glColor3f(1,1,0);
    Hole(18,25);
    glPopMatrix();

    //6th column
    glPushMatrix();
    glTranslatef(55,85,0);
    glColor3f(255/255.0, 255/255.0, 185/255.0);
    Hole(18,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(55,30,0);
    glColor3f(255/255.0, 255/255.0, 185/255.0);
    Hole(18,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(55,-25,0);
    glColor3f(1,0,0);
    Hole(18,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(55,-80,0);
    glColor3f(1,1,0);
    Hole(18,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(55,-135,0);
    glColor3f(1,0,0);
    Hole(18,25);
    glPopMatrix();

    //7th column
    glPushMatrix();
    glTranslatef(95,85,0);
    glColor3f(255/255.0, 255/255.0, 185/255.0);
    Hole(18,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(95,30,0);
    glColor3f(255/255.0, 255/255.0, 185/255.0);
    Hole(18,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(95,-25,0);
    glColor3f(255/255.0, 255/255.0, 185/255.0);
    Hole(18,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(95,-80,0);
    glColor3f(255/255.0, 255/255.0, 185/255.0);
    Hole(18,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(95,-135,0);
    glColor3f(1,1,0);
    Hole(18,25);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(50,-25,0);
    glScalef(0.6,0.6,0);
    Board();
    glPopMatrix();
}

void Cover()
{
    glPushMatrix();
    glTranslatef(-100,80,0);
    glBegin(GL_QUADS);
    //4
    glColor3f(1,1,0);
    glVertex2i(0,0);
    glVertex2i(0,50);
    glVertex2i(5,50);
    glVertex2i(5,0);

    glColor3f(1,1,0);
    glVertex2i(-10,25);
    glVertex2i(-10,50);
    glVertex2i(-5,50);
    glVertex2i(-5,25);

    glColor3f(1,1,0);
    glVertex2i(-10,25);
    glVertex2i(-10,30);
    glVertex2i(10,30);
    glVertex2i(10,25);

    //-
    glColor3f(1,1,0);
    glVertex2i(20,25);
    glVertex2i(20,30);
    glVertex2i(30,30);
    glVertex2i(30,25);

    //iN- i
    glColor3f(1,1,0);
    glVertex2i(40,0);
    glVertex2i(40,32);
    glVertex2i(45,32);
    glVertex2i(45,0);

    //N
    glColor3f(1,1,0);
    glVertex2i(50,0);
    glVertex2i(50,50);
    glVertex2i(55,50);
    glVertex2i(55,0);

    glColor3f(1,1,0);
    glVertex2i(65,0);
    glVertex2i(65,50);
    glVertex2i(70,50);
    glVertex2i(70,0);

    glColor3f(1,1,0);
    glVertex2i(50,50);
    glVertex2i(55,50);
    glVertex2i(70,0);
    glVertex2i(65,0);

    //-
    glColor3f(1,1,0);
    glVertex2i(80,25);
    glVertex2i(80,30);
    glVertex2i(90,30);
    glVertex2i(90,25);

    //A
    glColor3f(1,1,0);
    glVertex2i(103,50);
    glVertex2i(105,50);
    glVertex2i(100,0);
    glVertex2i(95,0);

    glColor3f(1,1,0);
    glVertex2i(103,50);
    glVertex2i(105,50);
    glVertex2i(115,0);
    glVertex2i(110,0);

    glColor3f(1,1,0);
    glVertex2i(100,20);
    glVertex2i(100,25);
    glVertex2i(110,25);
    glVertex2i(110,20);

    //-
    glColor3f(1,1,0);
    glVertex2i(120,25);
    glVertex2i(120,30);
    glVertex2i(130,30);
    glVertex2i(130,25);

    //Row
    //R
    glColor3f(1,1,0);
    glVertex2i(140,0);
    glVertex2i(140,50);
    glVertex2i(145,50);
    glVertex2i(145,0);

    glColor3f(1,1,0);
    glVertex2i(140,45);
    glVertex2i(140,50);
    glVertex2i(155,50);
    glVertex2i(155,45);

    glColor3f(1,1,0);
    glVertex2i(140,30);
    glVertex2i(140,25);
    glVertex2i(155,25);
    glVertex2i(155,30);

    glColor3f(1,1,0);
    glVertex2i(152,25);
    glVertex2i(152,50);
    glVertex2i(155,50);
    glVertex2i(155,25);

    glColor3f(1,1,0);
    glVertex2i(140,25);
    glVertex2i(140,35);
    glVertex2i(155,10);
    glVertex2i(155,0);

    //W
    glColor3f(1,1,0);
    glVertex2i(180,0);
    glVertex2i(180,50);
    glVertex2i(185,50);
    glVertex2i(185,0);


    glColor3f(1,1,0);
    glVertex2i(190,50);
    glVertex2i(195,50);
    glVertex2i(185,0);
    glVertex2i(180,0);

    glColor3f(1,1,0);
    glVertex2i(190,50);
    glVertex2i(195,50);
    glVertex2i(205,0);
    glVertex2i(200,0);

    glColor3f(1,1,0);
    glVertex2i(200,0);
    glVertex2i(200,50);
    glVertex2i(205,50);
    glVertex2i(205,0);
    glEnd();

    //i
    glPushMatrix();
    glTranslatef(42,40,0);
    Hole(4,5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(167,25,0);
    glColor3f(148/255.0,12/255.0,18/255.0);
    Hole(7,23);
    glColor3f(1,1,0);
    Hole(11,26);
    glPopMatrix();
    glPopMatrix();

    showTextLarge("Press 's' To Start The Game", 148/255.0, 12/255.0, 18/255.0, -140, -30, 0);

    CoverHole();

    glPushMatrix();
    glTranslatef(-150,-15,0);
    glColor3f(148/255.0,12/255.0,18/255.0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2d(0,0);
    glVertex2d(90,0);

    glVertex2d(0,5);
    glVertex2d(90,5);

    glVertex2d(0,-25);
    glVertex2d(90,-25);

    glVertex2d(0,-30);
    glVertex2d(90,-30);
    glEnd();
    glPopMatrix();

    glBegin(GL_QUADS);
    //Background
    glColor3f(148/255.0,12/255.0,18/255.0);
    glVertex2i(-170,50);
    glVertex2i(170,50);
    glVertex2i(170,170);
    glVertex2i(-170,170);

    glColor3f(255/255.0, 255/255.0, 185/255.0);
    glVertex2i(-170,50);
    glVertex2i(170,50);
    glVertex2i(170,-170);
    glVertex2i(-170,-170);
    glEnd();

}

void animate()
{
    ClockA-=0.1;

	if (CloudState == 0)
    {
        CloudX+=0.01;
    }

    if (CloudX > 100)
    {
        CloudState = 1;
    }

    if (CloudState == 1)
    {
        CloudX = -50;
        CloudState = 0;
    }

	glutPostRedisplay();
}

void display()
{
	//clear the display
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//load the correct matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);
	//initialize the matrix
	glLoadIdentity();

	//3. Which direction is the camera's UP direction?
	gluLookAt(0,0,200,	0,0,0,	0,1,0);

	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);

	if (gamestart == 1 || gamestart == 2)
    {
        background();
    }

    if (gamestart == 0)
    {
        Cover();
    }

	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glutSwapBuffers();
}

void init()
{
    for(int j = 0; j <= 7; j++)
    {
		a[6][j] = 1;
	}

	//clear the screen
	glClearColor(0,0,0,0);

	//load the PROJECTION matrix
	glMatrixMode(GL_PROJECTION);

	//initialize the matrix
	glLoadIdentity();

	//give PERSPECTIVE parameters
	gluPerspective(80,	1,	1,	1000.0);
}

void keyboardListener(unsigned char key, int f,int y){
	switch(key){

		case 's':
		    gamestart = 1;

			break;

        case 'x':
		    CloudX = 0, CloudY;
            ClockA = 0;
            CloudState = 0;
            cpidx;
            gamestart=0;

            for(int j = 0; j <= 7; j++)
            {
                a[6][j] = 1;
            }

            /*for(int j = 0; j < 5; j++)
            {
                x[j] = 0;
                z[j] = 0;
                q[j] = 0;
                r[j] = 0;
                s[j] = 0;
                t[j] = 0;
                u[j] = 0;
            }*/

            x[0] = 0;

            red=0;
            yellow=0;
            turn=2;

            r5c1 = 0, r5c2 = 0, r5c3 = 0, r5c4 = 0, r5c5 = 0, r5c6 = 0, r5c7 = 0;
            r4c1 = 0, r4c2 = 0, r4c3 = 0, r4c4 = 0, r4c5 = 0, r4c6 = 0, r4c7 = 0;
            r3c1 = 0, r3c2 = 0, r3c3 = 0, r3c4 = 0, r3c5 = 0, r3c6 = 0, r3c7 = 0;
            r2c1 = 0, r2c2 = 0, r2c3 = 0, r2c4 = 0, r2c5 = 0, r2c6 = 0, r2c7 = 0;
            r1c1 = 0, r1c2 = 0, r1c3 = 0, r1c4 = 0, r1c5 = 0, r1c6 = 0, r1c7 = 0;

            break;

		default:
			break;
	}
}

void mouseListener(int button, int state, int mx, int y){	//x, y is the x-y of the screen (2D)
	switch(button){
		case GLUT_LEFT_BUTTON:
			if(state == GLUT_DOWN)
            {
                // 2 times?? in ONE click? -- solution is checking DOWN or UP
                /*
                std::cout <<"x:"<< mx << " y:" << y << std::endl;

                cp[cpidx].mx = (double)mx;
                cp[cpidx].y = (double)(600 - y);
                std::cout <<"x:"<< cp[cpidx].mx << " y.a:" << cp[cpidx].y << std::endl;
                cpidx++;
                */

                //PlaySound("CoinDrop.wav", NULL, SND_FILENAME| SND_ASYNC);

                //1st Column
                if (turn % 2 == 0 && gamestart == 1)
                {
                    turn = 1;

                    if(mx >= 200 && mx <= 305)
                    {
                        for(int i = 1; i <= 6; i++) {
                            if(a[i][1] == 1) {
                                if(i == 1 && a[0][1] == 0)
                                {

                                }
                                else if(i == 2 && a[1][1] == 0)
                                {
                                    r1c1 = 1;
                                    a[i-1][1] = 1;
                                    x[4]=1;
                                }

                                else if(i == 3 && a[2][1] == 0)
                                {
                                    r2c1 = 1;
                                    a[i-1][1] = 1;
                                    x[3]=1;
                                }

                                else if(i == 4 && a[3][1] == 0)
                                {
                                    r3c1 = 1;
                                    a[i-1][1] = 1;
                                    x[2]=1;
                                }

                                else if(i == 5 && a[4][1] == 0)
                                {
                                    r4c1 = 1;
                                    a[i-1][1] = 1;
                                    x[1]=1;
                                }

                                else if(i == 6 && a[5][1] == 0)
                                {
                                    r5c1 = 1;
                                    a[i-1][1] = 1;
                                    x[0]=1;
                                }

                            }
                        }
                    }

                    //2nd Column
                    if(mx >= 310 && mx <= 405)
                    {
                        for(int i = 1; i <= 6; i++)
                        {
                            if(a[i][2] == 1)
                            {
                                if(i == 1 && a[0][2] == 0)
                                {

                                }

                                else if(i == 2 && a[1][2] == 0)
                                {
                                    r1c2 = 1;
                                    a[i-1][2] = 1;
                                    z[4]=1;
                                }

                                else if(i == 3 && a[2][2] == 0)
                                {
                                    r2c2 = 1;
                                    a[i-1][2] = 1;
                                    z[3]=1;
                                }

                                else if(i == 4 && a[3][2] == 0)
                                {
                                    r3c2 = 1;
                                    a[i-1][2] = 1;
                                    z[2]=1;
                                }

                                else if(i == 5 && a[4][2] == 0)
                                {
                                    r4c2 = 1;
                                    a[i-1][2] = 1;
                                    z[1]=1;
                                }

                                else if(i == 6 && a[5][2] == 0)
                                {
                                    r5c2 = 1;
                                    a[i-1][2] = 1;
                                    z[0]=1;
                                }
                            }
                        }
                    }

                    //3rd Column
                    if((mx >= 410 && mx <= 505))
                    {
                        for(int i = 1; i <= 6; i++)
                        {
                            if(a[i][3] == 1)
                            {
                                if(i == 1 && a[0][3] == 0)
                                {

                                }

                                else if(i == 2 && a[1][3] == 0)
                                {
                                    r1c3 = 1;
                                    a[i-1][3] = 1;
                                    q[4]=1;
                                }

                                else if(i == 3 && a[2][3] == 0)
                                {
                                    r2c3 = 1;
                                    a[i-1][3] = 1;
                                    q[3]=1;
                                }

                                else if(i == 4 && a[3][3] == 0)
                                {
                                    r3c3 = 1;
                                    a[i-1][3] = 1;
                                    q[2]=1;
                                }

                                else if(i == 5 && a[4][3] == 0)
                                {
                                    r4c3 = 1;
                                    a[i-1][3] = 1;
                                    q[1]=1;
                                }

                                else if(i == 6 && a[5][3] == 0)
                                {
                                    r5c3 = 1;
                                    a[i-1][3] = 1;
                                    q[0]=1;
                                }
                            }
                        }
                    }


                    //4th Column
                    if(mx >= 515 && mx <= 605)
                    {
                        for(int i = 1; i <= 6; i++)
                        {
                            if(a[i][4] == 1)
                            {
                                if(i == 1 && a[0][4] == 0)
                                {

                                }

                                else if(i == 2 && a[1][4] == 0)
                                {
                                    r1c4 = 1;
                                    a[i-1][4] = 1;
                                    r[4]=1;
                                }

                                else if(i == 3 && a[2][4] == 0)
                                {
                                    r2c4 = 1;
                                    a[i-1][4] = 1;
                                    r[3]=1;
                                }

                                else if(i == 4 && a[3][4] == 0)
                                {
                                    r3c4 = 1;
                                    a[i-1][4] = 1;
                                    r[2]=1;
                                }

                                else if(i == 5 && a[4][4] == 0)
                                {
                                    r4c4 = 1;
                                    a[i-1][4] = 1;
                                    r[1]=1;
                                }

                                else if(i == 6 && a[5][4] == 0)
                                {
                                    r5c4 = 1;
                                    a[i-1][4] = 1;
                                    r[0]=1;
                                }
                            }
                        }
                    }


                    //5th Column
                    if(mx >= 613 && mx <= 706)
                    {
                        for(int i = 1; i <= 6; i++)
                        {
                            if(a[i][5] == 1)
                            {
                                if(i == 1 && a[0][5] == 0)
                                {

                                }

                                else if(i == 2 && a[1][5] == 0)
                                {
                                    r1c5 = 1;
                                    a[i-1][5] = 1;
                                    s[4]=1;
                                }
                                else if(i == 3 && a[2][5] == 0)
                                {
                                    r2c5 = 1;
                                    a[i-1][5] = 1;
                                    s[3]=1;
                                }

                                else if(i == 4 && a[3][5] == 0)
                                {
                                    r3c5 = 1;
                                    a[i-1][5] = 1;
                                    s[2]=1;
                                }

                                else if(i == 5 && a[4][5] == 0)
                                {
                                    r4c5 = 1;
                                    a[i-1][5] = 1;
                                    s[1]=1;
                                }

                                else if(i == 6 && a[5][5] == 0)
                                {
                                    r5c5 = 1;
                                    a[i-1][5] = 1;
                                    s[0]=1;
                                }
                              }
                        }
                    }


                    //6th Column
                    if(mx >= 715 && mx <= 807)
                        {
                        for(int i = 1; i <= 6; i++)
                        {
                            if(a[i][6] == 1)
                            {
                                if(i == 1 && a[0][6] == 0)
                                {

                                }

                                else if(i == 2 && a[1][6] == 0)
                                {
                                    r1c6 = 1;
                                    a[i-1][6] = 1;
                                    t[4]=1;
                                }

                                else if(i == 3 && a[2][6] == 0)
                                {
                                    r2c6 = 1;
                                    a[i-1][6] = 1;
                                    t[3]=1;
                                }

                                else if(i == 4 && a[3][6] == 0)
                                {
                                    r3c6 = 1;
                                    a[i-1][6] = 1;
                                    t[2]=1;
                                }

                                else if(i == 5 && a[4][6] == 0)
                                {
                                    r4c6 = 1;
                                    a[i-1][6] = 1;
                                    t[1]=1;
                                }

                                else if(i == 6 && a[5][6] == 0)
                                {
                                    r5c6 = 1;
                                    a[i-1][6] = 1;
                                    t[0]=1;
                                }
                              }
                        }
                    }
                    //7 Column
                    if(mx >= 815 && mx <= 910)
                    {
                        for(int i = 1; i <= 6; i++)
                        {
                            if(a[i][7] == 1)
                            {
                                if(i == 1 && a[0][7] == 0)
                                {

                                }

                                else if(i == 2 && a[1][7] == 0)
                                {
                                    r1c7 = 1;
                                    a[i-1][7] = 1;
                                    u[4]=1;
                                }

                                else if(i == 3 && a[2][7] == 0)
                                {
                                    r2c7 = 1;
                                    a[i-1][7] = 1;
                                    u[3]=1;
                                }

                                else if(i == 4 && a[3][7] == 0)
                                {
                                    r3c7 = 1;
                                    a[i-1][7] = 1;
                                    u[2]=1;
                                }

                                else if(i == 5 && a[4][7] == 0)
                                {
                                    r4c7 = 1;
                                    a[i-1][7] = 1;
                                    u[1]=1;
                                }

                                else if(i == 6 && a[5][7] == 0)
                                {
                                    r5c7 = 1;
                                    a[i-1][7] = 1;
                                    u[0]=1;
                                }
                              }
                        }
                    }
                }



        }
        break;


		case GLUT_RIGHT_BUTTON:
			if(state == GLUT_DOWN)
            {
                // 2 times?? in ONE click? -- solution is checking DOWN or UP
                /*
                std::cout <<"x:"<< mx << " y:" << y << std::endl;

                cp[cpidx].mx = (double)mx;
                cp[cpidx].y = (double)(600 - y);
                std::cout <<"x:"<< cp[cpidx].mx << " y.a:" << cp[cpidx].y << std::endl;
                cpidx++;
                */

                //PlaySound("CoinDrop.wav", NULL, SND_FILENAME| SND_ASYNC);

                //1st Column
                if (turn % 2 != 0 && gamestart == 1)
                {
                    turn = 2;

                    if(mx >= 195 && mx <= 310)
                    {
                        for(int i = 1; i <= 6; i++)
                        {
                            if(a[i][1] == 1)
                            {
                                if(i == 1 && a[0][1] == 0)
                                {

                                }

                                else if(i == 2 && a[1][1] == 0)
                                {
                                    r1c1 = 2;
                                    a[i-1][1] = 1;
                                    x[4]=2;
                                }

                                else if(i == 3 && a[2][1] == 0)
                                {
                                    r2c1 = 2;
                                    a[i-1][1] = 1;
                                    x[3]=2;
                                }

                                else if(i == 4 && a[3][1] == 0)
                                {
                                    r3c1 = 2;
                                    a[i-1][1] = 1;
                                    x[2]=2;
                                }

                                else if(i == 5 && a[4][1] == 0)
                                {
                                    r4c1 = 2;
                                    a[i-1][1] = 1;
                                    x[1]=2;
                                }

                                else if(i == 6 && a[5][1] == 0)
                                {
                                    r5c1 = 2;
                                    a[i-1][1] = 1;
                                    x[0]=2;
                                }
                            }
                        }
                    }

                    //2nd Column
                    if(mx >= 310 && mx <= 405)
                    {
                        for(int i = 1; i <= 6; i++)
                        {
                            if(a[i][2] == 1)
                            {
                                if(i == 1 && a[0][2] == 0)
                                {

                                }

                                else if(i == 2 && a[1][2] == 0)
                                {
                                    r1c2 = 2;
                                    a[i-1][2] = 1;
                                    z[4]=2;
                                }

                                else if(i == 3 && a[2][2] == 0)
                                {
                                    r2c2 = 2;
                                    a[i-1][2] = 1;
                                    z[3]=2;
                                }

                                else if(i == 4 && a[3][2] == 0)
                                {
                                    r3c2 = 2;
                                    a[i-1][2] = 1;
                                    z[2]=2;
                                }

                                else if(i == 5 && a[4][2] == 0)
                                {
                                    r4c2 = 2;
                                    a[i-1][2] = 1;
                                    z[1]=2;
                                }

                                else if(i == 6 && a[5][2] == 0)
                                {
                                    r5c2 = 2;
                                    a[i-1][2] = 1;
                                    z[0]=2;
                                }
                              }
                            }
                    }

                    //3rd Column
                    if(mx >= 410 && mx <= 505)
                    {
                        for(int i = 1; i <= 6; i++)
                        {
                            if(a[i][3] == 1)
                            {
                                if(i == 1 && a[0][3] == 0)
                                {

                                }

                                else if(i == 2 && a[1][3] == 0)
                                {
                                    r1c3 = 2;
                                    a[i-1][3] = 1;
                                    q[4]=2;
                                }

                                else if(i == 3 && a[2][3] == 0)
                                {
                                    r2c3 = 2;
                                    a[i-1][3] = 1;
                                    q[3]=2;
                                }

                                else if(i == 4 && a[3][3] == 0)
                                {
                                    r3c3 = 2;
                                    a[i-1][3] = 1;
                                    q[2]=2;
                                }

                                else if(i == 5 && a[4][3] == 0)
                                {
                                    r4c3 = 2;
                                    a[i-1][3] = 1;
                                    q[1]=2;
                                }

                                else if(i == 6 && a[5][3] == 0)
                                {
                                    r5c3 = 2;
                                    a[i-1][3] = 1;
                                    q[0]=2;
                                }
                              }
                            }
                    }

                    //4th Column
                    if(mx >= 515 && mx <= 605)
                    {
                        for(int i = 1; i <= 6; i++)
                        {
                            if(a[i][4] == 1)
                            {
                                if(i == 1 && a[0][4] == 0)
                                {

                                }
                                else if(i == 2 && a[1][4] == 0)
                                {
                                    r1c4 = 2;
                                    a[i-1][4] = 1;
                                    r[4]=2;
                                }

                                else if(i == 3 && a[2][4] == 0)
                                {
                                        r2c4 = 2;
                                        a[i-1][4] = 1;
                                        r[3]=2;
                                }

                                else if(i == 4 && a[3][4] == 0)
                                {
                                    r3c4 = 2;
                                    a[i-1][4] = 1;
                                    r[2]=2;
                                }

                                else if(i == 5 && a[4][4] == 0)
                                {
                                    r4c4 = 2;
                                    a[i-1][4] = 1;
                                    r[1]=2;
                                }

                                else if(i == 6 && a[5][4] == 0)
                                {
                                    r5c4 = 2;
                                    a[i-1][4] = 1;
                                    r[0]=2;
                                }
                              }
                            }
                    }

                    //5th column
                    if(mx >= 613 && mx <= 706)
                    {
                        for(int i = 1; i <= 6; i++)
                        {
                            if(a[i][5] == 1)
                            {
                                if(i == 1 && a[0][5] == 0)
                                {

                                }

                                else if(i == 2 && a[1][5] == 0)
                                {
                                    r1c5 = 2;
                                    a[i-1][5] = 1;
                                    s[4]=2;
                                }

                                else if(i == 3 && a[2][5] == 0)
                                {
                                        r2c5 = 2;
                                        a[i-1][5] = 1;
                                        s[3]=2;
                                }

                                else if(i == 4 && a[3][5] == 0)
                                {
                                    r3c5 = 2;
                                    a[i-1][5] = 1;
                                    s[2]=2;
                                }

                                else if(i == 5 && a[4][5] == 0)
                                {
                                    r4c5 = 2;
                                    a[i-1][5] = 1;
                                    s[1]=2;
                                }

                                else if(i == 6 && a[5][5] == 0)
                                {
                                    r5c5 = 2;
                                    a[i-1][5] = 1;
                                    s[0]=2;
                                }
                              }
                            }
                    }

                    //6th Column
                    if(mx >= 715 && mx <= 807)
                    {
                        for(int i = 1; i <= 6; i++)
                        {
                            if(a[i][6] == 1)
                            {
                                if(i == 1 && a[0][6] == 0)
                                {

                                }

                                else if(i == 2 && a[1][6] == 0)
                                {
                                    r1c6 = 2;
                                    a[i-1][6] = 1;
                                    t[4]=2;
                                }

                                else if(i == 3 && a[2][6] == 0)
                                {
                                    r2c6 = 2;
                                    a[i-1][6] = 1;
                                    t[3]=2;
                                }

                                else if(i == 4 && a[3][6] == 0)
                                {
                                    r3c6 = 2;
                                    a[i-1][6] = 1;
                                    t[2]=2;
                                }

                                else if(i == 5 && a[4][6] == 0)
                                {
                                    r4c6 = 2;
                                    a[i-1][6] = 1;
                                    t[1]=2;
                                }

                                else if(i == 6 && a[5][6] == 0)
                                {
                                    r5c6 = 2;
                                    a[i-1][6] = 1;
                                    t[0]=2;
                                }
                            }
                        }
                    }

                    //7th Column
                    if(mx >= 815 && mx <= 910)
                    {
                        for(int i = 1; i <= 6; i++)
                        {
                            if(a[i][7] == 1)
                            {
                                if(i == 1 && a[0][7] == 0)
                                {

                                }

                                else if(i == 2 && a[1][7] == 0)
                                {
                                    r1c7 = 2;
                                    a[i-1][7] = 1;
                                    u[4]=2;
                                }

                                else if(i == 3 && a[2][7] == 0)
                                {
                                    r2c7 = 2;
                                    a[i-1][7] = 1;
                                    u[3]=2;
                                }

                                else if(i == 4 && a[3][7] == 0)
                                {
                                    r3c7 = 2;
                                    a[i-1][7] = 1;
                                    u[2]=2;
                                }

                                else if(i == 5 && a[4][7] == 0)
                                {
                                    r4c7 = 2;
                                    a[i-1][7] = 1;
                                    u[1]=2;
                                }

                                else if(i == 6 && a[5][7] == 0)
                                {
                                    r5c7 = 2;
                                    a[i-1][7] = 1;
                                    u[0]=2;
                                }
                            }
                        }
                    }
            }
        }

        break;

		default:
			break;
    }
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitWindowSize(1300, 700);
	glutInitWindowPosition(30, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

	glutCreateWindow("4 - IN - A - ROW");

	init();
	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)
    glutMouseFunc(mouseListener);
	glutKeyboardFunc(keyboardListener);

	glutMainLoop();		//The main loop of OpenGL

	return 0;
}




