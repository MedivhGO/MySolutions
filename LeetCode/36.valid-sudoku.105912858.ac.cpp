/*
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku/description/
 *
 * algorithms
 * Medium (36.83%)
 * Total Accepted:    139K
 * Total Submissions: 377.5K
 * Testcase Example:  '[[".","8","7","6","5","4","3","2","1"],["2",".",".",".",".",".",".",".","."],["3",".",".",".",".",".",".",".","."],["4",".",".",".",".",".",".",".","."],["5",".",".",".",".",".",".",".","."],["6",".",".",".",".",".",".",".","."],["7",".",".",".",".",".",".",".","."],["8",".",".",".",".",".",".",".","."],["9",".",".",".",".",".",".",".","."]]'
 *
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 * 
 * The Sudoku board could be partially filled, where empty cells are filled
 * with the character '.'.
 * 
 * 
 * 
 * A partially filled sudoku which is valid.
 * 
 * 
 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable. Only
 * the filled cells need to be validated.
 * 
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,bool> m;
        int ans = false;
        int row = board.size();
        if (row == 0)
            return ans;
        int col = board[0].size();
        //按行遍历
        for (int i = 0; i < row;++i) {
            for (int j = 0; j < col;++j) {
               char elem = board[i][j];
               if (elem == '.') continue;
               else {
                   if (m.find(elem) == m.end()) m[elem] = true;
                   else  return false;
               }
            }
            m.clear();
        }
        //按列遍历
         for (int i = 0; i < row;++i) {
            for (int j = 0; j < col;++j) {
                char elem = board[j][i];
                if (elem == '.') continue;
                else {
                    if (m.find(elem) == m.end()) m[elem] = true;
                    else return false;
                }
            }
            m.clear();
        }
            //按小方格遍历
        for (int i = 0 ;i < 3;++i) {
            for (int j =0;j <3;++j) {
                
                for (int c = i*3;c < i*3+3;++c)
                    for (int  r = j*3;r < j*3+3;++r) {
                        char elem = board[c][r];
                     if (elem == '.') continue;
                      else {
                         if (m.find(elem) == m.end()) m[elem] = true;
                            else return false;
                         }
                    }
                    
                m.clear();
                
            }
            
        }
    
        
        
        return true;
    }
};
