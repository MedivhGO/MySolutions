/*
 * [594] Longest Harmonious Subsequence
 *
 * https://leetcode.com/problems/longest-harmonious-subsequence/description/
 *
 * algorithms
 * Easy (41.02%)
 * Total Accepted:    16.9K
 * Total Submissions: 41.2K
 * Testcase Example:  '[1,3,2,2,5,2,3,7]'
 *
 * We define a harmonious array is an array where the difference between its
 * maximum value and its minimum value is exactly 1.
 * 
 * Now, given an integer array, you need to find the length of its longest
 * harmonious subsequence among all its possible subsequences.
 * 
 * Example 1:
 * 
 * Input: [1,3,2,2,5,2,3,7]
 * Output: 5
 * Explanation: The longest harmonious subsequence is [3,2,2,2,3].
 * 
 * 
 * 
 * Note:
 * The length of the input array will not exceed 20,000.
 * 
 * 
 * 
 */
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int maxSum = 0;
        int len = nums.size();
        if (len == 0)
            return 0;
        int minarr = *(min_element(nums.begin(),nums.end()));
        int maxarr = *(max_element(nums.begin(),nums.end()));
        if (minarr == maxarr)
            return 0;
        unordered_map<int,size_t> m;
        for (int i=0;i < len;++i) {
            m[nums[i]]++;
        }
        for (int i=0;i < len;++i) {
            if (m.find(nums[i]+1)!= m.end()) {
                int t = m[nums[i]+1] + m[nums[i]];
                if (t>maxSum)
                    maxSum = t;
            }
            if (m.find(nums[i]-1)!=m.end()) {
                int t = m[nums[i]-1] + m[nums[i]];
                if (t > maxSum)
                    maxSum = t;
            }
        }
        return maxSum;
    }
};
