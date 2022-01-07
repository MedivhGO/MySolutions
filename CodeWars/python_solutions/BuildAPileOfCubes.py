#https://www.codewars.com/kata/5592e3bd57b64d00f3000047
from math import sqrt,floor

def find_nb(m):
    n = int( floor(sqrt(2*sqrt(m))) )
    if (n*(n+1)/2)**2 == m:
        return n
    else:
        return -1