#https://www.codewars.com/kata/5412509bd436bd33920011bc

def maskify(cc):

    strlen = len(cc)
    if strlen <= 4:
        return cc
    ans = '#'*(strlen-4)
    ans += cc[-4:]
    return ans