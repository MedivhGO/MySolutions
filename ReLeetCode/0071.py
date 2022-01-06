class Solution:
    def simplifyPath(self, path: str) -> str:
        path_split = path.split('/')
        stk = []
        ans = "/"
        for x in path_split:
            if x == '.' or x == '':
                continue
            elif x == "..":
                if len(stk) != 0:
                    stk.pop()
            else:
                stk.append(x)
        ans +=  '/'.join(stk)
        return ans

# 模拟

# 时间复杂度 O(n)
# 空间复杂度 O(n)