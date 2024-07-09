class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res;
        int len = nums.size();
        int sum = len * (len + 1) / 2;
        int cur_sum = 0;
        cur_sum = accumulate(nums.begin(), nums.end(), 0);
        int diff  = sum - cur_sum;
        int duplicate = -1;
        for (int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) {
                duplicate = index+1;
                break;
            }
            nums[index] = -nums[index];
        }
        res.push_back(duplicate);
        res.push_back(duplicate + diff);
        return res;
    }
};

// 时间复杂度 O(n)
// 空间复杂度 O(1)

// 对于元素为 1-n 这种的 n 个元素的数组，可以通过将数组元素作为下标，来确认是否有重复元素。
// 每次访问以该 元素数值-1 为下标的元素并取反，遍历过程中如果发现这种元素已经为负，那么这个值就是
// 重复的。其核心逻辑代码为 11~17 行。