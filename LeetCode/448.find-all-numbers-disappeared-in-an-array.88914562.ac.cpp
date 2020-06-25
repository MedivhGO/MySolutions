/*
 * [448] Find All Numbers Disappeared in an Array
 *
 * https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
 *
 * algorithms
 * Easy (51.33%)
 * Total Accepted:    72.2K
 * Total Submissions: 140.7K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some
 * elements appear twice and others appear once.
 * 
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 * 
 * Could you do it without extra space and in O(n) runtime? You may assume the
 * returned list does not count as extra space.
 * 
 * Example:
 * 
 * Input:
 * [4,3,2,7,8,2,3,1]
 * 
 * Output:
 * [5,6]
 * 
 * 
 */
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        const int n = nums.size();
       
        sort(nums.begin(),nums.end());
       
        unique(nums.begin(),nums.end());
       
        vector<int> res;
        int count = nums.size();
        int i=1;
        int j=1;
        while(j <= n && i<=count ) {
            if(nums[i-1]!=j){
                res.push_back(j);
                j++;
            }
            else {
                i++;
                j++;
            }
        }
        return res;
    }
};
