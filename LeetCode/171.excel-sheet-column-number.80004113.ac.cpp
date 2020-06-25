/*
 * [171] Excel Sheet Column Number
 *
 * https://leetcode.com/problems/excel-sheet-column-number/description/
 *
 * algorithms
 * Easy (47.98%)
 * Total Accepted:    152.8K
 * Total Submissions: 318.3K
 * Testcase Example:  '"A"'
 *
 * Related to question Excel Sheet Column Title
 * Given a column title as appear in an Excel sheet, return its corresponding
 * column number.
 * 
 * For example:
 * ⁠   A -> 1
 * ⁠   B -> 2
 * ⁠   C -> 3
 * ⁠   ...
 * ⁠   Z -> 26
 * ⁠   AA -> 27
 * ⁠   AB -> 28 
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
public:
    int titleToNumber(string s) {
        map<char,int> mapping;
        for(int i=0;i<26;i++)
        {
        mapping['A'+i]=i+1;
        }
        const  int len = s.size();
        int result = 0;
        for(int i=len-1;i>=0;i--)
        {
        result += pow(26,len-i-1)*mapping[s[i]];
        }

        return result;
    }
};
