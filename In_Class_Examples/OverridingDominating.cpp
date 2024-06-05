// OverridingDominating.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <iostream>

using namespace std;
class X {

public:
	void f() { cout << "X::f() executing\n"; }
	int a;
};

class Y :public X {
public:
	void f() { cout << "Y::f() executing\n"; }
	int a;
};

int main() {
	X x;
	x.a = 22;
	x.f();
	cout << "x.a = " << x.a << endl;

	Y y;
	y.a = 44;
	y.X::a = 66;
	y.f();
	y.X::f();

	cout << "y.a = " << y.a << endl;
	cout << "y.X::a = " << y.X::a << endl;

	X z = y;

	cout << "z.a = " << z.a << endl;

	return 0;
}