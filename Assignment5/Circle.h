#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape2D.h"

class Circle : public Shape2D
{	double radius;

public:
	Circle(string _name, double _radius) : Shape2D(_name), radius(_radius) {}
	double computeArea() const override
	{
		return PI *(radius * radius);
	}
	void printDetail() const override
	{
		cout << name << ", " << getType() << ", radius " << radius << ", area " << computeArea() << "." << endl;
	}
	
};
#endif

