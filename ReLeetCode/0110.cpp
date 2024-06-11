class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int ret = helper(root);
        return ret == -1 ? false : true;
    }

    int helper(TreeNode* cur) {
        if (cur == nullptr) {
            return 0;
        }
        int left_cur = helper(cur->left);
        if (left_cur == -1) {
            return -1;
        }
        int right_cur = helper(cur->right);
        if (right_cur == -1) {
            return -1;
        }
        return abs(left_cur - right_cur) <= 1 ? 1 + max(left_cur, right_cur) : -1;
    }
};

// 时间复杂度 O(n)
// 空间复杂度 O(n)

// 将求树高的函数增加一个返回值类型，当判断出
// 左右子树不平衡时，不再返回当前节点的树高，而是返回 -1
// 在递归调用的过程中发现返回的是一个 -1 ，说明存在一个左子树已经
// 不平衡了，直接不用在判断其右子树情况了。