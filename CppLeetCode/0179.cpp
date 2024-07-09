class Solution {
public:
    string largestNumber(vector<int>& nums) {
        std::ranges::sort(nums,[](const int& x, const int&y) {
            return to_string(x) + to_string(y) > to_string(y) + to_string(x);
        });
        if (nums[0] == 0) {
            return "0";
        }
        string s;
        for (auto& x : nums) {
            s += to_string(x);
        }
        return s;
    }
};

// 时间复杂度 O(nlgn)
// 空间复杂度 O(n)

// 拼接结果的字典序大小决定其在序列里的相对顺序