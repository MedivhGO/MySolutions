class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.empty()) {
            return ans;
        }
        helper(nums, ans, 0, nums.size());
        return ans;
    }

    void helper(vector<int>& nums, vector<vector<int>>& ans, int k, int len) {
        if (k == len) {
            ans.push_back(nums);
            return;
        }
        for (int i = k; i < len; ++i) {
            swap(nums[k], nums[i]);
            helper(nums, ans, k+1, len);
            swap(nums[k], nums[i]);
        }
    }
};

// 时间复杂度 O(n*n!)
// 空间复杂度 O(n)

// 定义一个函数 helper(nums, ans, int begin, int end);
// 使用这个函数能够求得 nums 在 [begin, end) 范围中的所有排列并将
// 结果放入到 ans 中
// 在 helper 函数中，为了对找到 nums 的所有全排列
// 可以将 nums[begin] 元素和 [begin, end) 范围内的所有元素逐个交换。
// 每次交换，其实就是确定了一个排列的第一个位置上的元素
// 接下来递归去调用 helper(nums, ans, begin+1, end)，即可确定
// begin+1, begin+2, ... end-1 位置上的元素，此时将这个 nums 放入到
// ans 结果集中即可。
// 当递归调用结束时，需要将 nums[begin] 恢复到循环开始的位置，当下一轮
// 迭代是能够与 [begin, end) 中的下一个元素交换。