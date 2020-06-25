/*
 * [530] Minimum Absolute Difference in BST
 *
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (47.19%)
 * Total Accepted:    29.6K
 * Total Submissions: 62.7K
 * Testcase Example:  '[1,null,3,2]'
 *
 * Given a binary search tree with non-negative values, find the minimum
 * absolute difference between values of any two nodes.
 * 
 * 
 * Example:
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    3
 * ⁠   /
 * ⁠  2
 * 
 * Output:
 * 1
 * 
 * Explanation:
 * The minimum absolute difference is 1, which is the difference between 2 and
 * 1 (or between 2 and 3).
 * 
 * 
 * 
 * 
 * Note:
 * There are at least two nodes in this BST.
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
    vector<int> all;
    void inOrder(TreeNode* root) {
        if ( root != nullptr ) {
            inOrder(root->left);
            all.push_back(root->val);
            inOrder(root->right);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        
        int ans=INT_MAX;
        
        inOrder(root);
        for (int i = 0 ; i < all.size()-1 ;i++) {
            if (ans > (all[i+1]-all[i]))
                 ans = all[i+1]-all[i];
        }
        return ans;
    }
};
