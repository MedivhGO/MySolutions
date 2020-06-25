/*
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (37.68%)
 * Total Accepted:    134.6K
 * Total Submissions: 357.1K
 * Testcase Example:  '0'
 *
 * Given an index k, return the kth row of the Pascal's triangle.
 * 
 * 
 * For example, given k = 3,
 * Return [1,3,3,1].
 * 
 * 
 * 
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        
        
        for (int i = 1; i<=rowIndex+1;i++) {
            
            for (int j = i-2;j>0;j--)
                result[j] = result[j-1]+result[j];
            result.push_back(1);
        }
        
        return result;
    }
};
