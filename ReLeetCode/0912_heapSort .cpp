class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int len = nums.size();
        for (int i = len-1; i >= 0; --i) {
            apply_def(nums, i, len);
        }
        for (int i = len-1; i >= 0; --i) {
            swap(nums[i], nums[0]);
            apply_def(nums, 0, i);
        }
        return nums;
    }

    void apply_def(vector<int>& nums, int begin, int end) {
        int left_child = 2*begin+1;
        int right_child = 2*begin+2;
        if (left_child >= end) {
            return;
        }
        int max_index = left_child;
        if (right_child < end && nums[left_child] < nums[right_child]) {
            max_index = right_child;
        }
        if (nums[begin] >= nums[max_index]) {
            return;
        }
        swap(nums[begin], nums[max_index]);
        apply_def(nums, max_index, end);
    }
};

// 时间复杂度 O(nlgn)
// 空间复杂度 O(1)

// 根据二叉堆的定义，堆中每一个节点的孩子节点都小于或者大于该节点。
// 因此需要定义一个 apply_def (nums, begin, end) 函数，用于对 begin 节点及其子节点应用堆的定义。
// 我们首先需要将 nums 上的每个节点都应用该函数，记得需要从下往上进行调整，
// 也就是从数组 len-1 处的下标向左开始调整，由于在下标为 (len - 1) / 2 节点后的
// 都是叶节点，所以可以优化 5 行处的循环条件，由于 apply_def 函数在开始处会判断当前 begin
// 节点是否拥有孩子，所以为了方便，就直接从 len-1 处开始。
// 当建好堆后，需要将 nums[0] 处的堆顶元素与 nums[i] 处，也就是数组最后一个元素交换。
// 这时 nums[0] 处的元素就不符合堆的定义了，就需要进行调整，也就是调用 apply_def 方法。