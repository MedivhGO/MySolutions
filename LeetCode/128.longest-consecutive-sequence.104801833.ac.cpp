/*
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (37.78%)
 * Total Accepted:    126.9K
 * Total Submissions: 336K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 * 
 * 
 * For example,
 * Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4]. Return its
 * length: 4.
 * 
 * 
 * Your algorithm should run in O(n) complexity.
 * 
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> used;
        
        for (auto i : nums) used[i] = false;
        
        int longest = 0;
        
        for (auto i: nums) {
            if (used[i]) continue; //如果为true说明这个点已经被 连续的子序列搜索过了，如果再搜索它，就重复计算了。
            
            int length = 1;
            used[i] = true;
            
            for (int j = i+1;used.find(j)!=used.end();++j) {
                used[j] = true;
                ++length;
            }
            
            for (int j = i-1;used.find(j)!=used.end();--j) {
                used[j] = true;
                ++length;
            }
            
            longest = max(longest,length);
        }
        
        return longest;
    }
};
