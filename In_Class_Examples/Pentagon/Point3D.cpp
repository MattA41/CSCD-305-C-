#include "Point3D.h"

using namespace std;


Point3D::Point3D(double x, double y, double z):X{x}, Y{y}, Z{z}{}
Point3D::Point3D(const Point3D& p):X{ p.X }, Y{p.Y}, Z{p.Z} {}
Point3D& Point3D::operator=(const Point3D& p) {
	X = p.X;
        Y = p.Y;
        Z = p.Z;
	return *this;
}

Point3D& Point3D::setX(double x) {
	this->X = x;
	return (*this);
}

Point3D& Point3D::setY(double y) {
	this->Y = y;
	return (*this);
}

Point3D& Point3D::setZ(double z) {
	this->Z = z;
	return (*this);
}

double Point3D::getX() const {
	return X;
}

double Point3D::getY() const {
	return Y;
}

double Point3D::getZ() const {
	return Z;
}

ostream& operator <<(ostream& ostr, const Point3D& pOne) {

	ostr << pOne.X << " " << pOne.Y << " " << pOne.Z << endl;
	return ostr;
}

istream& operator>>(istream& istr, Point3D& pOne) {
	
	istr >> pOne.X >> pOne.Y >> pOne.Z;
	
	return istr;

}

