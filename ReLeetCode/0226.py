class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if root == None or (root.left == None and root.right == None):
            return root
        new_root_left = self.invertTree(root.right)
        new_root_right = self.invertTree(root.left)
        root.left = new_root_left
        root.right = new_root_right
        return root

# 翻转左子树得到new_left, 翻转右子树得到new_right
# 将root.left = new_left,将root.right = new_right

# 时间复杂度 O(n)
# 空间复杂度 O(n)

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if root == None:
            return root
        
        queue = deque([root]) # 使用list初始化一个双端队列

        while len(queue) != 0 :
            cur = queue.popleft()
            if cur.left or cur.right: # 左右孩子有一个不为空, 需要交换
                cur.left, cur.right = cur.right, cur.left # 交换后 继续按照层次遍历处理
                if cur.left and cur.right:
                    queue.append(cur.left)
                    queue.append(cur.right)
                elif cur.left != None:
                    queue.append(cur.left)
                elif cur.right != None:
                    queue.append(cur.right)
        
        return root


# 使用迭代, 类似层次遍历

# 时间复杂度 O(n)
# 空间复杂度 O(1)