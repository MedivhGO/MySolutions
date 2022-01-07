#https://www.codewars.com/kata/580a4734d6df748060000045
def is_sorted_and_how(arr):
    asc = sorted(arr)
    desc = sorted(arr,reverse=True)
    if asc == arr:
        return "yes, ascending"
    elif desc == arr:
        return "yes, descending"
    else:
        return "no"