/*
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (26.79%)
 * Total Accepted:    125.3K
 * Total Submissions: 467.6K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * 
 * 
 * For example,
 * Given the following matrix:
 * 
 * 
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 
 * 
 * You should return [1,2,3,6,9,8,7,4,5].
 * 
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        int beginX = 0,endX = matrix[0].size()-1; //水平方向上的开始和结束
        int beginY = 0,endY = matrix.size()-1;//垂直方向上的开始和结束
        while(true) {
            //from left to right
            for (int j = beginX;j<=endX;j++) result.push_back(matrix[beginY][j]);
            //使垂直上侧下移
            if (++beginY>endY) break;//
            //from top to bottom
            for (int i = beginY;i<=endY;++i) result.push_back(matrix[i][endX]);
            //使水平右侧左移
            if (beginX > --endX) break;
            //from right to left
            for (int j = endX;j>=beginX;j--) result.push_back(matrix[endY][j]);
            //使垂直下侧上移
            if (beginY> --endY) break;
            //from bottom to top
            for (int i = endY;i>= beginY;--i) result.push_back(matrix[i][beginX]);
            //使水平左侧右移
            if (++beginX>endX) break;
        }
        return result;
    }
};
