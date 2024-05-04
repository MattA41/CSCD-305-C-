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

Color::Color(const Color& color) : red(color.getRed()), green(color.getGreen()), blue(color.getBlue()) {}

Color& Color::operator=(const Color& color)
{
	if (this != &color)
	{
		red = color.getRed();
		green = color.getGreen();
		blue = color.getBlue();
		return *this;
	}
}

Color::Color(Color&& color) : red(color.getRed()), green(color.getGreen()), blue(color.getBlue()) {}

/*Color& Color::operator=(Color&& color)
{	
	if (this != &color) {
		red = color.getRed();
		green = color.getGreen();
		blue = color.getBlue();
		return *this;
	}
}*/

bool operator==(const Color& colorOne, const Color& colorTwo) {
	if (colorOne.getRed() != colorTwo.getRed() ||
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
	if (newRed > 1.0) {
		newRed = 1.0;
	}
	if (newGreen > 1.0) {
		newGreen = 1.0;
	}
	if (newBlue > 1.0) {
		newBlue = 1.0;
	}
	return Color(newRed, newGreen, newBlue);
}

Color operator-(const Color& colorOne, const Color& colorTwo) {
	double newRed, newGreen, newBlue;
	newRed = colorOne.getRed() - colorTwo.getRed();
	newGreen = colorOne.getGreen() - colorTwo.getGreen();
	newBlue = colorOne.getBlue() - colorTwo.getBlue();
	if (newRed < 0.0)
	{
		newRed = 0.0;
	}

	if (newGreen < 0.0)
	{
		newGreen = 0.0;
	}
	if (newBlue < 0.0)
	{
		newBlue = 0.0;
	}
	return Color(newRed, newGreen, newBlue);

}

Color operator*(const Color& colorOne, const Color& colorTwo)
{
	double newRed, newGreen, newBlue;
	newRed = colorOne.getRed() * colorTwo.getRed();
	newGreen = colorOne.getGreen() * colorTwo.getGreen();
	newBlue = colorOne.getBlue() * colorTwo.getBlue();
	return Color(newRed, newGreen, newBlue);
}

bool operator!(const Color& colorOne)
{
	if (colorOne.getRed() == 0.0 && colorOne.getGreen() == 0.0 && colorOne.getBlue() == 0.0)
	{
		return true;
	}
	return false;
}

ostream& operator<<(ostream&, const Color& color)
{
	return cout << "The RGB values are" << color.getRed() << " " << color.getGreen() << " " << color.getBlue() << endl;
}

istream& operator>>(istream&, Color& color)
{
	cout << "Enter a new value for red" << endl;
	color.setRed(color.validDouble());
	cout << "Enter a new value for green" << endl;
	color.setGreen(color.validDouble());
	cout << "Enter a new value for blue" << endl;
	color.setBlue(color.validDouble());
	return cin;

}

double Color::validDouble()
{
	string colorNum;
	double colorValue;

	while (true)
	{
		cin >> colorNum;
		stringstream input(colorNum);
		if (input >> colorValue && !(input >> colorNum))
		{
			if (colorValue >= 0.0 && colorValue <= 1.0)
			{
				return colorValue;
			}
		}
		cout << "Invalid input. Please enter a number between 0.0 and 1.0" << endl;
		colorNum = "";
		cin.clear();
		cin.ignore(10000, '\n');
	}
}