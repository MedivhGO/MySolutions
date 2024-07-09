class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }
        stack<TreeNode*> stk;
        while (root != nullptr || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            auto mid = stk.top();
            stk.pop();
            ans.push_back(mid->val);
            root = mid->right;
        }
        return ans;
    }
};

// 时间复杂度 O(n)
// 空间复杂度 O(n)

// 使用 root 记录当前正在指向的节点，使用 stk 存储待遍历的节点