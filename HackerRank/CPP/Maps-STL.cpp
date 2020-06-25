//https://www.hackerrank.com/challenges/cpp-maps/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int nq;
    cin>>nq;
    map<string,int> m;
    while(nq--) {
        int q;
        cin>>q;
        if (q == 1) {
            string name;
            int val;
            cin>>name>>val;
            if (m.find(name)!=m.end()){
                m[name]+=val;
            }

            else {
                m.insert(make_pair(name,val));
            }
        }
        else if (q==2) {
            string name;
            cin>> name;
            m.erase(name);
        }
        else if (q == 3) {
            string name;
            cin>>name;
            if (m.find(name)!=m.end())
                   cout << (m.find(name))->second << endl;
            else
                   cout << 0 <<endl;
        }
    }
    return 0;
}
