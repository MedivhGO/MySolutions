class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 1;
        }
        for (int i = 0; i < nums.size(); ++i) {
            while(nums[i] > 0 && nums[i] < n && nums[i] != nums[nums[i]]) {
                swap(nums[i], nums[nums[i]]);
            }
        }
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != i) {
                return i;
            }
        }
        return nums[0] == n ? n + 1 : n;
    }
};

// 时间复杂度 O(n)
// 空间复杂度 O(1)