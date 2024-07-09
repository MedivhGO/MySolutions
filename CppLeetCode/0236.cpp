class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root == p || root == q) {
            return root;
        }
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if (left != nullptr && right != nullptr) {
            return root;
        }
        return left == nullptr ? right : left;
    }
};

// 时间复杂度 O(n)
// 空间复杂度 O(n)

// 先去找从他的左孩子中寻找 p，q 的最低公共祖先，如果返回不为 nullptr，说明有比当前节点更低的祖先，最低公共祖先就在其左子树中。
// 如果左子树为空，就去他的右子树中寻找最低公共祖先。如果返回不为 nullptr, 说明有比当前节点更低的祖先，最低公共祖先就在其右子树中。
// 如果左右子树都不是 p，q 的最低公共祖先，那么当前节点就是他们的最低公共祖先。