//https://www.hackerrank.com/challenges/countingsort1/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    vector<int> ivec(101,0);
    for (int i=0;i < n;++i) {
        int x;
        cin>> x;
        ivec[x]++;
    }
    for (int i=0;i<100;++i) {
        cout << ivec[i] << " ";
    }
    return 0;
}
