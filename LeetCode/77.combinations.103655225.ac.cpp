/*
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (40.63%)
 * Total Accepted:    133K
 * Total Submissions: 327.4K
 * Testcase Example:  '4\n2'
 *
 * 
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * 
 * For example,
 * If n = 4 and k = 2, a solution is:
 * 
 * 
 * 
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */
class Solution {
public:
    void fun(vector<vector<int>>& ans,vector<int>& t,int cur,int k,int n)
    {
        if (cur == k) {
            ans.push_back(t);
        } else for (int i=1;i <= n ;i++) {
            int ok = 1; // == 1 继续向下进行 == 0 回溯
            for (int j = 0;j < cur ;j++) {
                if (t[j] == i || t[j] > i) ok = 0;
            }
            if (ok) { //
                t[cur] = i;
                fun(ans,t,cur+1,k,n);
            }
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector< vector<int> > ans;
        if (n < k)
            return ans;
            
        vector<int> t(k,-999);
        fun(ans,t,0,k,n);
        
        return ans;
        
        
    }
};
