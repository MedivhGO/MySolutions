class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        string comm = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            string cur_str = strs[i];
            int j = 0;
            while (j < cur_str.size() && comm[j] == cur_str[j]) {
                j++;
            }
            comm = comm.substr(0, j);
            if (comm.empty()) {
                return comm;
            }
        }
        return comm;
    }
};

// 时间复杂度 O(n^2)
// 空间复杂度 O(1)

// 在遍历的过程中如果公共子串为空，就可提前结束，能大幅提高速度。