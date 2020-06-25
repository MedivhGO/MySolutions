/*
 * [491] Increasing Subsequences
 *
 * https://leetcode.com/problems/increasing-subsequences/description/
 *
 * algorithms
 * Medium (38.98%)
 * Total Accepted:    15.3K
 * Total Submissions: 39.1K
 * Testcase Example:  '[4,6,7,7]'
 *
 * 
 * Given an integer array, your task is to find all the different possible
 * increasing subsequences of the given array, and the length of an increasing
 * subsequence should be at least 2 .
 * 
 * 
 * Example:
 * 
 * Input: [4, 6, 7, 7]
 * Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7],
 * [4,7,7]]
 * 
 * 
 * 
 * Note:
 * 
 * The length of the given array will not exceed 15.
 * The range of integer in the given array is [-100,100].
 * The given array may contain duplicates, and two equal integers should also
 * be considered as a special case of increasing sequence.
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.empty()) return ans;
        vector<int> tmp;
        dfs(ans,tmp,nums,0);
        return ans;
        
    }
    void dfs(vector<vector<int>>& ans,vector<int> tmp,vector<int>& nums,int cur) {
        if (tmp.size() > 1) ans.push_back(tmp);
        unordered_set<int> hash;
        for (int i = cur ;i < nums.size();i++) {
            if ( (tmp.empty()||nums[i] >= tmp.back()) && hash.find(nums[i]) == hash.end()) { //tmp.empty() == true 第一次深搜
                tmp.push_back(nums[i]);
                dfs(ans,tmp,nums,i+1);
                tmp.pop_back();
                hash.insert(nums[i]);
            }
        }
    }
};
