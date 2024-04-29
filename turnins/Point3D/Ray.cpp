#include "Ray.h"
#include "Point3D.h"
#include "Sphere.h"

Ray::Ray()
{
	origin = Point3D();
	direction = Point3D();
}

Ray::Ray(Point3D& o, Point3D& d)
{
	origin = o;
	direction = d;
}

Point3D Ray::getOrigin() const
{
	return this->origin;
}

Point3D Ray::getDirection() const
{
	return this->direction;
}

Ray& Ray::setDirection(Point3D& d)
{
	direction = d;
	return *this;
}

Ray& Ray::setOrigin(Point3D& o)
{
	origin = o;
	return *this;
}

void Ray::checkIntersection(Sphere& s)
{
	double A = this->direction.squarePoint();
	double B = (s.getCenter().subtractPoints(origin)).multiplyPoints(this->direction);
	double C = ((s.getCenter().subtractPoints(origin)).squarePoint()) - (s.getRadius() * s.getRadius());
	double outNum = (B * B) - (A * C);
	if(outNum < 0)
	{
		std::cout << "Ray does not touch or intersect the sphere" << std::endl;
	}else
	{
		std::cout << "Ray either touches or intersects the sphere" << std::endl;
	}
	
}


