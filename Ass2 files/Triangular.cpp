#include "Triangular.hpp"
#include "Shape.hpp"
#include <math.h>


TriangularPrism::TriangularPrism():Shape()
{
}

TriangularPrism::TriangularPrism(float side1, float side2, float t, float d)
{
	alen = side1;
	blen = side2;
	angle = t;
	depth = d;
}

float TriangularPrism::Getside1()
{
	return alen;
}

float TriangularPrism::Getside2()
{
	return blen;
}

float TriangularPrism::Gettheta()
{
	return angle;
}

float TriangularPrism::Getdepth()
{
	return depth;
}


void TriangularPrism::Setside1(float side1)
{
	alen = side1;
}

void TriangularPrism::Setside2(float side2)
{
	blen = side2;
}

void TriangularPrism::Settheta(float t)
{
	angle = t;
}

void TriangularPrism::Setdepth(float d)
{
	depth = d;
}

void TriangularPrism::draw()
{
	float s1 = alen, s2 = blen, t = angle *(M_PI)/180, d = depth;
	glTranslated(-s1 / 2, 0, -d / 2);
	glColor3f(red, green, blue);
	glBegin(GL_TRIANGLES);
	glVertex3d(x, y, z);
	glVertex3d(x + s1, y, z);
	glVertex3d(x + s2 * cos(t), y + s2 * sin(t), z);
	glEnd();	// front

	glBegin(GL_QUADS);
	glVertex3d(x, y, z);
	glVertex3d(x + s2 * cos(t), y + s2 * sin(t), z);
	glVertex3d(x + s2 * cos(t), y + s2 * sin(t), z + d);
	glVertex3d(x, y, z + d);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3d(x + s1, y, z);
	glVertex3d(x + s2 * cos(t), y + s2 * sin(t), z);
	glVertex3d(x + s2 * cos(t), y + s2 * sin(t), z + d);
	glVertex3d(x + s1, y, z + d);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3d(x, y, z);
	glVertex3d(x + s1, y, z);
	glVertex3d(x + s1, y, z + d);
	glVertex3d(x, y, z + d);
	glEnd();
}

