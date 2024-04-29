#include "Sphere.h"
#include "Point3D.h"
#include "Ray.h"

Sphere::Sphere()
{
	Center = Point3D();
	R = 0;
}

Sphere::Sphere(Point3D& c, double r)
{
	Center = c;
	this->R = r;
}

Point3D Sphere::getCenter() const
{
	return this->Center;
}

double Sphere::getRadius() const
{
	return this->R;
}

Sphere& Sphere::setPoint3D(Point3D& c)
{
	this->Center = c;
	return (*this);
}

Sphere& Sphere::setRadius(double r)
{
	this->R = r;
	return (*this);
}
