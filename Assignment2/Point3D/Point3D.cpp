#include "Point3D.h"

Point3D::Point3D() : x{ 0 }, y{ 0 }, z{ 0 }{}

Point3D::Point3D(double xP, double yP, double zP) : x{xP}, y{yP}, z{zP} {}

double Point3D::getX() const
{
	return this->x;
}

double Point3D::getY() const
{
	return this->y;
}

double Point3D::getZ() const
{
	return this->z;
}

Point3D& Point3D::setX(double xP)
{
	this->x = xP;
	return (*this);
}

Point3D& Point3D::setY(double yP)
{
	this->y = yP;
	return (*this);
}

Point3D& Point3D::setZ(double zP)
{
	this->z = zP;
	return (*this);
}

Point3D& Point3D::addPoints(const Point3D& p)
{
	this->x += p.x;
	this->y += p.y;
	this->z += p.z;
	return (*this);
}

Point3D& Point3D::subtractPoints(const Point3D& p)
{
	this->x = (this->x - p.x);
	this->y = (this->y - p.y);
	this->z = (this->z - p.z);
	return (*this);
}

double Point3D::multiplyPoints(const Point3D& p)
{
	
}

double Point3D::squarePoint()
{
	
}







