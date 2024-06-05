class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int m =  n * n;
        int d1 = -(m+1)*m / 2;
        long long d2 = (long long)-m * (m+1) * (m * 2 + 1) / 6;
        for (auto& row : grid) {
            for (auto& x : row) {
                d1 += x;
                d2 += x * x;
            }
        }
        int d = d2 / d1;
        return {(d + d1)/2, (d - d1)/2};
    }
};

# 时间复杂度 O(1)
# 空间复杂度 O(1)

# 一个连续的数组中，有一个值多出现了一次，一个值少出现了一次，可以总结出如上述公式
# 先计算连续和与连续的平方和，然后与当前数组中的所有值的和，与值的平方和相减。
# 得到 d1 与 d2，同时计算 d = d2 / d1
# 此时这个 a = (d + d1)/2, b = (d - d1)/2