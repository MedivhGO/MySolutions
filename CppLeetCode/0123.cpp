class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0 || len == 1) {
            return 0;
        }
        int f1 = -prices[0];
        int f2 = 0;
        int f3 = -prices[0];
        int f4 = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int& cur_price = prices[i];
            f1 = max(f1, -cur_price);     // 因为是第一次买入，肯定是当前这个价格的负值
            f2 = max(f2, f1 + cur_price); // 因为是第一次卖出，所以价格是第一次买入的利润+当前的价格
            f3 = max(f3, f2 - cur_price); // 同上
            f4 = max(f4, f3 + cur_price); // 同上
        }
        return f4;
    }
};

// 时间复杂度 O(n)
// 空间复杂度 O(1)