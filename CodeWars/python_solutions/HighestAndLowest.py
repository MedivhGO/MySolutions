#https://www.codewars.com/kata/554b4ac871d6813a03000035
def high_and_low(numbers):
    # ...
    lst = numbers.split()
    valuelst = [int(x) for x in lst]
    maxvalue = max(valuelst)
    minvalue = min(valuelst)
    strlst = [str(maxvalue),str(minvalue)]
    numbers = ' '.join(strlst)
    return numbers