//https://www.hackerrank.com/challenges/cpp-sets/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    set<int> ist;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int q,t;
        cin>>q>>t;
        if(q==1) {
            ist.insert(t);
        }
        else if(q == 2) {
            ist.erase(t);
        }
        else {
            set<int>::iterator it = ist.find(t);
            if(it == ist.end())
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
    }
    return 0;
}
