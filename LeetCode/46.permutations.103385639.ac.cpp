/*
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (45.86%)
 * Total Accepted:    207.3K
 * Total Submissions: 452.1K
 * Testcase Example:  '[1,2,3]'
 *
 * 
 * Given a collection of distinct numbers, return all possible permutations.
 * 
 * 
 * 
 * For example,
 * [1,2,3] have the following permutations:
 * 
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    void fun(vector<vector<int>>& ans, vector<int> nums, int cur,vector<int> &t) {
        if (cur == nums.size()) {
            ans.push_back(t);
        } else for (int i=0;i<nums.size();i++) {
            int ok = 1;
            for (int j=0;j<cur;j++) {
                if (t[j] == nums[i]) ok = 0 ;
            }
            if(ok) {
                t[cur] = nums[i];
                fun(ans,nums,cur+1,t);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> t(nums.size(),-999);
        fun(ans,nums,0,t);
        
        return ans;
    }
};
