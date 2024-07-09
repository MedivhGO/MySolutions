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

// 使用循环为 nums 中 [1,n-1] 的元素确定在数组中的对应位置
// 如果，在遍历完所有元素后，[1, n-1] 下标的元素都是对应的值
// 就需要判断 nums[0] 位置元素是不是 n
// 因为所有可能的结果 [1, n+1]，[1, n-1]的元素都已经被放在数组的合适位置了，
// 那么如果 nums[0] == n 说明 n 元素也有合适的位置了，那么结果只能是 n+1，否则就是 n

// 时间复杂度 O(n)
// 空间复杂度 O(1)