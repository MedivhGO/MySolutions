//https://www.hackerrank.com/challenges/classes-objects/problem

#include <iostream>
using namespace std;
// Write your Student class here
class Student
{
    public:
        void input()
        {
            for (int i = 0; i < 5; ++i) {
                cin>>fivesocre[i];
            }
        }
         int calculateTotalScore()
        {
            int total = 0;
            for (int i = 0; i < 5; ++i) {
                total += fivesocre[i];
            }
            return total;
        }




    private:
        int fivesocre[5];


};

