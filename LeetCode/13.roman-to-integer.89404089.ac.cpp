/*
 * [13] Roman to Integer
 *
 * https://leetcode.com/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (47.17%)
 * Total Accepted:    198K
 * Total Submissions: 419.8K
 * Testcase Example:  '"DCXXI"'
 *
 * Given a roman numeral, convert it to an integer.
 * 
 * Input is guaranteed to be within the range from 1 to 3999.
 */
class Solution {
public:
    inline int map(const char c) {
        switch(c) {
            case 'I' : return 1;
            case 'V' : return 5;
            case 'X' : return 10;
            case 'L' : return 50;
            case 'C' : return 100;
            case 'D' : return 500;
            case 'M' : return 1000;
            default : return 0;
        }
    }
    int romanToInt(string s) {
        int res = 0;
        for (size_t i=1;i < s.size(); i++) {
            if(map(s[i])>map(s[i-1])) {
                res-=map(s[i-1]);
            } else {
                res +=map(s[i-1]);
            }
        }
        res+=map(s[s.size()-1]);
        
        return res;
        
    }
};
