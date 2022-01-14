class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        ans = strs[0]
        for i in range(1, len(strs)):
            if ans is None:
                return ""
            ans = self.GetCommStr(ans, strs[i])
        return ans
    def GetCommStr(self, str1: str, str2: str) -> str:
        ans = ''
        i = 0
        while i < len(str1) and i < len(str2):
            if str1[i] == str2[i]:
                ans += str1[i]
            else:
                break
            i += 1
        return ans

# 模拟

# 时间复杂度 O(n^2)
# 空间复杂度 O(1)