/*
 * [168] Excel Sheet Column Title
 *
 * https://leetcode.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (26.89%)
 * Total Accepted:    123.9K
 * Total Submissions: 460.7K
 * Testcase Example:  '1'
 *
 * Given a positive integer, return its corresponding column title as appear in
 * an Excel sheet.
 * 
 * For example:
 * 
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB 
 * 
 * Credits:Special thanks to @ifanchu for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    string convertToTitle(int n) {
        unordered_map<size_t,char> mapping;
        for (int i = 1; i <= 26; i++) {
            mapping[i] = 'A'  - 1 + i;
        }
        stack<char> stk;
         
        while (n) {
                 char t;
                
                 if(n %26 != 0) {
                    t = mapping[n%26];
                    n = n/26;
                 }
                 else {
                     t = 'Z';
                     n=n/26-1;
                 }
                 stk.push(t);
          
        }
        string s;
        while (!stk.empty()) {
            s.push_back(stk.top());
            stk.pop();
        }
        return s; 
    }
};
