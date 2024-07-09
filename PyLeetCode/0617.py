class Solution:
    def mergeTrees(self, root1: TreeNode, root2: TreeNode) -> TreeNode:
        if root1 is None and root2 is None:
            return None
        if root1 is None:
            return root2
        if root2 is None:
            return root1

        newroot = TreeNode(root1.val + root2.val)
        newroot.left = self.mergeTrees(root1.left, root2.left)
        newroot.right = self.mergeTrees(root1.right, root2.right)
        return newroot

# 如果两棵树的对应节点不为空, 那么就构造一个新的node, 并存放两个val和的值.
# 如果其中一个节点为空, 另一个节点不为空, 就返回那个不空的节点.
# 如果两个节点都为空, 就返回空.
# 递归处理左右子树.

# 时间复杂度 O(min(m, n))
# 空间复杂度 O(min(m, n))