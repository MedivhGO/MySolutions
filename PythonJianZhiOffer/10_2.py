class Solution:
    def numWays(self, n: int) -> int:
        if n == 0:
            return 1
        if n == 1:
            return 1
        if n == 2:
            return 2
        
        pprev = 1
        prev = 2
        ans = 0
        for i in range(3, n + 1):
            ans = prev + pprev
            pprev = prev
            prev = ans
            
        return ans%1000000007