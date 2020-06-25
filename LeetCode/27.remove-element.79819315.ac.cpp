/*
 * [27] Remove Element
 *
 * https://leetcode.com/problems/remove-element/description/
 *
 * algorithms
 * Easy (40.13%)
 * Total Accepted:    246.8K
 * Total Submissions: 614.9K
 * Testcase Example:  '[3,2,2,3]\n3'
 *
 * Given an array and a value, remove all instances of that value in-place and
 * return the new length.
 * 
 * 
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * The order of elements can be changed. It doesn't matter what you leave
 * beyond the new length.
 * 
 * 
 * Example:
 * 
 * Given nums = [3,2,2,3], val = 3,
 * 
 * Your function should return length = 2, with the first two elements of nums
 * being 2.
 * 
 * 
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        return distance(nums.begin(),remove(nums.begin(),nums.end(),val));
    }
};
