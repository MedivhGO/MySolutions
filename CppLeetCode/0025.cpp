class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) {
            return false;
        }
        stack<char> stk;
        for (int i = 0; i < s.size(); ++i) {
            auto x = s[i];
            if (x == '(' || x == '{' || x == '[') {
                stk.push(x);
                continue;
            }
            if (stk.empty()) {
                return false;
            }
            char left = stk.top();
            if ((x == '}' && left == '{') ||
                (x == ')' && left == '(') ||
                (x == ']' && left == '[')) {
                stk.pop();
            } else {
                return false;
            }
        }
        return stk.empty();
    }
};

// 时间复杂度 O(n)
// 空间复杂度 O(n)

// 1. 判断栈顶元素之前需要保证栈不为空，所以 stk.empty() 分支需要在 第 14 行进行判断。
// 2. 如果第 18 行开始的条件都不满足，那么就可以结束遍历了，因为已经出现括号不匹配的情况。所以在第 23 行 return false