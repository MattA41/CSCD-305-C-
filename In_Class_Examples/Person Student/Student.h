#include "Person.h"

class Student : public Person{
public:
	Student(std::string n, int _ssn, int _sid = 0) : Person{ n, _ssn }, sid{ _sid }, gpa{ 0.0 }{}
	void setDateOfGraduation(int m, int d, int y){ dateOfGraduation.setDate(m, d, y); }
	void setGpa(float score){ gpa = score; }
	void setSID(int sID) { sid = sID; }
	void printDetail() { std::cout << "Name: " << name  << " " << "SSN: " << ssn << " " << "DOB: " << dob << " " << "SID: " << sid << " " << "GPA: " << gpa << " " << "Date of Graduation: " << dateOfGraduation << std::endl; }
	
private:
	int sid;                       // student identification number
	float gpa;                     // gpa
	Date dateOfGraduation;         // degree of graduation
};