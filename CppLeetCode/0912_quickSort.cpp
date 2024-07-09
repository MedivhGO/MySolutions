class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        quickSort(nums, 0, n);
        return nums;
    }
    void quickSort(vector<int>& nums, int begin, int end) {
        if (end-begin < 1) {
            return;
        }
        int pos = partition(nums, begin, end);
        quickSort(nums, begin, pos);
        quickSort(nums, pos+1, end);
    }
    int partition(vector<int>& nums, int begin, int end) {
        int left = begin;
        int right = end-1;
        int rand_idx = rand() % (end - begin) + begin;
        int pivot = nums[rand_idx];
        swap(nums[begin], nums[rand_idx]);
        while (left < right) {
            while (left < right && nums[right] >= pivot) {
                --right;
            }
            nums[left] = nums[right];
            while(left < right && nums[left] < pivot) {
                ++left;
            }
            nums[right] = nums[left];
        }
        nums[left] = pivot;
        return left;
    }
};

// 时间复杂度 O(nlgn)
// 空间复杂度 O(h) h 为快速排序递归调用的层数
// 最坏的情况下 O(n)，最优情况下 O(lgn)

// 随机选择一个下标元素作为 pivot，将这个元素和 left 进行交换
// 这样最左边的元素就是 pivot 元素
// 这个算法是要给这个 pivot 确定在数组中的最终位置
// 算法中有两个循环不变量，需要在迭代中维持其属性
// 维护比 pivot 小的数组，由 left 标识其起始位置
// 维护比 pivot 大于或者等于的数组，由 right 标识其结束位置
// 最后当 left 和 right 相遇的位置，就是 pivot 的最终位置
// 返回 left，在一次 partition 后，我们就确定了一个元素的最终位置
// 所以只需要对 [begin, parition) 和 [partion+1，end) 在进行 quickSort
// 就完成了排序