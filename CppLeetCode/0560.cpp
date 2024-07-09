class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int preSum = 0;
        int ans = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for (auto x : nums) {
            preSum += x;
            if (m.find(preSum-k) != m.end()) {
                ans += m[preSum-k];
            }
            m[preSum]++;
        }
        return ans;
    }
};

// 时间复杂度 O(n)
// 空间复杂度 O(n)

// 前缀和 + 哈希表
// 原题转换思路，其实就是求满足 preSum1 - preSum2 = k，的 preSum 个数。
// 与 two sum 问题类似，使用一个 hash 表存储所有 preSum 的值
// 找 preSum1 - preSum2 = k (preSum1 > preSum2)的个数
// 可等价的转换为当遍历到 preSum1 时 preSum1 - k 也就是 preSum2 的个数