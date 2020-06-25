/*
 * [110] Balanced Binary Tree
 *
 * https://leetcode.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (38.04%)
 * Total Accepted:    205.9K
 * Total Submissions: 541.2K
 * Testcase Example:  '[]'
 *
 * Given a binary tree, determine if it is height-balanced.
 * 
 * 
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
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
    bool ans=true;
    bool isBalanced(TreeNode* root) {
        
        getDepth(root);
        return ans;
        
    }
    int getDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int lefth = getDepth(root->left);
        int righth = getDepth(root->right);
        int t = abs(lefth-righth);
        if (t<=1)
            ans&=true;
        else
            ans&=false;
        return 1+max(lefth,righth);
    }
};
