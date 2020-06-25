/*
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (41.11%)
 * Total Accepted:    162.4K
 * Total Submissions: 395.1K
 * Testcase Example:  '[]'
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
 * 
 * 
 * For example:
 * Given binary tree {1,#,2,3},
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 
 * 
 * return [3,2,1].
 * 
 * 
 * Note: Recursive solution is trivial, could you do it iteratively?
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) 
            return ans;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* t = s.top();
            ans.push_back(t->val);
            s.pop();
            if (t->left!=nullptr)
                s.push(t->left);
            if (t->right!=nullptr) 
                s.push(t->right);
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};
