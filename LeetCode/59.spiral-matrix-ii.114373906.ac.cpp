/*
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (40.48%)
 * Total Accepted:    93.4K
 * Total Submissions: 230.7K
 * Testcase Example:  '0'
 *
 * Given an integer n, generate a square matrix filled with elements from 1 to
 * n2 in spiral order.
 * 
 * 
 * For example,
 * Given n = 3,
 * 
 * You should return the following matrix:
 * 
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        int begin = 0,end = n-1;
        int num = 1;
        while (begin < end) {
            for (int j = begin;j<end;j++) ans[begin][j] = num++;
            for (int j = begin;j<end;j++) ans[j][end] = num++;
            for (int j = end;j>begin;j--) ans[end][j] = num++;
            for (int j = end;j>begin;j--) ans[j][begin] = num++;
            begin++;
            end--;
        }
        if (begin == end) ans[end][end] = num++;
            
        return ans;
    }
};
