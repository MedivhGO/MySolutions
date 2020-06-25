/*
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (46.87%)
 * Total Accepted:    184.8K
 * Total Submissions: 394.3K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if (n<=0) return ans;
        addingpar(ans,"",n,0);
        return ans;
    }
    void addingpar(vector<string> &v,string str,int n,int m) {
        if (n == 0 && m == 0) {
            v.push_back(str);
            return ;
        }
        if (m > 0) addingpar(v,str+")",n,m-1);
        if (n > 0) addingpar(v,str+"(",n-1,m+1);
    }
};
