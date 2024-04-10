
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int validInt();


int main()
{
    
    
    

    int stuNum = validInt();

    

    

    cout << "Number of students is: " << stuNum << endl;

    return 0;
}

int validInt()
{
    string stuNumIn;
    int stuNum = 0;

    cout << "please enter the number of students" << "\n";

    while (true)
    {
        

        cin >> stuNumIn;
        stringstream input(stuNumIn);
        cout << "Please enter a valid number\n";

        if (input >> stuNum && !(input >> stuNumIn))
            return stuNum;

        stuNumIn = "";

        cin.clear();
        cin.ignore(100, '\n');


    }


}

