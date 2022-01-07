#https://www.codewars.com/kata/545cedaa9943f7fe7b000048
import string

def is_pangram(s):
    lst = [x.lower() for x in s if x.isalpha()]
    alphatable =  set(lst)
    if len(alphatable) == 26:
        return True
    else:
        return False