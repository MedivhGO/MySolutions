class Solution:
    def getTreeHeight(self, root: TreeNode) -> bool:
        return 0 if root == None else 1 + max(self.getTreeHeight(root.left), self.getTreeHeight(root.right))

    def isBalanced(self, root: TreeNode) -> bool:
        if root == None:
            return True

        left_height = self.getTreeHeight(root.left)
        right_height = self.getTreeHeight(root.right)

        if abs(left_height - right_height) > 1:
            return False

        return self.isBalanced(root.left) and self.isBalanced(root.right)

# 使用递归实现, 对每个节点进行子树高度的判断, 如果一个节点不符合就返回False, 否则就遍历他的左右子树.

# 时间复杂度 O(n^2)
# 空间复杂度 O(n)


class Solution:
    def getHeightAndBalance(self, root: TreeNode) -> int:
        if root == None:
            return 0
        
        left_height = self.getHeightAndBalance(root.left)
        if left_height == -1:
            return -1

        right_height = self.getHeightAndBalance(root.right)

        if right_height == -1:
            return -1

        if abs(left_height - right_height) <= 1:
            return 1 + max(left_height, right_height)
        else:
            return -1

    def isBalanced(self, root: TreeNode) -> bool:
        return self.getHeightAndBalance(root) >= 0

# 方法一有很多重复的计算, 比如在求树高的时候会遍历有所节点, 在判断平衡的时候会再次访问这些节点.
# 因此可以进行优化.
# 通过观察发现, 其实在进行树的高度计算的时候就可以, 进行平衡性的计算了.
# 因此把求树高和判断平衡放在一起.

# 重写实现求树高度的函数, 假设不平衡的树的高度为-1, 那么当求高函数返回-1时,树就是不平衡的.
# 1. 求左子树高度, 如果左子树高度为-1, 说明已经有一个子树不平衡了,整个树都是不平衡的,返回-1
# 2. 求右子树高度, 如果右子树高度为-1, 说明已经有一个子树不平衡了,整个树都是不平衡的,返回-1
# 3. 左右子树高度都不为-1, 如果左子树高度与右子树高度差的绝对值<=1, 则返回1 + max(左子树高度, 右子树高度)
# 4. 否则返回 -1

# 时间复杂度 O(n)
# 空间复杂度 O(n)