class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root is None:
            return root

        if (root.val - p.val) * (root.val - q.val) <= 0:
            return root

        left_node = self.lowestCommonAncestor(root.left, p, q)
        if left_node is not None:
            return left_node

        right_node = self.lowestCommonAncestor(root.right, p, q)
        if right_node is not None:
            return right_node

        return None


# 时间复杂度 O(n)
# 空间复杂度 O(lgn) 二叉树的深度

