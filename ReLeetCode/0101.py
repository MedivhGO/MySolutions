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

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        # 把左右两个孩子当作一个元组, 一起入队
        queue = collections.deque()
        queue.append((root.left, root.right))
        while len(queue) != 0:
            item = queue.popleft()
            left, right = item[0], item[1]
            if not left and not right:
                continue
            if not left or not right:
                return False
            if left.val != right.val:
                return False
            queue.append((left.left, right.right)) # 为了避免每次出队两个元组
            queue.append((left.right, right.left)) # 所以把镜像的一组放到同一个元组里
        return True

# 把根节点的左右孩子作为元组入队, 出队->判断左右孩子的情况, 将左孩子的左孩子和右孩子的右孩子
# 放入到一个元组中入队, 同理处理右孩子.
# 一直出队, 入队处理完所有节点

# 时间复杂度 O(n)
# 空间复杂度 o(n)

