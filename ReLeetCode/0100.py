class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if p is None and q is None:
            return True
        elif p is None and q is not None:
            return False
        elif p is not None and q is None:
            return False
        elif p.val != q.val:
            return False
        else:
            return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)

# 时间复杂度 O(min(n, m))
# 空间复杂度 O(min(n, m))