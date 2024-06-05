#include "Student.h"

using namespace std;

int main(){

	Person p("Peter Anderson", 301073);
	
	p.setDOB(1, 1, 1971);
	cout << "Printing the person version: " << endl;

	p.printDetail();
	cout << endl;
	
	Student s("Anna Anderson", 90743, 357791);
	s.setSID(45632);
	s.setDOB(2, 3, 2000);
	s.setGpa(3.9);
	s.setDateOfGraduation(6, 15, 2024);
	
	cout << "Printing the person version of the student: " << endl;
	s.Person::printDetail();
	cout << endl;

	cout << "Printing the student version: " << endl;
	s.printDetail();
	cout << endl;
	
	return 0;
}