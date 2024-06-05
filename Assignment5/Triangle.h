#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape2D.h"
class Triangle : public Shape2D
{
	double base;
	double height;

public:
	Triangle(string _name, double _base, double _height) : Shape2D{_name}, base { _base }, height {_height}{}

	double computeArea() const override
	{
		return 0.5 * (base * height);
	}
	void printDetail() const override
	{
		cout << name << ", " << getType() << ", base " << base << ", height " << height << ", area " << computeArea() << "." << endl;
	}
};

	

#endif

