#include <iostream>
#include <string>
#include "Date.h"

class Person{
public:
	Person(std::string _name = "", int _ssn = 1) :name{ _name }, ssn{ _ssn }{}
	void printName(){ std::cout << name; }
	void setDOB(int m, int d, int y){ dob.setDate(m, d, y); };
	void printDetail(){ std::cout << "Name: " << name << " " << "SSN: "  << ssn << " " <<  "DOB: " << dob << std::endl; }
	
protected:
	std::string name;
	int ssn;
	Date dob;
};