class Solution:
    def isSameHelper(self, tree1: TreeNode, tree2: TreeNode) -> bool:
        if tree1 == None and tree2 == None:
            return True
        if tree1 == None and tree2 != None:
            return False
        if tree1 != None and tree2 == None:
            return False
        if tree1.val != tree2.val:
            return False
        if self.isSameHelper(tree1.left, tree2.right) and self.isSameHelper(tree1.right, tree2.left):
            return True
        return False

    def isSymmetric(self, root: TreeNode) -> bool:
        return self.isSameHelper(root.left, root.right)

# 修改比较两个树是否相同的函数, tree1的左子树和tree2的右子树相同且tree1的右子树和tree2的左子树相同.
# tree1.val == tree2.val那么对称的
# 否则就是不对称的.

# 时间复杂度 O(n)
# 空间复杂度 O(n)

