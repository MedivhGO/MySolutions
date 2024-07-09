class Solution {
public:
    int maxPathSum(TreeNode* root) {
        curPathSum(root);
        return max_sum;
    }

    int curPathSum(TreeNode* cur) {
        if (!cur) {
            return 0;
        }
        int left_sum = curPathSum(cur->left);
        int right_sum = curPathSum(cur->right);
        left_sum = left_sum < 0 ? 0 : left_sum;
        right_sum = right_sum < 0 ? 0 : right_sum;
        int path_sum = left_sum + right_sum + cur->val;
        max_sum = max(max_sum, path_sum);
        return cur->val + max(left_sum, right_sum);
    }

private:
    int max_sum = INT_MIN;
};

// 时间复杂度 O(n)
// 空间复杂度 O(1)

// curPathSum(TreeNode* cur) 定义函数，求以当前节点为起点的最大路径和
// 1 空节点的最大路径和为 0
// 2 以左子树节点为起点的最大路径和为 如果值是负数，最大路径和为 0，否则为 curPathSum 返回的结果
// 3 以右子树节点为起点的最大路径和为 如果值是负数，最大路径和为 0，否则为 curPathSum 返回的结果
// 经过当前节点的最大路径和为 当前节点的值 + 1 + 2
// 函数返回以当前节点为起点的最大路径和为 点前节点的值 + max(1,2)