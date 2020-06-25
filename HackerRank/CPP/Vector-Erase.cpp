//https://www.hackerrank.com/challenges/vector-erase/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    ostream_iterator<int> out_iter(cout," ");
    vector<int> ivec;
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int t;
        cin>>t;
        ivec.push_back(t);
    }
    int pos;
    cin>> pos;
    ivec.erase(ivec.begin()+pos-1);
    int first,end;
    cin>>first>>end;
    ivec.erase(ivec.begin()+first-1,ivec.begin()+end-1);

    cout << distance(ivec.begin(),ivec.end());
    cout << endl;
    copy(ivec.begin(),ivec.end(),out_iter);
    return 0;
}
