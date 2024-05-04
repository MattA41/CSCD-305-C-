#ifndef COLOR_H
#define COLOR_H
#include <iostream>
#include <locale>
#include <sstream>
using namespace std;

class Color{

	double red, green, blue;

public:
	Color();
	Color(double r, double g, double b);
	double getRed() const;
	double getGreen() const;
	double getBlue() const;
	Color& setRed(double r);
	Color& setGreen(double g);
	Color& setBlue(double b);
	Color(const Color& color);
	Color& operator=(const Color& color);
	Color(Color&& color);
	//Color& operator=(Color&& color);
	friend bool operator==(const Color& colorOne, const Color& colorTwo);
	friend Color operator+(const Color& colorOne, const Color& colorTwo);
	friend Color operator-(const Color& colorOne, const Color& colorTwo);
	friend Color operator*(const Color& colorOne, const Color& colorTwo);
	friend bool operator!(const Color& colorOne);
	friend ostream& operator<<(ostream&, const Color&);
	friend istream& operator>>(istream&, Color&);
	double validDouble();
};
#endif
