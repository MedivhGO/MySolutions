/*
 * [219] Contains Duplicate II
 *
 * https://leetcode.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (32.70%)
 * Total Accepted:    131.1K
 * Total Submissions: 401K
 * Testcase Example:  '[]\n0'
 *
 * 
 * Given an array of integers and an integer k, find out whether there are two
 * distinct indices i and j in the array such that nums[i] = nums[j] and the
 * absolute difference between i and j is at most k.
 * 
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> cand; //窗口的长度是k+1
        for (int i =0;i < nums.size();i++) {
            if (i > k) cand.erase(nums[i-k-1]);
            if (!cand.insert(nums[i]).second) return true;
        }
        return false;
    }
};
