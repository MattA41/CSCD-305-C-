#ifndef _POINT3D_H
#define _POINT3D_H
#include <iostream>

class Point3D{
	double X;
        double Y;
        double Z;

public:
	Point3D (double x, double y, double z);
	Point3D():Point3D(0.0, 0.0, 0.0) {}
        Point3D(const Point3D&);
        Point3D& operator=(const Point3D&);
        Point3D& setX(double x);
        Point3D& setY(double y);
        Point3D& setZ(double z);

        double getX() const;
        double getY() const;
        double getZ() const;

	friend std::istream& operator>>(std::istream&, Point3D&);  //non-member friend function
	friend std::ostream& operator<<(std::ostream&, const Point3D&);  //non-member friend function

};
#endif