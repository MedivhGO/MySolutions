class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = binarySearch(nums, target);
        if (left == nums.size() || nums[left] != target) {
            return {-1, -1};
        }
        int right = binarySearch(nums, target+1) - 1;
        return {left, right};
    }

    int binarySearch(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};

// 时间复杂度 O(lgn)
// 空间复杂度 O(1)

// binarysearch 知识点
// 1. return left 的值为 target 元素能够插入到的数组位置下标
// 当需要注意对返回值的处理，left 有可能是不存在的 target 返回的无效下标
// 因为 left 取值范围为 [0, len]，所以需要通过 left == len 和 nums[left] == target
// 来决定这个 left 是不是有效的，所以第 5 行是当 target 不存在时的判断条件
// 2. 当寻找结束位置时，可以寻找 target + 1 起始位置 -1 来决定其结束位置
// 因为 nums 是个连续递增整数的数组，如果 target + 1 存在，它一定在紧跟在 target 之后
// 如果 target + 1 不存在，其 left 值也在 target 元素之后。