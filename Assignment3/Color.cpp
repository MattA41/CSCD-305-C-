#include "Color.h"

Color::Color() {
	red = 0.5;
	green = 0.5;
	blue = 0.5;
}

Color::Color(double r, double g, double b) : red(r), green(g), blue(b) {}

double Color::getRed() const {
	return this->red;
}

double Color::getGreen() const {
	return this->green;
}

double Color::getBlue() const {
	return this->blue;
}

Color& Color::setRed(double r)
{
	this->red = r;
	return *this;
}

Color& Color::setGreen(double g)
{
	this->green = g;
	return *this;
}

Color& Color::setBlue(double b)
{
	this->blue = b;
	return *this;
}

bool operator==(const Color& colorOne, const Color& colorTwo) {
	if(colorOne.getRed() != colorTwo.getRed() || 
		colorOne.getBlue() != colorTwo.getBlue() ||
		colorOne.getGreen() != colorTwo.getGreen()) {
		return false;
	}
	return true;
}

Color operator+(const Color& colorOne, const Color& colorTwo) {
	double newRed, newGreen, newBlue;
	newRed = colorOne.getRed() + colorTwo.getRed();
	newGreen = colorOne.getGreen() + colorTwo.getGreen();
	newBlue = colorOne.getBlue() + colorTwo.getBlue();
	if(newRed > 1.0) {
		newRed = 1.0;
	}
	if(newGreen > 1.0) {
		newGreen = 1.0;
	}
	if(newBlue > 1.0) {
		newBlue = 1.0;
	}
	return Color(newRed, newGreen, newBlue);
}

Color operator-(const Color& colorOne, const Color& colorTwo) {

}