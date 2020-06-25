/*
 * [581] Shortest Unsorted Continuous Subarray
 *
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Easy (29.25%)
 * Total Accepted:    25.5K
 * Total Submissions: 87.2K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * Given an integer array, you need to find one continuous subarray that if you
 * only sort this subarray in ascending order, then the whole array will be
 * sorted in ascending order, too.  
 * 
 * You need to find the shortest such subarray and output its length.
 * 
 * Example 1:
 * 
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make
 * the whole array sorted in ascending order.
 * 
 * 
 * 
 * Note:
 * 
 * Then length of the input array is in range [1, 10,000].
 * The input array may contain duplicates, so ascending order here means . 
 * 
 * 
 */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        if (len <=1 ) return 0;
        vector<int> sort_nums(nums.begin(),nums.end());
        sort(sort_nums.begin(),sort_nums.end());
        int start = -1,end = len+1;
        for (int i = 0; i< len;i++) {
            if (sort_nums[i]!= nums[i]){
                start = i;
                break;
            }
            
        }
        for (int i = 0; i< len;i++) {
            if (sort_nums[len-i-1]!= nums[len-i-1]){
                end = len-i-1;
                break;
            }
            
        }
        return start==-1&&end == len+1? 0:end-start+1;
    }
};
