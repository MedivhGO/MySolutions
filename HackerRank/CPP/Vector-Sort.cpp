//https://www.hackerrank.com/challenges/vector-sort/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<int> ivec;
    int n;
    cin>>n;
    for(int i=0;i < n;i++) {
        int c;
        cin>>c;
        ivec.push_back(c);
    }
    sort(ivec.begin(),ivec.end());
    for(auto x : ivec) {
        cout << x << " ";
    }
    return 0;
}
