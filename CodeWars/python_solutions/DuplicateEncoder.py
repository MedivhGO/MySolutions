#https://www.codewars.com/kata/54b42f9314d9229fd6000d9c
def duplicate_encode(word):
    #your code here
    dic = {}
    word = word.lower()
    for x in word:
        dic[x] = word.count(x)
        
    ans = ""
    for x in word:
        if dic[x] == 1:
            ans+="("
        else:
            ans+=")"
    return ans