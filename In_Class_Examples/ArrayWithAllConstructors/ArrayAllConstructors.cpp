#include "Array.h"


Array createArray() {
	  
	Array e2(5, 10.0);

  return e2;
}

int main(){

	Array a1(5, 9.0);
	cout << "a1 = " << a1 << endl;
	Array a2(a1);
	cout << "a2 = " << a2 << endl;
	Array a3(5);
	cout << "a3 = " << a3 << endl;
	cin >> a3;
	cout << "a3 = " << a3 << endl;
	Array a4;
	cout << "a4 = " << a4 << endl;

	a2 = createArray();
	cout << "a2 = " << a2 << endl;
	a4 = std::move(a3);
	cout << "a4 = " << a4 << endl;
	
	return 0;



}