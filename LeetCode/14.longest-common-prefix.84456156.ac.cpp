/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (31.57%)
 * Total Accepted:    232.7K
 * Total Submissions: 737.2K
 * Testcase Example:  '[]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        int size = strs.size();
        if (size == 0 )
            return res;
        res = strs[0];
        for (int i = 1;i < size;i++) {
            string::iterator t,j;
            t = res.begin();
            j = strs[i].begin();
            while (*t == *j) {
                t++;
                j++;
            }
            res.clear();
            res = string(strs[i].begin(),j); 
        }
        return res;
        
       
    }
};
