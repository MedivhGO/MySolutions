/*
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (23.13%)
 * Total Accepted:    86K
 * Total Submissions: 372.1K
 * Testcase Example:  '[1]'
 *
 * Given a list of non negative integers, arrange them such that they form the
 * largest number.
 * 
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 * 
 * Note: The result may be very large, so you need to return a string instead
 * of an integer.
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
public:
    string largestNumber(vector<int>& nums) {
          vector<string> arr;
        for (auto i : nums) 
            arr.push_back(to_string(i));
            
        sort(begin(arr),end(arr),   [](string &s1,string &s2)  {  return s1+s2>s2+s1;    });
        
        string res;
        
        for (auto s : arr) 
            res+=s;
        
        while(res[0] == '0' && res.length()>1)
            res.erase(0,1);
        
        return res;
    }
};
