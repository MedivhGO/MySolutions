//https://www.hackerrank.com/challenges/maxsubarray/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int time;
    cin>>time;
    for (int i=0;i<time;++i) {

        int k;
        cin>>k;
        vector<int> arr;
        for (int i=0;i<k;++i) {
            int t;
            cin>>t;
            arr.push_back(t);
        }
        int notcon=0,cursum = 0,maxsum = INT_MIN;
        for (int i=0;i<arr.size();++i) {
            if (arr[i] > 0)
                   notcon+=arr[i];

            cursum+=arr[i];
            if (maxsum<cursum)
                   maxsum = cursum;
            if (cursum < 0)
                   cursum = 0;

        }
         if (notcon == 0)
                  notcon = maxsum;

        cout  << maxsum << " " << notcon << endl;
    }
    return 0;
}
