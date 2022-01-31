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
# 空间复杂度 O(n) 最坏情况是一个单边树.


class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        cur_ptr = root
        while cur_ptr is not None:
            if (cur_ptr.val - p.val) * (cur_ptr.val - q.val) <= 0:
                return cur_ptr
            elif cur_ptr.val > max(p.val, q.val):
                cur_ptr = cur_ptr.left
            elif cur_ptr.val < min(p.val, q.val):
                cur_ptr = cur_ptr.right
        return None


# 使用迭代的方法
# 如果当前节点在p,q之间就返回
# 如果当前节点大于p,q的值, 说明公共祖先在当前节点的左子树中.
# 如果当前节点小于p,q的值, 说明公共祖先在当前节点的右子树中.

# 时间复杂度 O(n)
# 空间复杂度 O(1)