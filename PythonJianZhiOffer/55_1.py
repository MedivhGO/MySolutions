class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        ans = 0
        queue = collections.deque()
        if root is not None:
            queue.append(root)
        while len(queue) != 0:
            size = len(queue)
            ans += 1
            while size != 0:
                next_level = queue.popleft()
                if next_level.left is not None:
                    queue.append(next_level.left)
                if next_level.right is not None:
                    queue.append(next_level.right)
                size -= 1
        return ans

# BFS
# 使用collections.deque定义双端队列.
# 使用popleft()方法从队头出队, appendleft()方法对头入队.
# append()方法队尾入队, pop()方法从队尾出队.

# 时间复杂度 O(n)
# 空间复杂度 O(n) 最差情况下, (当树平衡时), 队列queue同时存储N/2个节点.

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        return 0 if root is None else 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))

# 后序遍历

# 时间复杂度 O(n)
# 空间复杂度 O(n) 最差情况下递归调用深度是一个单边树.
