class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            auto t = stk.top();
            stk.pop();
            ans.push_back(t->val);
            if (t->right) {
                stk.push(t->right);
            }
            if (t->left) {
                stk.push(t->left);
            }
        }
        return ans;
    }
};

// 时间复杂度 O(n)
// 空间复杂度 O(1)

// 每个节点都是先入栈再出栈，由于是先序遍历
// 所以右孩子比左孩子先入栈