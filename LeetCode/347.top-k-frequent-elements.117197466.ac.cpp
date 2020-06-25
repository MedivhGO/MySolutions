/*
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (49.06%)
 * Total Accepted:    86.7K
 * Total Submissions: 176.8K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * For example,
 * Given [1,1,1,2,2,3] and k = 2, return [1,2].
 * 
 * 
 * Note: 
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * 
 */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        if (nums.empty()) return ans;
        unordered_map<int,int> m;
        for (auto x : nums) {
            m[x]++;
        }
        
        priority_queue<pair<int,int>> pq ; //大端堆
        for (auto t : m) {
            pq.push(make_pair(t.second,t.first));
        }
        
        for (int i=0;i<k;i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
       
        
        return ans;
        
    }
};
