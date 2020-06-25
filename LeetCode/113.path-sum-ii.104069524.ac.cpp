/*
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (34.88%)
 * Total Accepted:    149.9K
 * Total Submissions: 429.7K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
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
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 * 
 * 
 * 
 * return
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
 * 
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
   void fun(TreeNode* t,int sum,vector<int> tmp,vector<vector<int>> &ans) {
        
        if (t->left == nullptr && t->right == nullptr) {
            tmp.push_back(t->val);
            int res = accumulate(tmp.begin(),tmp.end(),0);
            
            if (res == sum)  
                ans.push_back(tmp);
                
            return ;

        } 
        else {
            tmp.push_back(t->val);
            if(t->left != nullptr)
                fun(t->left,sum,tmp,ans);
            if (t->right != nullptr)
                 fun(t->right,sum,tmp,ans);
        }
        
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
          vector<vector<int>> ans;
          if (root == nullptr)
                return ans;
          vector<int> tmp;
          fun(root,sum,tmp,ans);
          return ans;
    }
};
