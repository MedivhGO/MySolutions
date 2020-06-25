/*
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (19.15%)
 * Total Accepted:    94.3K
 * Total Submissions: 492.2K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * 
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
 * surrounded by 'X'.
 * 
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 * 
 * 
 * 
 * For example,
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * 
 * 
 * After running your function, the board should be:
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 */
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int i,j;
        int row = board.size();
        if (row == 0) return ;
        int col = board[0].size();
        
        for ( i = 0; i < row ;i++) {
            check(board,i,0,row,col); //检查第1列,将第一列中的O变成1
            if(col > 1)
                check(board,i,col-1,row,col) ;//检查最后一列，将最后一列中的0变成1
        }
        
        for (j = 1; j+1 < col ;j++) {
            check(board,0,j,row,col); //检查第一行，将第一行中的0变成1
            if (row > 1)
                check(board,row-1,j,row,col);
        }
        
        for (i = 0; i< row ;i++)
            for (j = 0; j < col;j++)
                if (board[i][j] == 'O')
                        board[i][j] = 'X';
        
        for (i = 0; i< row ;i++)
            for (j = 0; j < col;j++)
                if (board[i][j] == '1')
                        board[i][j] = 'O';
        
        
        
        
        
        
            
        
    }
    void check(vector<vector<char>>& vec,int i,int j,int row,int col) {
        if (vec[i][j] == 'O') {
            vec[i][j] = '1';
            if (i>1)
                check(vec,i-1,j,row,col);
            if (j>1)
                check(vec,i,j-1,row,col);
            if (i+1<row) 
                check(vec,i+1,j,row,col);
            if (j+1<col)
                check(vec,i,j+1,row,col);
        }
        return  ;
    }
};
