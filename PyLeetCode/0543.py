class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.ans = 0
        self.diameterOfBinaryTreeHelper(root, self.ans)
        return self.ans

    def diameterOfBinaryTreeHelper(self, root: TreeNode, ans: list) -> int:
        if root == None:
            return 0
        left_max = self.diameterOfBinaryTreeHelper(root.left, self.ans)
        right_max = self.diameterOfBinaryTreeHelper(root.right, self.ans)
        self.ans = max(left_max + right_max, self.ans)
        return 1 + max(left_max, right_max)


# 明确最大直径的定义, 对于每个节点来说就是它的左子树高度 + 右子树高度.
# 所以可以在求树高度的递归过程中,记录每个节点的最大直径, 最后返回即可.

# 时间复杂度 O(n)
# 空间复杂度 O(lgn)