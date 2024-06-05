#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape2D.h"

class Rectangle : public Shape2D
{
	double width;
	double height;

public:
	Rectangle(string _name, double _width, double _height) : Shape2D(_name) { width = _width; height = _height; }
	double computeArea() const override { return width * height; }
	void printDetail() const override
	{
		cout << name << ", " << getType() << ", width " << width << ", height " << height << ", area " << computeArea() << "." << endl;
	}
	
};
#endif

