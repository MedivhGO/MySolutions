class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n);
        return nums;
    }

    void merge(vector<int>&  nums, int begin, int mid, int end) {
        vector<int> tmp(end - begin);
        int i = begin;
        int j = mid;
        int k = 0;
        while (i < mid && j < end) {
            if (nums[i] < nums[j]) {
                tmp[k++] = nums[i++];
            } else {
                tmp[k++] = nums[j++];
            }
        }
        while (i < mid) {
            tmp[k++] = nums[i++];
        }
        while (j < end) {
            tmp[k++] = nums[j++];
        }
        for (int i = 0; i < k; ++i) {
            nums[begin+i] = tmp[i];
        }
    }

    void mergeSort(vector<int>& nums, int begin, int end) {
        if (end - begin <= 1) {
            return;
        }
        int mid = (begin + end) / 2;
        mergeSort(nums, begin, mid);
        mergeSort(nums, mid, end);
        merge(nums, begin, mid, end);
    }
};

// 时间复杂度 O(nlog)
// 空间复杂度 O(n)

// 定义归并排序的接口，因为要进行对半划分，所以接口上使用
// [begin, end)，当 end - begin <= 1 时说明有 0 个或 1 个元素，结束排序
// 否则，求出中间元素 mid = (begin + end) / 2
// 对 [begin, mid) 中的元素进行归并排序
// 对 [mid, end) 中的元素进行归并排序
// 将 [begin, mid) [mid, end) 这两个区间中的元素进行合并
// 使用 合并两个有序数组 中的算法实现，不同的是这个是在一个数组中进行操作
// 使用 i，j 下标分别标识同一数组中的两个有序部分的开始元素