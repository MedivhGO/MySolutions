/*
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (35.13%)
 * Total Accepted:    137.8K
 * Total Submissions: 392.3K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 
 * Given a collection of candidate numbers (C) and a target number (T), find
 * all unique combinations in C where the candidate numbers sums to T.
 * 
 * 
 * Each number in C may only be used once in the combination.
 * 
 * Note:
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * 
 * 
 * For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
 * A solution set is: 
 * 
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 */
class Solution {
public:
    void dfs(vector<int>& candidates,vector<int> tmp,int cur,int gap,vector<vector<int>>& ans) {
        if (gap == 0) {
            ans.push_back(tmp);
            return ;
        }
        //扩展所有可能
        int previous = -1;
        for (int i = cur;i<candidates.size();i++) {
            if (previous == candidates[i]) continue;
            if (gap<candidates[i]) return ;
            previous = candidates[i];
            tmp.push_back(candidates[i]);
            dfs(candidates,tmp,i+1,gap-candidates[i],ans);
            tmp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        if (candidates.empty()) return ans;
        sort(candidates.begin(),candidates.end());
        vector<int> tmp;
        dfs(candidates,tmp,0,target,ans); 
        return ans;
    }
};
