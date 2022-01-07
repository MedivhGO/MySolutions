#https://www.codewars.com/kata/5390bac347d09b7da40006f6
def toJadenCase(string):
    return " ".join([x.capitalize() for x in string.split()])