/*
 * [34] Search for a Range
 *
 * https://leetcode.com/problems/search-for-a-range/description/
 *
 * algorithms
 * Medium (31.54%)
 * Total Accepted:    168.7K
 * Total Submissions: 534.8K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers sorted in ascending order, find the starting and
 * ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * 
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 * 
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        const int  a = distance(nums.begin(),lower_bound(nums.begin(),nums.end(),target));
        const int  b = distance(nums.begin(),prev(upper_bound(nums.begin(),nums.end(),target)));
        if (nums[a]!=target) {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        else {
            result.push_back(a);
            result.push_back(b);
            return result;
        }
       
    }
};
