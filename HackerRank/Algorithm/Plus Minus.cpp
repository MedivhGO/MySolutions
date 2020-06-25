//https://www.hackerrank.com/challenges/plus-minus/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    int postive = 0;
    int negtive = 0;
    int zero = 0;
    int total = arr.size();
    for (auto x : arr) {
        if (x>0)
            postive++;
        else if (x == 0)
            zero++;
        else
            negtive++;
    }
    cout << setprecision(6) << (postive+0.0)/total << endl;
    cout << setprecision(6) << (negtive+0.0)/total << endl;
    cout << setprecision(6) << (0.0+zero)/total << endl;
    return 0;
}
