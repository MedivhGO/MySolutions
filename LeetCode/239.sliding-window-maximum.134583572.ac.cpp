/*
 * [239] Sliding Window Maximum
 *
 * https://leetcode.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (33.82%)
 * Total Accepted:    78.7K
 * Total Submissions: 232.6K
 * Testcase Example:  '[]\n0'
 *
 * Given an array nums, there is a sliding window of size k which is moving
 * from the very left of the array to the very right. You can only see the k
 * numbers in the window. Each time the sliding window moves right by one
 * position.
 * 
 * For example,
 * Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
 * 
 * 
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * Therefore, return the max sliding window as [3,3,5,5,6,7].
 * 
 * Note: 
 * You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for
 * non-empty array.
 * 
 * Follow up:
 * Could you solve it in linear time?
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> buffer;//存储有可能成为最大值的元素 
        vector<int> res;

        for(auto i=0; i<nums.size();++i)
        {
            while(!buffer.empty() && nums[i]>=nums[buffer.back()]) buffer.pop_back();//保证buff中最左侧的元素是最大的
            buffer.push_back(i);

            if(i>=k-1) res.push_back(nums[buffer.front()]);// 当i大于等于k-1时就res就会开始产生题目所需要的结果。
            if(buffer.front()<= i-k+1) buffer.pop_front();//这条语句保证了buff中的元素都在同一窗口的
        }
        return res;
    }
};
