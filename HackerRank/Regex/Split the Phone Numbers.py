#https://www.hackerrank.com/challenges/split-number/problem
# Enter your code here. Read input from STDIN. Print output to STDOUT
import re
N=int(input())
for i in range(N):
    line=input()
    rep=r'^(\d{1,3})[-\s](\d{1,3})[-\s](\d{4,10})$'
    res=re.search(rep,line)
   # print("CountryCode=%s,LocalAreaCode=%s,Number=%s" % res.groups())
    print("CountryCode=%s,LocalAreaCode=%s,Number=%s" % (res.group(1),res.group(2),res.group(3)))







