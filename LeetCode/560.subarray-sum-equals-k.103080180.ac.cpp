/*
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (40.46%)
 * Total Accepted:    25.4K
 * Total Submissions: 62.8K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers and an integer k, you need to find the total
 * number of continuous subarrays whose sum equals to k.
 * 
 * Example 1:
 * 
 * Input:nums = [1,1,1], k = 2
 * Output: 2
 * 
 * 
 * 
 * Note:
 * 
 * The length of the array is in range [1, 20,000].
 * The range of numbers in the array is [-1000, 1000] and the range of the
 * integer k is [-1e7, 1e7].
 * 
 * 
 * 
 */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int> mapping;
        mapping[0]++;
        
        int sum = 0;
        
        for (int i=0;i < nums.size();i++) {
            
            sum+=nums[i]; //sum[0.j]
            
            ans+=mapping[sum-k]; //sum[i-j]
            
            mapping[sum]++; //sum[0,i-1]
            
        }
        return ans;
    }
};
