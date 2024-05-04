#ifndef SPHERE_H
#define SPHERE_H
#include <iostream>
#include "Point3D.h"
#include "Ray.h"
using namespace std;
class Sphere
{
	Point3D Center;
	double R;
public:
	friend class Ray;
	Sphere();
	Sphere(Point3D& c, double r);
	Point3D getCenter() const;
	double getRadius()const;
	Sphere& setPoint3D(Point3D& c);
	Sphere& setRadius(double);
	friend class Ray;
};

#endif
