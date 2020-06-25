/*
 * [89] Gray Code
 *
 * https://leetcode.com/problems/gray-code/description/
 *
 * algorithms
 * Medium (41.94%)
 * Total Accepted:    100.6K
 * Total Submissions: 239.8K
 * Testcase Example:  '0'
 *
 * The gray code is a binary numeral system where two successive values differ
 * in only one bit.
 * 
 * Given a non-negative integer n representing the total number of bits in the
 * code, print the sequence of gray code. A gray code sequence must begin with
 * 0.
 * 
 * For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 * 
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 * 
 * 
 * Note:
 * For a given n, a gray code sequence is not uniquely defined.
 * 
 * For example, [0,2,3,1] is also a valid gray code sequence according to the
 * above definition.
 * 
 * For now, the judge is able to judge based on one instance of gray code
 * sequence. Sorry about that.
 */
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> mi;
        vector<int> ans;
        ans.push_back(0);
        for (int i=0;i<n;i++) {
            mi.push_back(1<<i);
        }
        for (int i=0;i<n;i++) 
            for (int k = ans.size()-1;k>=0;k--) {
                ans.push_back(ans[k]|mi[i]);
        }
        
        return ans;
    }
};
