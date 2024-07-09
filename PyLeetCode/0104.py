class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        return 0 if root == None else 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))

# 递归实现

# 时间复杂度 O(n) 需要遍历所有树中节点
# 空间复杂度 O(lgn) 最深的调用栈为O(lgn)即二叉树的高度


class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        ans = 0
        queue = collections.deque()
        queue.append(root)
        while len(queue) != 0:
            n = len(queue) # 当前层的节点个数
            while n != 0: # 将所有当前层的节点的孩子节点入队
                cur_node = queue.popleft()
                if cur_node.left is not None:
                    queue.append(cur_node.left)
                if cur_node.right is not None:
                    queue.append(cur_node.right)
                n -= 1
            ans += 1 # 当前层节点全部出队完成, 高度 +1
        return ans

# 使用广度优先

# 时间复杂度 O(n)
# 空间复杂度 O(n)
