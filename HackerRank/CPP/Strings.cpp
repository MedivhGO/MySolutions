//https://www.hackerrank.com/challenges/c-tutorial-strings/problem
#include <iostream>
#include <string>
using namespace std;

int main() {
   // Complete the program
    string s1;
    string s2;
    while(cin>>s1) {
        cin>>s2;
        cout << s1.size() << " " << s2.size() <<endl;
        cout << s1+s2 << endl;
        char t ;
        t = s1[0];
        s1[0] = s2[0];
        s2[0] = t;
        cout << s1 << " " << s2 <<endl;
    }
    return 0;
}
