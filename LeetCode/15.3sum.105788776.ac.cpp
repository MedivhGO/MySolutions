/*
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (21.80%)
 * Total Accepted:    279.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array S of n integers, are there elements a, b, c in S such that a
 * + b + c = 0? Find all unique triplets in the array which gives the sum of
 * zero.
 * 
 * Note: The solution set must not contain duplicate triplets.
 * 
 * 
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;
        sort(nums.begin(),nums.end());
        const int target = 0;
        auto last = nums.end();
        for ( auto i = nums.begin(); i < last-2; ++i ) {
            auto j = i+1;
            if (i > nums.begin() && *i == *(i-1)) continue; //如果ｉ不是第一个元素，且ｉ和 它前一个元素相同 就继续
            auto k = last - 1;
            while (j < k) {
                if (*i+*j+*k < target) {
                    ++j;
                    while (*j == *(j-1) && j < k) ++j;
                } else if (*i+*j+*k > target) {
                    --k;
                    while (*(k+1) == *k && k > j) --k;
                }  else {
                    result.push_back({*i,*j,*k});
                    j++;
                    --k;
                    while (*j == *(j-1) && *(k+1) == *k && j < k) ++j;
                }
            }
        }
        return result;
    }
};
