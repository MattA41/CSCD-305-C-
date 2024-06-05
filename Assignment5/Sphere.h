#ifndef SPHERE_H
#define SPHERE_H
#include "Shape3D.h"

class Sphere : public Shape3D
{
	double radius;
public:
	Sphere(string _name, double _radius) : Shape3D(_name), radius(_radius) {}
	double computeArea() const override
	{
		return 4 * 3.14159 * (radius * radius);
	}
	double computeVolume() const override
	{
		return (4 * PI * (radius * radius * radius)) / 3;
	}
	void printDetail() const override
	{
		cout << name << ", " << getType() << ", radius " << radius << ", area " << computeArea() << ", volume " << computeVolume() <<"." << endl;
	}
};
#endif
