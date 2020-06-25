//https://www.hackerrank.com/challenges/cpp-lower-bound/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    vector<int> ivec;
    for(int i=0;i<n;i++) {
        int t;
        cin>>t;
        ivec.push_back(t);
    }

    int res;
    cin>>res;
    for(int i=0;i<res;i++) {
        int c;
        cin>>c;
        vector<int>::iterator it = lower_bound(ivec.begin(),ivec.end(),c);
        if(*it == c)
            cout << "Yes " << it - ivec.begin()+1<<endl;
        else
            cout << "No " << it - ivec.begin() +1<<endl;
    }



    return 0;
}
