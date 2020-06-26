#https://www.hackerrank.com/challenges/ip-address-validation/problem

# Enter your code here. Read input from STDIN. Print output to STDOUT
import re
N=int(input())
#ipv4='\b(([1-9][0-9]?|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\.){3}'
ipv6=r'^([a-f0-9]{0,4}:[a-f0-9]{0,4}:[a-f0-9]{0,4}:[a-f0-9]{0,4}:[a-f0-9]{0,4}:[a-f0-9]{0,4}:[a-f0-9]{0,4}:[a-f0-9]{0,4})$'
ipv4=r'^(([0-9]|[0-9]{2}|1[0-9]{2}|2[0-4][0-9]|25[0-5])\.){3}([0-9]|[0-9]{2}|1[0-9]{2}|2[0-4][0-9]|25[0-5])$'

for _ in range(N):
    line=input()
    res=re.search(ipv4,line)
    resipv6=re.search(ipv6,line)
    if resipv6:
        print("IPv6")
    elif res:
        print("IPv4")
    else:
        print("Neither")





