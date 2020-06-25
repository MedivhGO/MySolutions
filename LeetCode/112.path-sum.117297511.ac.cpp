/*
 * [112] Path Sum
 *
 * https://leetcode.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (34.49%)
 * Total Accepted:    194.8K
 * Total Submissions: 564.8K
 * Testcase Example:  '[]\n1'
 *
 * 
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 * 
 * 
 * For example:
 * Given the below binary tree and sum = 22,
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \      \
 * ⁠       7    2      1
 * 
 * 
 * 
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    bool hasPathSum(TreeNode* root, int sum) {
        bool ans = false;
        if (root == nullptr) return ans;
        Fun(root,0,sum,ans);
        return ans;
    }
    void Fun(TreeNode* root,int currentsum,int sum,bool& ans) {
        currentsum+= root->val;
        bool isLeaf = root->left == nullptr && root->right == nullptr;
        if (currentsum == sum && isLeaf) {
            ans = true;
        }
        if (root->left != nullptr) 
            Fun(root->left,currentsum,sum,ans);
        if (root->right != nullptr)
            Fun(root->right,currentsum,sum,ans);
        currentsum-=root->val;
    }
    
};
