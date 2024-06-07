class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        int n = height.size();
        int pre = -1;
        for (int i = 1; i < n-1; ++i) {
            int max_left = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (height[j] > max_left) {
                    max_left = height[j];
                }
            }
            int max_right = 0;
            for (int j = i + 1; j < n; j++) {
                if (height[j] > max_right) {
                    max_right = height[j];
                }
            }
            int limit = min(max_left, max_right);
            if (limit > height[i]) {
                sum += limit - height[i];
            }
        }
        return sum;
    }
};

// 暴力法
// 时间复杂度 O(n^2)
// 空间复杂度 O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        vector<int> dp1(height.size(), 0);
        vector<int> dp2(height.size(), 0);
        int n = height.size();
        dp1[0] = height[0];
        dp2[n-1] = height[n-1];
        for (int i = 1; i < height.size(); ++i) {
            dp1[i] = max(dp1[i-1], height[i]);
        }
        for (int j = height.size() - 2; j >= 0; j--) {
            dp2[j] = max(dp2[j+1], height[j]);
        }
        for (int i = 1; i < height.size() - 1; ++i) {
            int limit = min(dp1[i], dp2[i]);
            if (limit > height[i]) {
                sum += limit - height[i];
            }
        }
        return sum;
    }
};

// 动态规划
// 时间复杂度 O(n)
// 空间复杂度 O(n)