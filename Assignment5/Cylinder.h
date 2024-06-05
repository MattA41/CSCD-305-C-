#ifndef CYLINDER_H
#define CYLINDER_H
#include "Shape3D.h"

class Cylinder : public Shape3D
{	double radius;
	double height;
public:
	Cylinder(string _name, double _radius, double _height) : Shape3D(_name), radius(_radius), height(_height) {}
	double computeArea() const override
	{
		return (2*PI *radius*height) + (2*PI*radius*radius);
	}
	double computeVolume() const override
	{
		return PI * (radius*radius) * height;
	}
	void printDetail() const override
	{
		cout << name << ", " << getType() << ", radius " << radius << ", height " << height << ", area " << computeArea() << ", volume " << computeVolume() << "." << endl;
	}
};

#endif

