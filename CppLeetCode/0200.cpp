class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    ans++;
                    helper(grid, i, j, n, m);
                }
            }
        }
        return ans;
    }
    void helper(vector<vector<char>>& grid, int i, int j, int n, int m) {
        if (i < 0 || j < 0 || i >=n || j >= m) {
            return;
        }
        if (grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        helper(grid, i + 1, j, n, m);
        helper(grid, i, j + 1, n, m);
        helper(grid, i - 1, j, n, m);
        helper(grid, i, j-1, n, m);
    }
};

// 遍历 grid 中的每一个 '1' 的位置，当碰到 '1' 就将与其相邻的所有 '1'
// 都置为 '0'。使用 dfs 方法实现上述过程。其中退出条件为：
// 1. dfs 函数遇到了边界
// 2. 遇到了 '0' 的位置