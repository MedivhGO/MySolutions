//https://www.hackerrank.com/challenges/cpp-input-and-output/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int sum = 0;
    int c;
    while(cin>>c) {
        sum+=c;
    }
    cout << sum << endl;
    return 0;
}
