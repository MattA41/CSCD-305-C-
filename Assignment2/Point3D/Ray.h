#ifndef RAY_H
#define RAY_H
#include "Point3D.h"
#include "Sphere.h"
class Ray
{
	Point3D origin, direction;
public:
	Ray();
	Ray(Point3D& o, Point3D& d);
	Point3D& getOrigin() const;
	Point3D& getDirection() const;
	Ray& setOrigin(Point3D& o);
	Ray& setDirection(Point3D& d);
	void checkInstersection(Sphere& s);
};

#endif
