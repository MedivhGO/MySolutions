class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        int begin = 0, end = 0;
        int n = s.size();
        int res = INT_MIN;
        while (end < n && begin <= end) {
            if (m.find(s[end]) == m.end()) {
                m[s[end]]++;
                end++;
            } else {
                m.erase(s[begin]);
                begin++;
            }
            res = max(res, (int) m.size());
        }
        return res;
    }

private:
    std::unordered_map<char, int> m;
};


// 时间复杂度 O(n)
// 空间复杂度 O(max(len)) 无重复子串的长度

// 使用 [begin, end] 来标识遍历过程中的子串
// 在遍历过程中，要保持 hash 表中的元素不重复，在插入 end 元素中
// 如果发现重复元素 begin 就向前移动，直到 end 元素在 hash 表中不再重复。