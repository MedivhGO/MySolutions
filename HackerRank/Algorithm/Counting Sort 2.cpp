//https://www.hackerrank.com/challenges/countingsort2/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    vector<int> bucket(100,0);
    for (int i=0;i < n ; ++i) {
        int x;
        cin >> x;
        bucket[x]++;
    }
    for (int i=0;i<100;++i) {
        int number = bucket[i];
        for (int j=0;j<number;j++) {
            cout << i << " ";
        }
    }
    return 0;
}
