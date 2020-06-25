/*
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (37.52%)
 * Total Accepted:    133.5K
 * Total Submissions: 355.8K
 * Testcase Example:  '[1,2,2]'
 *
 * 
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * 
 * For example,
 * If nums = [1,2,2], a solution is:
 * 
 * 
 * 
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        
        unordered_map<int,int> count_map;//记录每个元素的出现次数
        
        for_each(nums.begin(),nums.end(),[&count_map](int e){//使用for_each对vector中的每个元素
        //进行计数                
            if (count_map.find(e)!=count_map.end()) { //找到相应的元素
                        count_map[e]++;
            }
            else {
                count_map[e] = 1;
            }
        });
        vector<pair<int,int>> elems;
        for_each(count_map.begin(),count_map.end(),[&elems](const pair<int,int> &e){
            elems.push_back(e);
        });
        
        sort(elems.begin(),elems.end());
        vector<int> t;
        
        subsets(elems,0,t,ans);
        
        return ans;
    }
private:
    static void subsets(const vector<pair<int,int> >& elems,
    size_t cur,vector<int> &t,vector<vector<int>>& ans) {
        if (cur == elems.size()) {
            ans.push_back(t);
            return ;
        }
        for (int i=0;i<=elems[cur].second;i++) {
            for (int j=0;j<i;j++) {
                t.push_back(elems[cur].first);
            }
            subsets(elems,cur+1,t,ans);
            for (int j=0;j<i;j++) {
                t.pop_back();
            }
        }
    }
};
