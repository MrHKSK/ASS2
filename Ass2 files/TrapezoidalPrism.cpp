#include "TrapezoidalPrism.hpp"
#include "Shape.hpp"
#include <math.h>

TrapezoidalPrism::TrapezoidalPrism() :Shape() 
{
}
TrapezoidalPrism::TrapezoidalPrism(float BottomWidth, float TopWidth, float Height, float offset, float Depth)
{
	alen = BottomWidth;
	blen = TopWidth;
	height = Height;
	aoff = offset;
	depth = Depth;
}

float TrapezoidalPrism::GetBottomWidth()
{
	return alen;
}

float TrapezoidalPrism::GetTopWidth()
{
	return blen;
}

float TrapezoidalPrism::GetHeight()
{
	return height;
}

float TrapezoidalPrism::GetOffset()
{
	return aoff;
}

float TrapezoidalPrism::GetDepth()
{
	return depth;
}


void TrapezoidalPrism::SetBottomWidth(float Bottom)
{
	alen = Bottom;
}
void TrapezoidalPrism::SetTopWidth(float Top)
{
	blen = Top;
}
void TrapezoidalPrism::SetHeight(float Hei)
{
	height = Hei;
}
void TrapezoidalPrism::SetOffset(float Off)
{
	aoff = Off;
}
void TrapezoidalPrism::SetDepth(float Dep)
{
	depth = Dep;
}


void TrapezoidalPrism::draw() {
	float h = height;
	float t = blen + aoff;
	float b = alen;
	float d = depth;
	float a = aoff;

	glTranslated(-b / 2, 0, -d / 2);
	//glRotated(180, 0, 1, 0);
	glColor3f(red, green, blue);

	glBegin(GL_POLYGON);
	glVertex3d(x, y, z);
	glVertex3d(x + b, y, z);
	glVertex3d(x + b, y, z + d);
	glVertex3d(x, y, z + d);//bottom face
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(x, y, z);
	glVertex3d(x + b, y, z);
	glVertex3d(x + t, y + h, z);
	glVertex3d(x + a, y + h, z);//front face
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(x + b, y, z);
	glVertex3d(x + b, y, z + d);
	glVertex3d(x + t, y + h, z + d);
	glVertex3d(x + t, y + h, z);//Right face
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(x, y, z);
	glVertex3d(x + a, y + h, z);
	glVertex3d(x + a, y + h, z + d);
	glVertex3d(x, y, z + d);//Left face
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(x + a, y + h, z);
	glVertex3d(x + t, y + h, z);
	glVertex3d(x + t, y + h, z + d);
	glVertex3d(x + a, y + h, z + d);//Top face
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(x, y, z + d);
	glVertex3d(x + b, y, z + d);
	glVertex3d(x + t, y + h, z + d);
	glVertex3d(x + a, y + h, z + d);//back face
	glEnd();
}
