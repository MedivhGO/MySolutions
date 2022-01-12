class Solution:
    def fib(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return 1
        if n == 2:
            return 1
        
        pprev = 1
        prev = 1
        ans = 0
        for i in range(3, n + 1):
            ans = prev + pprev
            pprev = prev
            prev = ans
            
        return ans%1000000007