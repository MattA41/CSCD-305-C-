#include <iostream>
#include <string>
#include <sstream>
//I used the compiler in visual studio
using namespace std;
int validInt();

int main()
{
    cout << "please enter the number of students" << "\n";
    int stuNum = validInt();
    int maxScore = 0;
    int minScore = 100;
    double ave = 0;
    for(int i = 0; i < stuNum; i++)
    {
        cout << "please enter a score for student " << i + 1 <<" \n";
    	int stuScore = validInt();
        while(stuScore > 100)
        {
            cout << "please enter a valid number\n";
            stuScore = validInt();
        }

        if(stuScore > maxScore)
        {
            maxScore = stuScore;
        }

        if(stuScore < minScore)
        {
            minScore = stuScore;
        }

        ave = ave + stuScore;

    }

    ave = ave / stuNum;

    cout << "The average score was: " << ave << endl;
    cout << "The lowest score was: " << minScore << endl;
    cout << "The highest score was: " << maxScore << endl;

    



    return 0;
}

int validInt()
{
    string stuNumIn;
    int stuNum = 0;

    while (true)
    {


        cin >> stuNumIn;
        stringstream input(stuNumIn);
        if (input >> stuNum && !(input >> stuNumIn)) {
            if(stuNum > 0)
            {
                return stuNum;
            }
        }

        cout << "Please enter a valid number\n";
        stuNumIn = "";

        cin.clear();
        cin.ignore(100, '\n');


    }
}