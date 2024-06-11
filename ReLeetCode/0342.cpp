class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && ((n & n-1)) == 0 && (n & (0xaaaaaaaa)) == 0;
    }
};

// 时间复杂度 O(1)
// 空间复杂度 O(1)

// 1. 只有一个 1
// 2. 1 出现在奇数位置
// 3. n > 0