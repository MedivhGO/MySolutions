class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return max_res;
    }

    int helper(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left_height = helper(root->left);
        int right_height = helper(root->right);
        if (left_height + right_height > max_res) {
            max_res = left_height +right_height;
        }
        return 1 + max(left_height, right_height);
    }
private:
    int max_res = INT_MIN;
};

// 时间复杂度 O(n)
// 空间复杂度 O(h) h 树的高度

// 先求左子树的树高，然后再求右子树的树高，直径为 left_height + right_height
// 同时返回以当前节点为根的树的树高，也就是 1 + max(left_height, right_height)
// 这个算法遍历了树中的每一个节点，保证了求的不仅仅是经过 root 节点的直径。