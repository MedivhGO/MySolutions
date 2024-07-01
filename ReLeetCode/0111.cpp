class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        if (root->left == nullptr) {
            return minDepth(root->right) + 1;
        }
        if (root->right == nullptr) {
            return minDepth(root->left) + 1;
        }
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

// 时间复杂度 O(h) h 为树的高度
// 空间复杂度 O(h)

// 因为是根节点到最近叶子节点的最短路径上的节点数量。
// 所以当根节点左右子树有一个空的时候，其最小深度就是不为空的那个子树的最小深度 + 1
// 当都不为空的时候，就是左右子树的最小深度中的最小值+1