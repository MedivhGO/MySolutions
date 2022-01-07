#https://www.codewars.com/kata/5583090cbe83f4fd8c000051
def digitize(n):
    newstr = str(n)
    newstr = newstr[::-1]
    return [int(x) for x in newstr]