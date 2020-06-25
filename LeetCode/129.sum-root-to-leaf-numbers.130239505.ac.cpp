/*
 * [129] Sum Root to Leaf Numbers
 *
 * https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
 *
 * algorithms
 * Medium (37.35%)
 * Total Accepted:    126.2K
 * Total Submissions: 337.9K
 * Testcase Example:  '[]'
 *
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path
 * could represent a number.
 * An example is the root-to-leaf path 1->2->3 which represents the number
 * 123.
 * 
 * Find the total sum of all root-to-leaf numbers.
 * 
 * For example,
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * 
 * 
 * 
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 * 
 * 
 * Return the sum = 12 + 13 = 25.
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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        if (root == nullptr)
            return ans;
        TreeNode* cur = root;
        string tmp;
        fun(cur,tmp,ans);
        return ans;
    }
    void fun(TreeNode* cur,string tmp,int &sum) {
        if (cur->left==nullptr && cur->right == nullptr) {
            tmp.append(to_string(cur->val));
            sum+=stoi(tmp);
            tmp.clear();
            return ;
        }
        tmp.append(to_string(cur->val));
        if (cur->left != nullptr)
            fun(cur->left,tmp,sum);
        if (cur->right != nullptr)
            fun(cur->right,tmp,sum);
        return;
    }
};
