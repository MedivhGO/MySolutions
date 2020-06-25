/*
 * [628] Maximum Product of Three Numbers
 *
 * https://leetcode.com/problems/maximum-product-of-three-numbers/description/
 *
 * algorithms
 * Easy (45.11%)
 * Total Accepted:    26.8K
 * Total Submissions: 59.5K
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array, find three numbers whose product is maximum and
 * output the maximum product.
 * 
 * Example 1:
 * 
 * Input: [1,2,3]
 * Output: 6
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1,2,3,4]
 * Output: 24
 * 
 * 
 * 
 * Note:
 * 
 * The length of the given array will be in range [3,104] and all elements are
 * in the range [-1000, 1000].
 * Multiplication of any three numbers in the input won't exceed the range of
 * 32-bit signed integer.
 * 
 * 
 */
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size() < 3)
         	return 0;
        int ans;
        int len = nums.size();
        sort(nums.begin(),nums.end());
        
        int tmp1 = nums[len-1] * nums[len-2] * nums[len-3];
        int tmp2 = nums[0]*nums[1] * nums[len-1];
        
        ans = tmp1 >= tmp2 ? tmp1 : tmp2;
        
        return ans;
        
        
        
    }
};
