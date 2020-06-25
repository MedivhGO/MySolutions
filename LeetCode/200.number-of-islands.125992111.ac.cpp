/*
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (35.93%)
 * Total Accepted:    147.1K
 * Total Submissions: 409.5K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 11110110101100000000
 * Answer: 1
 * Example 2:
 * 11000110000010000011
 * Answer: 3
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 */
class UF {
public:
	UF(int N) { //进行初始化1维数组。
		count = N;
		id = new int[N];
		weight = new int[N];
		for (int i = 0; i < N; i++) {
			id[i] = i;
			weight[i] = 0;
		}
	}
	~UF() {
		delete[]id;
		delete[]weight;
	}
	void unionP(int p, int q) {
		int i = root(p);
		int j = root(q);
		if (i == j) { //两个点的根相同
			return;
		}
		if (weight[i] < weight[j]) { //如果j的树中节点大于i的树中节点，就让i成为j的子树
			id[i] = j;
		}
		else if (weight[i] > weight[j]) {//如果i的树中节点大于j的树中节点，就让j成为i的子树
			id[j] = i;
		}
		else {
			id[i] = j;  //就让i成为j的子树
			weight[j]++;//记录j树中的节点数量。
		}
		count--; //记录已经连结的区域个数。
	}
	bool connected(int p, int q) { //判断两个点是否连结
		return root(p) == root(q);
	}
	int getCount() { //返回独立区域个数
		return count;
	}
private:
	int *id;
	int *weight;
	int count;
	int root(int i) {
		while (i != id[i]) {
			id[i] = id[id[i]];
			i = id[i];
		}
		return i;
	}
};

class Solution {
public:
	// Runtime: 8 ms
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty() || grid[0].empty()) {
			return 0;
		}
		int ROW = grid.size(), COL = grid[0].size();
		UF uf(ROW * COL + 1);
		int dummyPoint = ROW * COL; // We assume it as 0 and it connects all 0s.
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				if (grid[i][j] == '1') {
					if (j != COL - 1 && grid[i][j + 1] == '1') {
						uf.unionP(i * COL + j, i * COL + j + 1);
					}
					if (i != ROW - 1 && grid[i + 1][j] == '1') {
						uf.unionP(i * COL + j, (i + 1) * COL + j);
					}
				}
				else {
					uf.unionP(i * COL + j, dummyPoint);
				}
			}
		}
		return uf.getCount() - 1;
	}
};
