/*
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (47.45%)
 * Total Accepted:    234.8K
 * Total Submissions: 494.8K
 * Testcase Example:  '[1]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.empty())
                return 0;
        	int ans;
        	int count = 0;
        	for (auto x :nums) {
                if (count == 0) {
                    ans = x;
                    count = 1;
                } else {
                    if (x == ans)
                        count++;
                    else
                        count--;
                }
            }
        
        	return ans;
    }
};
