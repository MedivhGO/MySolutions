/*
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (23.89%)
 * Total Accepted:    207.6K
 * Total Submissions: 869.2K
 * Testcase Example:  '[2,1,3]'
 *
 * 
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * 
 * 
 * 
 * Assume a BST is defined as follows:
 * 
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * Example 1:
 * 
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 
 * Binary tree [2,1,3], return true.
 * 
 * 
 * Example 2:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * 
 * Binary tree [1,2,3], return false.
 * 
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
    void inOrder(TreeNode* root) {
        if (root) {
            inOrder(root->left);
            data.push_back(root->val);
            inOrder(root->right);
        }
    }
    bool isValidBST(TreeNode* root) {
       if (root == nullptr) return true;
       inOrder(root);
       if (data.size() == 1) return true;
       int pre =data[0];
       for (int i = 1; i < data.size();i++) {
           if (data[i]<=pre) return false;
           else {
               pre = data[i];
           }
       }
       return true;
    }
private:
    vector<int> data;
};
