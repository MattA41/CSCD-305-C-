#ifndef POINT3D_H
#define POINT3D_H
#include <iostream>
using namespace std;

class Point3D
{
	double x, y, z;
public:
	Point3D();
	Point3D(double, double, double);
	double getX() const;
	double getY() const;
	double getZ() const;
	Point3D& setX(double);
	Point3D& setY(double);
	Point3D& setZ(double);
	Point3D& addPoints(const Point3D& p);
	Point3D& subtractPoints(const Point3D& p);
	double multiplyPoints(const Point3D& p);
	double squarePoint();
};



#endif
