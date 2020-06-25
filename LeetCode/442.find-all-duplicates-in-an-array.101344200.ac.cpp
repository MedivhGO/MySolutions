/*
 * [442] Find All Duplicates in an Array
 *
 * https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
 *
 * algorithms
 * Medium (56.53%)
 * Total Accepted:    47.4K
 * Total Submissions: 83.8K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements
 * appear twice and others appear once.
 * 
 * Find all the elements that appear twice in this array.
 * 
 * Could you do it without extra space and in O(n) runtime?
 * 
 * Example:
 * 
 * Input:
 * [4,3,2,7,8,2,3,1]
 * 
 * Output:
 * [2,3]
 * 
 */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
         vector<int> ans;
         for (int i=0;i<nums.size();i++) {
              
             int t = abs(nums[i]);
             if (nums[t-1]<0)
                  ans.push_back(t);
             else
                 nums[t-1] = -nums[t-1];
         }
         
         return ans;
    }
};
