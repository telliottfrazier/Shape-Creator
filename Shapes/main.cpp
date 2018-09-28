//Author:	Elliott Frazier
//Date:		2/12/18

#include "rgbtriple.h"
#include "picture.h"
#include "Shape.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

void main()
{

	vector<Shape*> shapes;
	Picture& art = Picture::getInstance();
	string line;

	ifstream fin("drawShapes.stb");

	while (getline(fin, line))
	{
		istringstream sin(line);
		string shapeType;
		sin >> shapeType;
		Shape* ShapePtr;

		if (shapeType == "Rectangle") {
			ShapePtr = new Rectangle;
			shapes.push_back(ShapePtr);
			ShapePtr->initialize(line);
		}
		else if (shapeType == "RightTriangle")
		{
			ShapePtr = new RightTriangle;
			shapes.push_back(ShapePtr);
			ShapePtr->initialize(line);
		}
		else if (shapeType == "Dimond")
		{
			ShapePtr = new Dimond;
			shapes.push_back(ShapePtr);
			ShapePtr->initialize(line);
		}
		else if (shapeType == "Star")
		{
			ShapePtr = new Star;
			shapes.push_back(ShapePtr);
			ShapePtr->initialize(line);
		}
		else if (shapeType == "Point")
		{
			ShapePtr = new Point;
			shapes.push_back(ShapePtr);
			ShapePtr->initialize(line);
		}
		else if (shapeType == "Line")
		{
			ShapePtr = new Line;
			shapes.push_back(ShapePtr);
			ShapePtr->initialize(line);
		}
	}


	for (int i = 0; i < shapes.size(); i++)
	{
		shapes[i]->draw();
	}

	art.WriteToFile("drawShapes.bmp");
}


