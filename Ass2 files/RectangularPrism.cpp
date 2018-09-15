#include "RectangularPrism.hpp"
#include "Shape.hpp"


RectangularPrism::RectangularPrism():Shape()
{
}

RectangularPrism::RectangularPrism(float xlin, float ylin, float zlin)
{
	xlen = xlin;
	ylen = ylin;
	zlen = zlin;
}

float RectangularPrism::GetXlin()
{
	return xlen;
}

float RectangularPrism::GetYlin()
{
	return ylen;
}

float RectangularPrism::GetZlin()
{
	return zlen;
}

void RectangularPrism::SetXlin(float x)
{
	xlen = x;
}

void RectangularPrism::SetYlin(float y)
{
	ylen = y;
}

void RectangularPrism::SetZlin(float z)
{
	zlen = z;
}

void RectangularPrism::wheel()
{
	float l = xlen, w = ylen, h = zlen;
	glTranslated(-l / 2, -w/2, -h / 2);
	glColor3f(red, green, blue);
	glBegin(GL_QUADS);	// Front
	glVertex3d(x, y, z);
	glVertex3d(x + l, y, z);
	glVertex3d(x + l, y + w, z);
	glVertex3d(x, y + w, z);
	glEnd();

	glBegin(GL_QUADS);	// Bottom
	glVertex3d(x, y, z);
	glVertex3d(x + l, y, z);
	glVertex3d(x + l, y, z + h);
	glVertex3d(x, y, z + h);
	glEnd();

	glBegin(GL_QUADS);	// Back
	glVertex3d(x, y, z + h);
	glVertex3d(x + l, y, z + h);
	glVertex3d(x + l, y + w, z + h);
	glVertex3d(x , y + w, z + h);
	glEnd();

	glBegin(GL_QUADS);	// Top
	glVertex3d(x, y + w, z);
	glVertex3d(x + l, y + w, z);
	glVertex3d(x + l, y + w, z + h);
	glVertex3d(x, y + w, z + h);
	glEnd();

	glBegin(GL_QUADS); // Right
	glVertex3d(x + l, y, z);
	glVertex3d(x + l, y, z + h);
	glVertex3d(x + l, y + w, z + h);
	glVertex3d(x + l, y + w, z);
	glEnd();

	glBegin(GL_QUADS); // Left
	glVertex3d(x, y, z);
	glVertex3d(x, y + w, z);
	glVertex3d(x, y + w, z + h);
	glVertex3d(x, y, z + h);
	glEnd();
}

void RectangularPrism::draw()
{
	// x, y, z are the initial position
	float l = xlen, w = ylen, h = zlen;
	glTranslated(-l / 2, 0, -h / 2);
	glColor3f(red, green, blue);
	glBegin(GL_QUADS);	// Front
	glVertex3d(x, y, z);
	glVertex3d(x + l, y, z);
	glVertex3d(x + l, y + w, z);
	glVertex3d(x, y + w, z);
	glEnd();

	glBegin(GL_QUADS);	// Bottom
	glVertex3d(x, y, z);
	glVertex3d(x + l, y, z);
	glVertex3d(x + l, y, z + h);
	glVertex3d(x, y, z + h);
	glEnd();

	glBegin(GL_QUADS);	// Back
	glVertex3d(x, y, z + h);
	glVertex3d(x + l, y, z + h);
	glVertex3d(x + l, y + w, z + h);
	glVertex3d(x, y + w, z + h);
	glEnd();

	glBegin(GL_QUADS);	// Top
	glVertex3d(x, y + w, z);
	glVertex3d(x + l, y + w, z);
	glVertex3d(x + l, y + w, z + h);
	glVertex3d(x, y + w, z + h);
	glEnd();

	glBegin(GL_QUADS); // Right
	glVertex3d(x + l, y, z);
	glVertex3d(x + l, y, z + h);
	glVertex3d(x + l, y + w, z + h);
	glVertex3d(x + l, y + w, z);
	glEnd();

	glBegin(GL_QUADS); // Left
	glVertex3d(x, y, z);
	glVertex3d(x, y + w, z);
	glVertex3d(x, y + w, z + h);
	glVertex3d(x, y, z + h);
	glEnd();
	//glTranslated(3, 4, 5);
}

