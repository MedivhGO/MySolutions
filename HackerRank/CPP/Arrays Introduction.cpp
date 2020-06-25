#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    size_t n;
    cin>> n;
    int arr[n];
    for(size_t i=0;i<n;i++)
        cin>> arr[i];
    for(size_t i=0;i<n;i++)
        cout << arr[n-i-1] << " ";
    return 0;
}
//https://www.hackerrank.com/challenges/arrays-introduction/problem