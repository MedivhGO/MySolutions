/*
 * [421] Maximum XOR of Two Numbers in an Array
 *
 * https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/
 *
 * algorithms
 * Medium (47.24%)
 * Total Accepted:    19.1K
 * Total Submissions: 40.5K
 * Testcase Example:  '[3,10,5,25,2,8]'
 *
 * Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai <
 * 231.
 * 
 * Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
 * 
 * Could you do this in O(n) runtime?
 * 
 * Example:
 * 
 * Input: [3, 10, 5, 25, 2, 8]
 * 
 * Output: 28
 * 
 * Explanation: The maximum result is 5 ^ 25 = 28.
 * 
 * 
 */
class Solution {
    public:
        class TreeNode { //定义字典树
            public:
                TreeNode* next[2];
                TreeNode() {next[0] = NULL;next[1] = NULL;}
        };

        TreeNode* buildTree(vector<int> &nums) { // 根据已有的元素的二进制位构建相应元素的字典树序列
                TreeNode* root = new TreeNode(),*cur;
                int n = nums.size();
                for (int i=0;i<n;i++) {
                    int num = nums[i];
                    cur = root; //针对每一个元素都需要从根节点开始构建
                    for (int j=31;j>=0;j--) { 
                        int index = ((num>>j)&1); // 从左到右建树 0 或 1
                        //如果末位为0，根据cur指向的单元的0子树是否为空，如果为空就占据该子树节点，如果不为空就让cur指向该子树节点。
                        if (cur->next[index] == NULL)
                            cur->next[index] = new TreeNode();
                        cur = cur->next[index];
                    }
                }
                //完成树的构建
                return root;
        }

        int helper(TreeNode* cur,int num) { //确定该节点的在树中的最大异或值。
            int res = 0;
            for (int i=31;i>=0;i--) {
                int index = ((num>>i) & 1) ? 0 : 1;
                if (cur->next[index]) { //如果与当前元素的对应位存在相反的值
                    res<<=1;
                    res|=1; //将末位置1
                    
                    cur = cur->next[index];
                } else {
                    res<<=1;
                    res|=0; //将末位置0
                   
                    cur = cur->next[index ? 0 : 1];
                }
            }
            return res;
        }

        int findMaximumXOR(vector<int>& nums) {
            int res =0;
            TreeNode* root = buildTree(nums);

            for (auto i : nums) {
                res = max(res,helper(root,i));
            }

            return res;
        }
        

};
