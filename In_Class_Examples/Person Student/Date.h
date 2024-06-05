#include <iostream>

class Date{

	friend std::istream& operator>>(std::istream&, Date&);
	friend std::ostream& operator<<(std::ostream&, const Date&);

public:
	Date(int m = 0, int d = 0, int y = 0) :month(m), day(d), year(y){}

	void setDate(int m, int d, int y){ month = m; day = d; year = y; }
private:

	int month, day, year;
};

std::istream& operator>> (std::istream& in, Date& x){
	in >> x.month >> x.day >> x.year;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Date& x){

	std::string monthName[] = {"",  "January",  "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	out << monthName[x.month] << " " << x.day << "," << x.year;
	return out;

}