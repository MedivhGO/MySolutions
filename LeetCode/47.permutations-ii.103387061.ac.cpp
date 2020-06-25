/*
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (34.16%)
 * Total Accepted:    146.4K
 * Total Submissions: 428.5K
 * Testcase Example:  '[1,1,2]'
 *
 * 
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * 
 * 
 * For example,
 * [1,1,2] have the following unique permutations:
 * 
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    void fun(vector<vector<int>>& ans,vector<int> nums,vector<int> t, int cur) {
        if (cur == nums.size()) {
            ans.push_back(t);
        } else for (int i=0;i<nums.size();i++) 
            if (nums[i]!=nums[i-1] ||  !i )
            {
              int c1 = 0,c2 = 0; // c1统计在t串中nums[i] 出现的次数，c2统计nums 中 nums[i] 出现的次数。
              for (int j=0;j<cur;j++) {
                  if (t[j] == nums[i]) c1++;
              }
              for (int j=0;j<nums.size();j++) {
                  if (nums[j] == nums[i]) c2++;
              }
              if (c1 < c2) {
                  t[cur] = nums[i];
                  fun(ans,nums,t,cur+1);
              }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> t(nums.size(),-999);
        sort(nums.begin(),nums.end());
        fun(ans,nums,t,0);
        
        return ans;
    }
};
