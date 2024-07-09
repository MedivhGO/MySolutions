class Solution {
public:
    int lengthOfLastWord(string s) {
        int ret = 0;
        if (s.empty()) {
            return ret;
        }
        long end = s.size() - 1;
        while (s[end] == ' ') {
            end--;
        }
        long count = 0;
        while (end >= 0 && s[end] != ' ') {
            count++;
            end--;
        }
        return count;
    }
};

// 时间复杂度 O(n)
// 空间复杂度 O(1)

// 从后往前遍历
// 先找到第一个非空的位置 end，以这个位置为起点记录字符个数 count
// 直到碰到空格，最后返回 count
