/*
 * [504] Base 7
 *
 * https://leetcode.com/problems/base-7/description/
 *
 * algorithms
 * Easy (44.14%)
 * Total Accepted:    23.8K
 * Total Submissions: 53.8K
 * Testcase Example:  '100'
 *
 * Given an integer, return its base 7 string representation.
 * 
 * Example 1:
 * 
 * Input: 100
 * Output: "202"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: -7
 * Output: "-10"
 * 
 * 
 * 
 * Note:
 * The input will be in range of [-1e7, 1e7].
 * 
 */
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0)
            return "0";
        int flag = 1;
        if (num < 0) {
            flag = 0;
            num = abs(num);
        }
        
        vector<char> vans;
        stack<char> stk;
        while(num) {
            int t = num%7;
            char ct = t+'0';
            stk.push(ct);
            num = num/7;
        }
        if (flag == 0) {
            stk.push('-');
        }
        while (!stk.empty()) {
            vans.push_back(stk.top());
            stk.pop();
        }
        
        string s(vans.begin(),vans.end());
        
        return s;
    }
};
