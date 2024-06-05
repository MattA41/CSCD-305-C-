#ifndef BOX_H
#define BOX_H
#include "Shape3D.h"

class Box : public Shape3D
{ double depth, width, height;
public:
	Box(string _name, double _depth, double _width, double _height) : Shape3D(_name), depth(_depth), width(_width), height(_height) {}
	double computeArea() const override
	{
		return (2 * (width * height)) + (2 * (width * depth)) + (2 * (height * depth));
	}
	double computeVolume() const override
	{
		return width * height * depth;
	}
	void printDetail() const override
	{
		cout << name << ", " << getType() << ", width: " << width << ", height: " << height << ", depth: " << depth << ", area: " << computeArea() << ", volume: " << computeVolume() << "." << endl;
	}
};

#endif

