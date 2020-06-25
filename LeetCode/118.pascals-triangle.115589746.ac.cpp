/*
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (39.48%)
 * Total Accepted:    155.3K
 * Total Submissions: 393.4K
 * Testcase Example:  '0'
 *
 * Given numRows, generate the first numRows of Pascal's triangle.
 * 
 * 
 * For example, given numRows = 5,
 * Return
 * 
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {//从右向左版
        vector<vector<int>> result;
        vector<int> array;
        for (int i = 1;i<=numRows;i++) {
            for (int j = i-2;j>0;j--) {
                array[j] = array[j-1] + array[j];
            }
            array.push_back(1);
            result.push_back(array);
        }
        return result;
    }
};
