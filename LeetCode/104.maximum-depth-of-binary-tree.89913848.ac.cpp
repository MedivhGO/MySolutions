/*
 * [104] Maximum Depth of Binary Tree
 *
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (53.67%)
 * Total Accepted:    292.8K
 * Total Submissions: 545.6K
 * Testcase Example:  '[]'
 *
 * Given a binary tree, find its maximum depth.
 * 
 * The maximum depth is the number of nodes along the longest path from the
 * root node down to the farthest leaf node.
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
    int maxDepth(TreeNode* root) {
        int maxD = 0;
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return 1;
        maxD = max(maxDepth(root->left),maxDepth(root->right))+1;
        
        return maxD;
    }
};
