/*
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (40.17%)
 * Total Accepted:    140.2K
 * Total Submissions: 349K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * 
 * For example, given the following binary tree:
 * 
 * 
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * 
 * 
 * All root-to-leaf paths are:
 * ["1->2->5", "1->3"]
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
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
    void binaryTreePaths(vector<string>& result,TreeNode* root,string t) {
        if(!root->left && !root->right) {
            result.push_back(t);
            return;
        }
        if(root->left)  binaryTreePaths(result,root->left,t+"->"+to_string(root->left->val));
        if(root->right) binaryTreePaths(result,root->right,t+"->"+to_string(root->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(!root)  return result;
        binaryTreePaths(result,root,to_string(root->val));
        
        return result;
        
    }
};
