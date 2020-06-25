/*
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (40.06%)
 * Total Accepted:    266K
 * Total Submissions: 663.9K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 
 * Find the contiguous subarray within an array (containing at least one
 * number) which has the largest sum.
 * 
 * 
 * For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 * the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * click to show more practice.
 * 
 * More practice:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */
class Solution {
public:
    int maxSumRec( vector<int>& a,int left,int right) {
        if(left == right) {
            if(a[left]>0)
                return a[left];
            else
                return a[right];
        }
        int center = (left+right) / 2;
        int maxLeftSum = maxSumRec(a,left,center);
        int maxRightSum = maxSumRec(a,center+1,right);
        
        int maxLeftBorderSum = INT_MIN,leftBorderSum = 0;
        
        for(int i=center;i>=left;i--) {
            leftBorderSum+=a[i];
            if(leftBorderSum>maxLeftBorderSum) 
                maxLeftBorderSum = leftBorderSum;
        }
        
        int maxRightBorderSum = INT_MIN,rightBorderSum = 0;
        
        for(int j=center+1;j<=right;j++) {
            rightBorderSum += a[j];
            if(rightBorderSum>maxRightBorderSum)
                maxRightBorderSum = rightBorderSum;
        }
        
        return max(maxLeftSum,max(maxRightSum,maxRightBorderSum+maxLeftBorderSum));
    }
    int maxSubArray(vector<int>& nums) {
        return maxSumRec(nums,0,nums.size()-1);
    }
};
