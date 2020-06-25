//https://www.hackerrank.com/challenges/a-very-big-sum/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    long long res=0;
    cout << accumulate(arr.begin(),arr.end(),res);
    return 0;
}
