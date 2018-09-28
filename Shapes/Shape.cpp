#include "Shape.h"
#include "picture.h"
#include <sstream>
using std::string;

//Shape::Shape(int w, int h, RGBTriple c)// :width(width), height(height), color(color)
//{
//}

Shape::Shape()
{
}

Shape::~Shape()
{
}


void boxModel::initialize(string line)
{
	istringstream sin(line);
	string junk;
	string shapeDimensions;
	string shapeColor;
	int shapeXvalue;
	int shapeYvalue;

	sin >> junk;
	sin >> shapeDimensions;
	sin >> shapeColor;
	sin >> shapeXvalue;
	sin >> shapeYvalue;

	int width;
	int height;
	int red;
	int green;
	int blue;

	std::string::size_type sz;   // alias of size_t

	width = std::stoi(shapeDimensions.substr(0, 'x'), &sz);
	height = std::stoi(shapeDimensions.substr(shapeDimensions.find('x') + 1, shapeDimensions.length()), &sz);

	int dot = shapeColor.find('.');
	blue = std::stoi(shapeColor.substr(1, dot - 1), &sz);
	green = std::stoi(shapeColor.substr(dot + 1, dot + 4), &sz);
	red = std::stoi(shapeColor.substr(dot+5, dot + 8), &sz);

	RGBTriple RGBShapeColor(blue, green, red);

	color = RGBShapeColor;
	shapeWidth = width;
	shapeHeight = height;
	startCoord.x = shapeXvalue;
	startCoord.y = shapeYvalue;


	//DELETE THIS BEFORE SUBMITTING
	cout << junk << endl;
	cout << width << endl;
	cout << height << endl;
	cout << red << endl;
	cout << green << endl;
	cout << blue << endl;
	cout << shapeXvalue << endl;
	cout << shapeYvalue << endl;

}

void Rectangle::draw()
{
	//import drawing area
	Picture& canvas = Picture::getInstance();

	//Top line
	canvas.AddLine(startCoord.x, startCoord.y, startCoord.x + shapeWidth, startCoord.y, color);
	//Left line
	canvas.AddLine(startCoord.x, startCoord.y, startCoord.x, startCoord.y - shapeHeight, color);
	//Bottom line
	canvas.AddLine(startCoord.x, startCoord.y - shapeHeight, startCoord.x + shapeWidth, startCoord.y - shapeHeight, color);
	//Right line
	canvas.AddLine(startCoord.x + shapeWidth, startCoord.y, startCoord.x + shapeWidth, startCoord.y - shapeHeight, color);

}

void RightTriangle::draw()
{
	//import drawing area
	Picture& canvas = Picture::getInstance();

	canvas.AddLine(startCoord.x, startCoord.y, startCoord.x, startCoord.y - shapeHeight, color);
	canvas.AddLine(startCoord.x, startCoord.y - shapeHeight, startCoord.x + shapeWidth, startCoord.y - shapeHeight, color);

	canvas.AddLine(startCoord.x, startCoord.y, startCoord.x + shapeWidth, startCoord.y - shapeHeight, color);

}

void Dimond::draw()
{
	//import drawing area
	Picture& canvas = Picture::getInstance();

	canvas.AddLine(startCoord.x, startCoord.y, startCoord.x + (shapeWidth/2), startCoord.y + (shapeHeight/2), color);

	canvas.AddLine(startCoord.x + (shapeWidth / 2), startCoord.y + (shapeHeight / 2), startCoord.x + shapeWidth, startCoord.y, color);

	canvas.AddLine(startCoord.x + shapeWidth, startCoord.y, startCoord.x + (shapeWidth / 2), startCoord.y - (shapeHeight / 2), color);

	canvas.AddLine(startCoord.x + (shapeWidth / 2), startCoord.y - (shapeHeight / 2), startCoord.x, startCoord.y, color);

}

void Star::draw()
{
	//import drawing area
	Picture& canvas = Picture::getInstance();

	canvas.AddLine(startCoord.x, startCoord.y, startCoord.x + shapeWidth, startCoord.y, color);

	canvas.AddLine(startCoord.x + shapeWidth, startCoord.y, startCoord.x + (shapeWidth*.15), startCoord.y - (shapeHeight/2) , color);

	canvas.AddLine(startCoord.x + (shapeWidth*.15), startCoord.y - (shapeHeight / 2), startCoord.x + (shapeWidth/2), startCoord.y + (shapeHeight/2) , color);

	canvas.AddLine(startCoord.x + (shapeWidth / 2), startCoord.y + (shapeHeight / 2), startCoord.x + (shapeWidth*.85), startCoord.y - (shapeHeight/2), color);

	canvas.AddLine(startCoord.x + (shapeWidth*.85), startCoord.y - (shapeHeight / 2), startCoord.x, startCoord.y, color);



}


void Point::draw()
{
	//import drawing area
	Picture& canvas = Picture::getInstance();

	canvas.SetPixelColor(startCoord.x, startCoord.y, color);
}

void Point::initialize(string line)
{
	istringstream sin(line);
	string junk;
	string shapeColor;
	int shapeXvalue;
	int shapeYvalue;

	sin >> junk;
	sin >> shapeColor;
	sin >> shapeXvalue;
	sin >> shapeYvalue;

	std::string::size_type sz;   // alias of size_t

	int red;
	int green;
	int blue;

	int dot = shapeColor.find('.');
	blue = std::stoi(shapeColor.substr(1, dot - 1), &sz);
	green = std::stoi(shapeColor.substr(dot + 1, dot + 4), &sz);
	red = std::stoi(shapeColor.substr(dot + 5, dot + 8), &sz);

	RGBTriple RGBShapeColor(blue, green, red);
	color = RGBShapeColor;

	startCoord.x = shapeXvalue;
	startCoord.y = shapeYvalue;

	//DELETE THIS BEFORE SUBMITTING
	cout << junk << endl;
	cout << red << endl;
	cout << green << endl;
	cout << blue << endl;
	cout << startCoord.x << endl;
	cout << startCoord.y << endl;
}

void Line::draw()
{
	//import drawing area
	Picture& canvas = Picture::getInstance();

	canvas.AddLine(startCoord.x, startCoord.y, endCoord.x, endCoord.y, color);
}

void Line::initialize(string line)
{
	istringstream sin(line);
	string junk;
	string shapeColor;

	sin >> junk;
	sin >> shapeColor;
	sin >> startCoord.x;
	sin >> startCoord.y;
	sin >> endCoord.x;
	sin >> endCoord.y;

	std::string::size_type sz;   // alias of size_t

	int red;
	int green;
	int blue;

	int dot = shapeColor.find('.');
	blue = std::stoi(shapeColor.substr(1, dot - 1), &sz);
	green = std::stoi(shapeColor.substr(dot + 1, dot + 4), &sz);
	red = std::stoi(shapeColor.substr(dot + 5, dot + 8), &sz);

	RGBTriple RGBShapeColor(blue, green, red);
	color = RGBShapeColor;


	//DELETE THIS BEFORE SUBMITTING
	cout << junk << endl;
	cout << red << endl;
	cout << green << endl;
	cout << blue << endl;
	cout << startCoord.x << endl;
	cout << startCoord.y << endl;
	cout << endCoord.x << endl;
	cout << endCoord.y << endl;
}



