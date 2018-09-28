#include "rgbtriple.h"
#include <string>

using std::string;

#pragma once

struct Coordinate{
	int x = 25;
	int y = 475;
};

class Shape
{
public:
	//Shape(int w, int h, RGBTriple c);
	Shape();
	virtual ~Shape();
	virtual void draw() = 0;
	virtual void initialize(string) = 0;
protected:
	//Make startCoord static???
	Coordinate startCoord;
	RGBTriple color;
	bool isFilled;
};

class boxModel : public Shape
{
public:
	virtual void initialize(string);
protected:
	int shapeWidth;
	int shapeHeight;
};

class Rectangle : public boxModel
{
public:
	void draw();
};

class RightTriangle : public boxModel
{
public:
	void draw();
};

class Dimond : public boxModel
{
public:
	void draw();
};

class Star : public boxModel
{
public:
	void draw();
};

class Point : public Shape
{
public:
	void draw();
	void initialize(string);
};

class Line : public Shape
{
public:
	void draw();
	void initialize(string);
private:
	Coordinate endCoord;
};