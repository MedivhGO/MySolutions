/*
 * [220] Contains Duplicate III
 *
 * https://leetcode.com/problems/contains-duplicate-iii/description/
 *
 * algorithms
 * Medium (18.91%)
 * Total Accepted:    62.3K
 * Total Submissions: 329.6K
 * Testcase Example:  '[]\n0\n0'
 *
 * 
 * Given an array of integers, find out whether there are two distinct indices
 * i and j in the array such that the absolute difference between nums[i] and
 * nums[j] is at most t and the absolute difference between i and j is at most
 * k.
 * 
 */
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        //每个数进入滑动窗口的时候检测其左侧的距离在k之内的数据是否重复完成
        //每个数在出去的时候检测其右侧是否重复完成
        //窗口的大小为k+1
        set<long> s;
        for (int i = 0; i < nums.size();i++) {
            if (i>k) s.erase(nums[i-k-1]);
            auto pos = s.lower_bound(long (nums[i]) - t); //检测是否有一个x（nums[i]的左侧元素）满足与nums[i]差不超过t， 及这个值x满足x>=nums[i]-t;
            
            if (pos!= s.end() && *pos-nums[i] <=t) return true;// x <= nums[i] + t;
            s.insert(long(nums[i]));
        }
        return false;
        
    }
};
