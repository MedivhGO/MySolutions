//https://www.hackerrank.com/challenges/c-tutorial-for-loop/problem
#include <iostream>
#include <cstdio>
using namespace std;
int fun(int i) {
string num[10] = {" ","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    cout << num[i] << endl;
return 0;
}
int main() {
    // Complete the code.
    int a,b;
    cin>>a>>b;
    for(int i=a;i<=b;i++) {
        if(i<=9 && i>=1)
            fun(i);
        else if(i%2==0)
            cout << "even" << endl;
        else
            cout << "odd" << endl;
    }
    return 0;
}
