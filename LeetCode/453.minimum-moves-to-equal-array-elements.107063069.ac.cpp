/*
 * [453] Minimum Moves to Equal Array Elements
 *
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements/description/
 *
 * algorithms
 * Easy (47.87%)
 * Total Accepted:    36.4K
 * Total Submissions: 76K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty integer array of size n, find the minimum number of moves
 * required to make all array elements equal, where a move is incrementing n -
 * 1 elements by 1.
 * 
 * Example:
 * 
 * Input:
 * [1,2,3]
 * 
 * Output:
 * 3
 * 
 * Explanation:
 * Only three moves are needed (remember each move increments two elements):
 * 
 * [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 * 
 * 
 */
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;
        int minelem = *(min_element(nums.begin(),nums.end()));
        int sum = accumulate(nums.begin(),nums.end(),0);
        return sum-len*minelem;
    }
};
