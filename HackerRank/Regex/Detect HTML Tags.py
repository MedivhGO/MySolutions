#https://www.hackerrank.com/challenges/detect-html-tags/problem
# Enter your code here. Read input from STDIN. Print output to STDOUT
import re
N=int(input())
st=set()
exp=r'<[\s]*(\w+)[^<]*>'
for _ in range(N):
    line=input()
    res=re.findall(exp,line)
    for x in res:
        st.add(x)

ans=sorted(st)
print(";".join(ans))

