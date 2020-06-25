/*
 * [540] Single Element in a Sorted Array
 *
 * https://leetcode.com/problems/single-element-in-a-sorted-array/description/
 *
 * algorithms
 * Medium (56.12%)
 * Total Accepted:    24K
 * Total Submissions: 42.8K
 * Testcase Example:  '[1,1,2]'
 *
 * 
 * Given a sorted array consisting of only integers where every element appears
 * twice except for one element which appears once. Find this single element
 * that appears only once. 
 * 
 * 
 * Example 1:
 * 
 * Input: [1,1,2,3,3,4,4,8,8]
 * Output: 2
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [3,3,7,7,10,11,11]
 * Output: 10
 * 
 * 
 * 
 * Note:
 * Your solution should run in O(log n) time and O(1) space.
 * 
 * 
 */
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (mid % 2 == 0)  {
                if (nums[mid] == nums[mid-1]) right = mid-2;
                else if (nums[mid] == nums[mid+1]) left = mid+2;
                else return nums[mid];
            }
            else {
                if (nums[mid] == nums[mid-1]) left = mid+1;
                else if (nums[mid] == nums[mid+1]) right = mid-1;
            }
        }
        return nums[left];
    }
};
