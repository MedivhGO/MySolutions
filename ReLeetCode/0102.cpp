class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int cur_size = q.size();
            vector<int> cur_level;
            while (cur_size--) {
                TreeNode* cur_node = q.front();
                q.pop();
                cur_level.push_back(cur_node->val);
                if (cur_node->left) {
                q.push(cur_node->left);
                }
                if (cur_node->right) {
                    q.push(cur_node->right);
                }
            }
            ans.push_back(cur_level);
        }
        return ans;
    }
};

// 时间复杂度 O(n)
// 空间复杂度 O(n)

// 在每一轮迭代开始时，队列中保存当前层中所有节点
// 因此在循环开始时，首先确定当前队列中的节点个数
// 通过循环逐个遍历这些节点，每次遍历节点，将其，左右
// 孩子逐个入队，为下一轮迭代增加下一层元素。