/*
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (37.33%)
 * Total Accepted:    143.9K
 * Total Submissions: 385.5K
 * Testcase Example:  '[]'
 *
 * 
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after
 * raining. 
 * 
 * 
 * 
 * For example, 
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 * 
 * 
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 */
class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        int *max_left = new int[n]();
        int *max_right = new int[n]();
        
        for (int i = 1; i < n ;i++) {
            max_left[i] = max(max_left[i-1],height[i-1]);
            max_right[n-1-i] = max(max_right[n-i],height[n-i]);
        }
        
        int sum = 0;
        
        for (int i = 0; i < n ;i++) {
            int t = min(max_left[i],max_right[i]);
            if (t > height[i]){
                sum+=t-height[i];
            }
        }
        delete[] max_left;
        delete[] max_right;
        
        return sum;
    }
};
