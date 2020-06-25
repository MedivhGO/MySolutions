/*
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (43.20%)
 * Total Accepted:    154.5K
 * Total Submissions: 357.7K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * Given the sorted array: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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
    //每次都找区间中间的节点进行插入，最后就能得到一个平衡的二叉排序树
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        if(right+1 == 0)
            return nullptr;
        int mid = left + (right-left)/2;
        TreeNode* ans = new TreeNode(nums[mid]);
        vector<int> tl(nums.begin(),nums.begin()+mid);
        vector<int> tr(nums.begin()+mid+1,nums.end());
        ans->left = sortedArrayToBST(tl);
        ans->right = sortedArrayToBST(tr);
        
        return ans;
        
    }
};
