/*
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (27.68%)
 * Total Accepted:    157.8K
 * Total Submissions: 570.3K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * 
 * 
 * For example,
 * Given board = 
 * 
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
 * 
 */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || word.empty()) return false;
        int row = board.size();
        int col = board[0].size();
        if(row * col < word.size()) return false;
        for (int i = 0; i < row;i++) 
            for (int j = 0; j < col;j++ )
                if (fun(board,0,i,j,word)) return true;
        
        return false;
        
    }
    bool fun(vector<vector<char>> &board,int cur,int i,int j,const string &word) {
        if (cur >= word.size()) return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[i].size()) return false;
        if (board[i][j] == word[cur++]) {
            char c = board[i][j];
            board[i][j] = '#';
            bool ans = fun(board,cur,i+1,j,word) || fun(board,cur,i-1,j,word) || fun(board,cur,i,j+1,word) || fun(board,cur,i,j-1,word);
            board[i][j] = c;
            return ans;
        }
        
        
        return false;
       
    }
};
