#https://www.codewars.com/kata/55908aad6620c066bc00002a
def xo(s):
    xlst = [x for x in s if x.lower() == 'x']
    olst = [x for x in s if x.lower() == 'o']

    return len(xlst) == len(olst)