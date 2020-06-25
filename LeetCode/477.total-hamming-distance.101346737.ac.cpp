/*
 * [477] Total Hamming Distance
 *
 * https://leetcode.com/problems/total-hamming-distance/description/
 *
 * algorithms
 * Medium (47.79%)
 * Total Accepted:    27.3K
 * Total Submissions: 57.2K
 * Testcase Example:  '[4,14,2]'
 *
 * The Hamming distance between two integers is the number of positions at
 * which the corresponding bits are different.
 * 
 * Now your job is to find the total Hamming distance between all pairs of the
 * given numbers.
 * 
 * 
 * Example:
 * 
 * Input: 4, 14, 2
 * 
 * Output: 6
 * 
 * Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is
 * 0010 (just
 * showing the four bits relevant in this case). So the answer will be:
 * HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2
 * + 2 + 2 = 6.
 * 
 * 
 * 
 * Note:
 * 
 * Elements of the given array are in the range of 0  to 10^9
 * Length of the array will not exceed 10^4. 
 * 
 * 
 */
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans=0;
        const int len = nums.size();
        
        if (len == 1)
            return 0;
        while (true) {
            int countZero = 0;
            int count[2]= {0,0};// col accumulate
            for (int i=0;i<len;i++) {
                if (nums[i] == 0) countZero++;
                count[nums[i]%2]++;
                nums[i] = nums[i] >> 1;
            } 
        ans+=count[0] * count[1];
        if (countZero == len)   return ans;
        }
    }
};
