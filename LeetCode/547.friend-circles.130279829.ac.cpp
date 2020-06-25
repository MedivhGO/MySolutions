/*
 * [547] Friend Circles
 *
 * https://leetcode.com/problems/friend-circles/description/
 *
 * algorithms
 * Medium (49.19%)
 * Total Accepted:    27.2K
 * Total Submissions: 55.3K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 * 
 * There are N students in a class. Some of them are friends, while some are
 * not. Their friendship is transitive in nature. For example, if A is a direct
 * friend of B, and B is a direct friend of C, then A is an indirect friend of
 * C. And we defined a friend circle is a group of students who are direct or
 * indirect friends.
 * 
 * 
 * 
 * Given a N*N matrix M representing the friend relationship between students
 * in the class. If M[i][j] = 1, then the ith and jth students are direct
 * friends with each other, otherwise not. And you have to output the total
 * number of friend circles among all the students.
 * 
 * 
 * Example 1:
 * 
 * Input: 
 * [[1,1,0],
 * ⁠[1,1,0],
 * ⁠[0,0,1]]
 * Output: 2
 * Explanation:The 0th and 1st students are direct friends, so they are in a
 * friend circle. The 2nd student himself is in a friend circle. So return
 * 2.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * [[1,1,0],
 * ⁠[1,1,1],
 * ⁠[0,1,1]]
 * Output: 1
 * Explanation:The 0th and 1st students are direct friends, the 1st and 2nd
 * students are direct friends, so the 0th and 2nd students are indirect
 * friends. All of them are in the same friend circle, so return 1.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * N is in range [1,200].
 * M[i][i] = 1 for all students.
 * If M[i][j] = 1, then M[j][i] = 1.
 * 
 * 
 */

class Solution {
private:
    int find(int x,vector<int>& parents) {
        return parents[x] == x ? x : find(parents[x],parents);
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
       
        int row = M.size();
        if (row == 0) return row;
        int ans = row; 
        vector<int> leads(row,0);
        
        for (int i = 0; i < row ;i++) leads[i] = i;  //初始化 在数组leads中的每个元素leads[i]表示 节点i的父节点。
        
        
        for (int i = 0; i < row ;i++) 
            for (int j = i+1;j<row;j++) {
                if (M[i][j]) {
                    int iRoot = find(i,leads);
                    int jRoot = find(j,leads);
                    if (iRoot != jRoot) {
                        leads[iRoot] = jRoot; //如果两个人没有联系，建立联系。将iRoot的放到以jRoot所在的树上。
                        ans--;
                    }                     
                }
            }
        return ans;        
    }
};
