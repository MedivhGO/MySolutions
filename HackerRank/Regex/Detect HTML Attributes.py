#https://www.hackerrank.com/challenges/html-attributes/problem
# Enter your code here. Read input from STDIN. Print output to STDOUT
import re
from collections import defaultdict

N=int(input())
tag_attributes = defaultdict(list)
for i in range(N):
    line=input()
    rep=r'<(\w+)([^>]*)>'
    attrirep=r'(\w+)=[\'\"]'
    res=re.findall(rep,line)
    for everytag in res:
        tag,attr=everytag
        tag_attributes[tag].extend(re.findall(attrirep,attr))

for tag,attr in sorted(tag_attributes.items()):
    attrstr =','.join(sorted(set(attr)))
    print(tag+":"+attrstr)

