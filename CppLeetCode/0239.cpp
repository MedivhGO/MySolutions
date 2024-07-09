class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; ++i) {
            q.emplace(nums[i], i);
        }
        vector<int> ans{q.top().first};
        for (int i = k; i < n; ++i) {
            q.emplace(nums[i], i);
            while(q.top().second  <= i - k) {
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};

// 时间复杂度 O(nlg) 空间复杂度 O(n)
// 使用优先队列，也就是一个堆来维护当前窗口的最大值，为了方便判断 是否要当前的堆顶元素是否要移除 堆中存放的是 <nums[i], i> 当堆顶元素的下标不在窗口中了，就将其移除，一直找到一个在窗口范围内的堆顶、

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if (nums.empty()) {
            return ans;
        }
        deque<int> q; // 保存下标
        for (int i = 0; i < nums.size(); ++i) {
            // 入队，需要维持单调队列的性质
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            // 出队
            if (i - q.front() + 1 > k) {
                q.pop_front();
            }
            // 记录结果
            if (i + 1 >= k) {
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};

// 时间复杂度 O(n) 空间复杂度 O(k)
// 使用单调队列，将元素入队时要保证比它小的元素都从队尾出队后再进入，当队头元素已经超过窗口所在位置时，要出队 i - q.front() + 1 是标识以这个队头元素为起点到 i 的
// 数组范围元素个数，当其大于 k 时说明该出队了，当 i + 1 >= k 时，明说窗口已经被填满，需要记录当前窗口中的最大元素了。