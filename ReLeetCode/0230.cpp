class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        assert(root != nullptr);
        stack<TreeNode*> stk;
        while (root != nullptr || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            auto mid = stk.top();
            stk.pop();
            count++;
            if (count == k) {
                return mid->val;
            }
            root = mid->right;
        }
        return -1;
    }
};

// 时间复杂度 O(n)
// 空间复杂度 O(n)

// 使用中序遍历