/*
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (46.54%)
 * Total Accepted:    189.3K
 * Total Submissions: 406.8K
 * Testcase Example:  '[]'
 *
 * 
 * Given an array of integers, find if the array contains any duplicates. Your
 * function should return true if any value appears at least twice in the
 * array, and it should return false if every element is distinct.
 * 
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty()) return false;
        set<int> s;
        for (auto x : nums) {
            if (s.find(x) != s.end()) return true;
            s.insert(x);
        }
        return false;
        
    }
};
