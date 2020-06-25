//https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
   int a;
   stringstream ss(str);
   vector<int> res;
   char ch;
   while(1) {
       ss>>a;
       ss>>ch;
       res.push_back(a);
       if(ch != ',')
           break;

       ch = '\0';
   }

   return res;

}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}
