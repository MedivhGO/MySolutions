/*
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (39.27%)
 * Total Accepted:    208.8K
 * Total Submissions: 531.6K
 * Testcase Example:  '[0]'
 *
 * Given a non-negative integer represented as a non-empty array of digits,
 * plus one to the integer.
 * 
 * You may assume the integer do not contain any leading zero, except the
 * number 0 itself.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list.
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        const int len = digits.size();
        int carry=1;
        int subres = 0;
        vector<int> res;
        for (int i=len-1;i>=0;i--) {
            subres = (digits[i]+carry)%10;
            carry = (digits[i]+carry)/10;
            res.push_back(subres);
        }
        if(carry != 0 )
            res.push_back(carry);
        reverse(res.begin(),res.end());
        
        return res;
    }
};
