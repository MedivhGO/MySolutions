/*
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (40.35%)
 * Total Accepted:    195.3K
 * Total Submissions: 483.9K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 
 * Given a set of candidate numbers (C) (without duplicates) and a target
 * number (T), find all unique combinations in C where the candidate numbers
 * sums to T. 
 * 
 * 
 * The same repeated number may be chosen from C unlimited number of times.
 * 
 * 
 * Note:
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * 
 * 
 * For example, given candidate set [2, 3, 6, 7] and target 7, 
 * A solution set is: 
 * 
 * [
 * ⁠ [7],
 * ⁠ [2, 2, 3]
 * ]
 * 
 * 
 */
class Solution {
public:
    void dfs(vector<int>& data,int cur,vector<int> tmp,int target,vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(tmp);
            return ;
        }
        for (int i=cur;i<data.size();i++) {
            if (data[i]>target) return ;
            tmp.push_back(data[i]);
            dfs(data,i,tmp,target-data[i],ans);
            tmp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        if(candidates.empty() ) return ans;
        sort(candidates.begin(),candidates.end());
        vector<int> tmp;
        dfs(candidates,0,tmp,target,ans);
        return ans;
    }
};
