#https://www.codewars.com/kata/54e6533c92449cc251001667
def unique_in_order(iterable):
    ans = []
    for x in iterable:
        if len(ans) == 0 or x != ans[-1]:
            ans.append(x)
    return ans
