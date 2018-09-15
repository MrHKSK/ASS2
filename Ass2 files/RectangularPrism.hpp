#ifndef RECTANGULAR_H
#define RECTANGULAR_H

#pragma once
#include <GL/glut.h>
#include "Shape.hpp"

class RectangularPrism : public Shape 
{
private:
	float xlen;
	float ylen;
	float zlen;

public:
	RectangularPrism();
	RectangularPrism(float xlin, float ylin, float zlin);
	
	float GetXlin();
	float GetYlin();
	float GetZlin();
	//double GetRotation;

	void SetXlin(float x);
	void SetYlin(float y);
	void SetZlin(float z);
	//void SetRotation;
	void wheel();
	void draw();
};

#endif