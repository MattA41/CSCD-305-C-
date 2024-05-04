#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

class Array{

	//friend functions

	friend bool operator==(const Array&, const Array&);
	friend ostream& operator<<(ostream&, const Array&);
	friend istream& operator>>(istream&, Array&);

public:
	Array(int sz, double d);             // delegating constructor
	Array() : Array(1, 0.0) {};          // default constructor calls delegating constructor
	Array(int sz) : Array(sz, 0.0) {};   // constructor with parameter calls delegating construcor
	Array(const Array&);                 //copy 
	Array& operator=(const Array&);       //assignment operator
	
	~Array();                            //destructor
	Array(Array&&);                      //move constructor
	Array& operator=(Array&&);            //move assignment operator
	
	double& operator[](int) const;
private:
	int size;
	double* data;
};

#endif