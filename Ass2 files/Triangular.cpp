#include "Triangular.hpp"
#include "Shape.hpp"
#include <math.h>


TriangularPrism::TriangularPrism() :Shape()
{
}

TriangularPrism::TriangularPrism(double side1, double side2, double theta, double depth)
{
	Side1 = side1;
	Side2 = side2;
	Theta = theta;
	Depth = depth;
}

double TriangularPrism::Getside1()
{
	return Side1;
}

double TriangularPrism::Getside2()
{
	return Side2;
}

double TriangularPrism::Gettheta()
{
	return Theta;
}

double TriangularPrism::Getdepth()
{
	return Depth;
}

void TriangularPrism::Setside1(double side1)
{
	Side1 = side1;
}

void TriangularPrism::Setside2(double side2)
{
	Side2 = side2;
}

void TriangularPrism::Settheta(double theta)
{
	Theta = theta;
}

void TriangularPrism::Setdepth(double depth)
{
	Depth = depth;
}

void TriangularPrism::draw()
{
	double s1 = Side1, s2 = Side2, t = Theta * (M_PI) / 180, d = Depth;
	glTranslated(s1 / 2, 0, d / 2);
	glColor3f(red, green, blue);

	glBegin(GL_TRIANGLES);
	glVertex3d(x, y, z);
	glVertex3d(x - s1, y, z);
	glVertex3d(x - s2 * cos(t), y + s2 * sin(t), z);
	glEnd();//front face

	glBegin(GL_TRIANGLES);
	glVertex3d(x, y, z - d);
	glVertex3d(x - s1, y, z - d);
	glVertex3d(x - s2 * cos(t), y + s2 * sin(t), z - d);
	glEnd();//back face

	glBegin(GL_QUADS);
	glVertex3d(x, y, z);
	glVertex3d(x - s2 * cos(t), y + s2 * sin(t), z);
	glVertex3d(x - s2 * cos(t), y + s2 * sin(t), z - d);
	glVertex3d(x, y, z - d);
	glEnd();//left face

	glBegin(GL_QUADS);
	glVertex3d(x - s1, y, z);
	glVertex3d(x - s2 * cos(t), y + s2 * sin(t), z);
	glVertex3d(x - s2 * cos(t), y + s2 * sin(t), z - d);
	glVertex3d(x - s1, y, z - d);
	glEnd();//top face

	glBegin(GL_QUADS);
	glVertex3d(x, y, z);
	glVertex3d(x - s1, y, z);
	glVertex3d(x - s1, y, z - d);
	glVertex3d(x, y, z - d);
	glEnd();//bottom face
}

