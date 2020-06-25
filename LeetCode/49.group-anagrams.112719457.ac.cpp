/*
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (36.98%)
 * Total Accepted:    173.1K
 * Total Submissions: 468K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * 
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
 * Return:
 * 
 * [
 * ⁠ ["ate", "eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note: All inputs will be in lower-case.
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        if (strs.empty()) return ans;
        unordered_map<string,vector<string>> m;
        for(auto x : strs) {
            string t  =  x;
            sort(x.begin(),x.end());
            m[x].push_back(t);
        }
        for (auto x : m) {
            ans.push_back(x.second);
        }
        return ans;
        
        
    }
};
