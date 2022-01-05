class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        return 0 if root == None else 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))

# 递归实现

# 时间复杂度 O(n) 需要遍历所有树中节点
# 空间复杂度 O(lgn) 最深的调用栈为O(lgn)即二叉树的高度