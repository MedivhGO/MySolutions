#https://www.codewars.com/kata/54521e9ec8e60bc4de000d6c
def maxSequence(arr):
    # ...
    alen = len(arr)
    if alen == 0:
        return 0
    negative = [x for x in arr if x < 0]
    lennegative = len(negative)
    if lennegative == alen:
        return 0
    maxsum = -1000
    cursum = 0
    for i in range(alen):
        cursum+=arr[i]
        if cursum>maxsum:
            maxsum = cursum
        if cursum <= 0 :
            cursum = 0
    return maxsum