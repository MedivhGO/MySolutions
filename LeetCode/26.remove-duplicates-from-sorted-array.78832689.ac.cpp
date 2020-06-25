/*
 * [26] Remove Duplicates from Sorted Array
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 *
 * algorithms
 * Easy (35.78%)
 * Total Accepted:    297.1K
 * Total Submissions: 830.5K
 * Testcase Example:  '[1,1,2]'
 *
 * 
 * Given a sorted array, remove the duplicates in-place such that each element
 * appear only once and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * 
 * Example:
 * 
 * Given nums = [1,1,2],
 * 
 * Your function should return length = 2, with the first two elements of nums
 * being 1 and 2 respectively.
 * It doesn't matter what you leave beyond the new length.
 * 
 * 
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return distance(nums.begin(),unique(nums.begin(),nums.end()));
        //distacne 接受两个参数，起始迭代器，和终止迭代器，
        //unique() 返回最后一个元素的后面一位的迭代器
    }
};
