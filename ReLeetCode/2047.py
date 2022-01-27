class Solution:
    def countValidWords(self, sentence: str) -> int:
        ans = 0
        if len(sentence) == 0:
            return ans
        word_list = sentence.split(' ')
        helper_list = [chr(i) for i in range(97, 123)]
        alpha_list = [chr(i) for i in range(97, 123)]
        helper_list.append('.')
        helper_list.append('!')
        helper_list.append(',')
        
        for x in word_list:
            if len(x) == 0:
                continue
            if x.count('-') > 1:
                continue
            if x.count('.') + x.count('!') +  x.count(',') > 1:
                continue
            if x.startswith('-') or x.endswith('-'):
                continue
            if (x.startswith('!') or x.startswith('.') or x.startswith(',')) and len(x) != 1:
                continue
            flag = True
            for idx, e in enumerate(x):
                len_e = len(x)
                if e in [str(i) for i in range(10)]:
                    flag = False
                    break
                if (e == '.' or e == '!' or e == ',') and (idx != len_e - 1):
                    flag = False
                    break
                if (e == '-') and (x[idx - 1] not in alpha_list or x[idx + 1] not in alpha_list):
                    flag = False
                    break 
                if (idx == len_e - 1) and (e not in helper_list):
                    flag = False
                    break
            ans += 1 if flag == True else 0
        return ans

# 模拟

# 时间复杂度 O(n)
# 空间复杂度 O(1)