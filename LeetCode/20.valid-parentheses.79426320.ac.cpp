/*
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (33.75%)
 * Total Accepted:    280K
 * Total Submissions: 829.6K
 * Testcase Example:  '"["'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * The brackets must close in the correct order, "()" and "()[]{}" are all
 * valid but "(]" and "([)]" are not.
 * 
 */
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        string left = "([{";
        string right = ")]}";
        
        for(auto x:s){
            if(left.find(x)!=string::npos)
            {
                stk.push(x);
            }
            else //是右括号
            {
                if(stk.empty()||stk.top()!=left[right.find(x)])//找到与之对应的左括号，并与栈顶元素比较。
                    return false;
                else
                    stk.pop();
            }
        }
        return stk.empty();
    }
};
