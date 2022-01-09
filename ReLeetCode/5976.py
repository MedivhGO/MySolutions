class Solution:
    def checkValid(self, matrix: List[List[int]]) -> bool:
        n = len(matrix)
        for i in range(0, n):
            col_set = set()
            row_set = set()
            for j in range(0, n):
                if matrix[i][j] in col_set or matrix[j][i] in row_set:
                    return False
                if matrix[i][j] not in col_set:
                    col_set.add(matrix[i][j])
                if matrix[j][i] not in row_set:
                    row_set.add(matrix[j][i])
        return True

# 这道题关键是要认识到, 在两个for循环中可以同时以行和列的方式进行遍历矩阵
# 这样我们就可以用在一维数组中判断数值是不是唯一的思路去解决这个问题.

# 时间复杂度 O(n^2)
# 空间复杂度 O(n)