#ifndef SHAPE2D_H
#define SHAPE2D_H
#include "Shape.h"

class Shape2D : public Shape
{

public:
	Shape2D(string n ) : Shape{n}{}

	string getType() const override
	{
		return "2D Shape";
	}

	virtual double computeArea() const = 0;
	
};

#endif
