class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        if root is None:
            return ans
        stk = []
        cur_node = root
        while cur_node is not None or len(stk) != 0: # cur_node is None说明当前这个树及其子树都遍历完了.
            while cur_node is not None:
                stk.append(cur_node)
                cur_node = cur_node.left
            cur_node = stk.pop()
            ans.append(cur_node.val)
            cur_node = cur_node.right
        return ans

# 迭代 模拟遍历二叉树过程.
# 从根节点出发, 沿着左子树一直走到叶节点, 经过的节点依次入栈. (1)
# 叶节点后, 栈顶元素出栈cur_node, 把元素放到结果数组中, 让cur_node指向cur_node右子树. (2)
# 对当前cur_node按照(1)过程循环处理. (3)

# 时间复杂度 O(n)
# 空间复杂度 O(n)


class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        if root is None:
            return ans
        ans.extend(self.inorderTraversal(root.left))
        ans.append(root.val)
        ans.extend(self.inorderTraversal(root.right))
        return ans

# 递归

# 时间复杂度 O(n)
# 空间复杂度 O(lgn)