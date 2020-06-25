/*
 * [508] Most Frequent Subtree Sum
 *
 * https://leetcode.com/problems/most-frequent-subtree-sum/description/
 *
 * algorithms
 * Medium (52.32%)
 * Total Accepted:    25.1K
 * Total Submissions: 48.1K
 * Testcase Example:  '[5,2,-3]'
 *
 * 
 * Given the root of a tree, you are asked to find the most frequent subtree
 * sum. The subtree sum of a node is defined as the sum of all the node values
 * formed by the subtree rooted at that node (including the node itself). So
 * what is the most frequent subtree sum value? If there is a tie, return all
 * the values with the highest frequency in any order.
 * 
 * 
 * Examples 1
 * Input:
 * 
 * ⁠ 5
 * ⁠/  \
 * 2   -3
 * 
 * return [2, -3, 4], since all the values happen only once, return all of them
 * in any order.
 * 
 * 
 * Examples 2
 * Input:
 * 
 * ⁠ 5
 * ⁠/  \
 * 2   -5
 * 
 * return [2], since 2 happens twice, however -5 only occur once.
 * 
 * 
 * Note:
 * You may assume the sum of values in any subtree is in the range of 32-bit
 * signed integer.
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
    int getSum(TreeNode* root) {
        int sum = 0;
        if (root) {
            sum+= root->val;
            sum+=getSum(root->left);
            sum+=getSum(root->right);
        }
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        stack<TreeNode*> stk;
        stk.push(root);
        unordered_map<int,size_t> m;
        int maxtime = 0;
        while (!stk.empty()) {
            TreeNode* p = stk.top();
            stk.pop();
            int t = getSum(p);
            m[t]++;
            
            if (m[t] > maxtime) 
                maxtime = m[t];
            if (p->right!=nullptr) stk.push(p->right);
            if (p->left != nullptr) stk.push(p->left);
        }
        for(auto x : m) {
            if (x.second == maxtime)
                 ans.push_back(x.first);
        }
        return ans;
    }
};
