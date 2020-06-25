/*
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (26.40%)
 * Total Accepted:    124.4K
 * Total Submissions: 471.2K
 * Testcase Example:  '[-2]'
 *
 * 
 * Find the contiguous subarray within an array (containing at least one
 * number) which has the largest product.
 * 
 * 
 * 
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6.
 * 
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        
        if (len == 0)
            return 0;
        
        int maxherepre = nums[0];
        int minherepre = nums[0];
        int maxsofar = nums[0];
        int maxhere,minhere;
        
        for (int i=1;i<len;++i){    
            
            maxhere = max(max(maxherepre*nums[i],minherepre*nums[i]),nums[i]);
            minhere = min(min(maxherepre*nums[i],minherepre*nums[i]),nums[i]);
            
            
            maxsofar = max(maxhere,maxsofar);
            maxherepre = maxhere;
            minherepre = minhere;
        }
        
        return maxsofar;
        
    }
};
