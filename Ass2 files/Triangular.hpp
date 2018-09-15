#ifndef TRIANGULAR_H
#define TRIANGULAR_H

#define _USE_MATH_DEFINES

#pragma once
#include <GL/glut.h>
#include "Shape.hpp"
#include <math.h>
//#include "Messages.hpp"


class TriangularPrism : public Shape
{
private:
	float alen;		//bottom side
	float blen;		//left side
	float angle;	//in degree
	float depth;
	
public:
	TriangularPrism();
	TriangularPrism(float side1, float side2, float t, float d);

	float Getside1();
	float Getside2();
	float Gettheta();
	float Getdepth();

	void Setside1(float side1);
	void Setside2(float side2);
	void Settheta(float t);
	void Setdepth(float d);

	void draw();
};
#endif
