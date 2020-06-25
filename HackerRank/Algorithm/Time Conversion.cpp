//https://www.hackerrank.com/challenges/time-conversion/problem

#include <bits/stdc++.h>

using namespace std;

string timeConversion(string time) {



    string output = time.substr(0, 8);
    string ampm = time.substr(time.size() - 2);
    string hourString = time.substr(0, 2);

    if (ampm == "PM" && hourString != "12") {
        int hour = stoi(hourString);
        hour = (hour + 12) % 24;

        stringstream ss;
        ss << hour;

        output[0] = ss.str()[0];
        output[1] = ss.str()[1];
    }
    else if (ampm == "AM" && hourString == "12") {
        output[0] = output[1] = '0';
    }

    return output;
}

int main() {
    string s;
    cin >> s;
    string result = timeConversion(s);
    cout << result << endl;
    return 0;
}
