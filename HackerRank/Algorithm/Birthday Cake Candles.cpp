//https://www.hackerrank.com/challenges/birthday-cake-candles/problem
#include <bits/stdc++.h>

using namespace std;

int birthdayCakeCandles(int n, vector <int> ar) {
    // Complete this function
    int mx = *max_element(ar.begin(),ar.end());
    return count(ar.begin(),ar.end(),mx);
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = birthdayCakeCandles(n, ar);
    cout << result << endl;
    return 0;
}
