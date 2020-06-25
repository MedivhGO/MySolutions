/*
 * [287] Find the Duplicate Number
 *
 * https://leetcode.com/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (43.97%)
 * Total Accepted:    92.3K
 * Total Submissions: 209.9K
 * Testcase Example:  '[1,1]'
 *
 * 
 * Given an array nums containing n + 1 integers where each integer is between
 * 1 and n (inclusive), prove that at least one duplicate number must exist.
 * Assume that there is only one duplicate number, find the duplicate one.
 * 
 * 
 * 
 * Note:
 * 
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n2).
 * There is only one duplicate number in the array, but it could be repeated
 * more than once.
 * 
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       
       if (nums.size() > 1) {
           int slow = nums[0];
		    int fast = nums[nums[0]];
		    while (slow != fast)
		    {
			slow = nums[slow];
		   	fast = nums[nums[fast]];
		    }
		    
		    //在 nums[t] 与 nums[nums[t]] 中循环但是不知道是 nums[t]的值还是nums[nums[t]]的值。
		    
		    //接下来的循环来确定值是哪一个
		    
		     fast = 0;
		    
		    while (fast != slow) {
		        
		        fast  = nums[fast];
		        slow = nums[slow];
		    }
		    
		    return fast;
		    
       }
       
       return -1;
    }
};
