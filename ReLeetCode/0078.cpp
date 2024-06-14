class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(nums, ans, vector<int>(), 0, nums.size());
        return ans;
    }

    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int> tmp, int begin, int end) {
        if (begin >= end) {
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(nums[begin]);
        helper(nums, ans, tmp, begin+1, end);
        tmp.pop_back();
        helper(nums, ans, tmp, begin+1, end);  
    }
};

// 时间复杂度 O(n*2^n)
// 空间复杂度 O(n)