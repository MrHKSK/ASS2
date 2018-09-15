#ifndef TRAPEZOIDAL_H
#define TRAPEZOIDAL_H

#pragma once
#include <GL/glut.h>
#include "Shape.hpp"
#include <math.h>

class TrapezoidalPrism : public Shape
{
private:
	float alen;	//BottomLength
	float blen;	//TopLength
	float height;
	float aoff;	//offset
	float depth;

public:
	TrapezoidalPrism();
	TrapezoidalPrism(float BottomWidth, float TopWidth, float Height, float offset, float Depth);

	float GetBottomWidth();
	float GetTopWidth();
	float GetHeight();
	float GetOffset();
	float GetDepth();
		
	void SetBottomWidth(float Bottom);
	void SetTopWidth(float Top);
	void SetHeight(float hei);
	void SetOffset(float off);
	void SetDepth(float Dep);

	void draw();
};

#endif