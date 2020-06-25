/*
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (39.77%)
 * Total Accepted:    218.5K
 * Total Submissions: 549.6K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3]  is not:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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
    bool isSymmetricTree(TreeNode* t1,TreeNode* t2) {
        
        if (t1 == nullptr && t2 == nullptr)
            return true;
        if (!(t1 && t2))
            return false;
        
        if (t1->val == t2->val)
            return isSymmetricTree(t1->left,t2->right) && isSymmetricTree(t1->right,t2->left);
        else
            return false;
       
        
    }
    bool isSymmetric(TreeNode* root) {
        
        if (root == nullptr)
            return true;
        return isSymmetricTree(root->left,root->right);
    }
};
