/*
 * [501] Find Mode in Binary Search Tree
 *
 * https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (37.78%)
 * Total Accepted:    27.8K
 * Total Submissions: 73.6K
 * Testcase Example:  '[1,null,2,2]'
 *
 * Given a binary search tree (BST) with duplicates, find all the mode(s) (the
 * most frequently occurred element) in the given BST.
 * 
 * 
 * Assume a BST is defined as follows:
 * 
 * The left subtree of a node contains only nodes with keys less than or equal
 * to the node's key.
 * The right subtree of a node contains only nodes with keys greater than or
 * equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * 
 * For example:
 * Given BST [1,null,2,2],
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 * 
 * 
 * 
 * return [2].
 * 
 * 
 * Note:
 * If a tree has more than one mode, you can return them in any order.
 * 
 * 
 * Follow up:
 * Could you do that without using any extra space? (Assume that the implicit
 * stack space incurred due to recursion does not count).
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
    void fun(TreeNode* root) {
        if (root) {
            m[root->val]++;
            fun(root->left);
            fun(root->right);
        }
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        fun(root);
        int t = 0;
        for (auto p : m) {
            
            if (p.second > t) {
                ans.clear();
                t = p.second;
                ans.push_back(p.first);
            }
            
            else if (p.second == t) {
                ans.push_back(p.first);
            }
        }
        return ans;
    }
private:
    unordered_map<int,size_t> m;
};
