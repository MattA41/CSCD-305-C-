#include <iostream>
#include <string>

using namespace std;


class Shape {

protected:
	string name;

public:
	Shape(string s) {
		name = s;
	}

	void setName(string s) {
		name = s;
	}

	string getName() const {
		return name;
	}

	virtual double getArea() const = 0;

};

// first child class

class Circle : public Shape {

	double radius;

public:
	Circle(string s, double r) : Shape(s) { radius = r; }

	void setRadius(double r) {
		radius = r;
	}
	double getRadius() const {
		return radius;
	}

	double getArea() const {
		return 3.14159*radius*radius;
	}


};

class Rectangle :public Shape {

	double length, width;
public:
	Rectangle(string n, double l, double w) : Shape(n) {
		length = l; width = w;
	}

	void setLength(double l) {
		length = l;
	}

	void setWidth(double w) {
		width = w;
	}

	double getLength() const {
		return length;
	}

	double getWidth() const {
		return width;
	}

	double getArea() const {
		return width*length;
	}
};

class Triangle :public Shape {

	double base, width;
public:
	Triangle(string n, double b, double w) :Shape(n) {

		base = b; width = w;
	}

	double getArea() const {

		return 0.5*base*width;
	}
};

int main() {

	// An abstract base class can never be instantiated


	Shape* shapes[3] = { new Circle("Circle", 2.1), new Rectangle("Rectangle", 3.1, 1.2), new Triangle("Triangle", 8.1, 2.3) };

	// print area of all shape objects in the shape array

	for (int i = 0; i < 3; i++) {

		cout << "Shapes " << i << " " << shapes[i]->getArea() << endl;
	}
	return 0;
}