/*
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (43.17%)
 * Total Accepted:    206.2K
 * Total Submissions: 477.6K
 * Testcase Example:  '[1,2,3]'
 *
 * 
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * 
 * For example,
 * If nums = [1,2,3], a solution is:
 * 
 * 
 * 
 * [
 * ⁠ [3],
 * ⁠ [1],
 * ⁠ [2],
 * ⁠ [1,2,3],
 * ⁠ [1,3],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> t;
        fun(ans,nums,0,t);
        
        return ans;
    }
private:
    void fun(vector<vector<int>>& ans,const vector<int> nums,int cur,vector<int> &t) {
        if (cur == nums.size()) {
            ans.push_back(t);
            return;
        }
        fun(ans,nums,cur+1,t);
        
        t.push_back(nums[cur]);
        
        fun(ans,nums,cur+1,t);
        
        t.pop_back();
    }
};
