#https://www.codewars.com/kata/58223370aef9fc03fd000071
def dashatize(num):
    numstr = str(num)
    for x in ['1','3','5','7','9']:
        numstr = numstr.replace(x,'-'+x+'-')
    return numstr.strip('-').replace('--','-')