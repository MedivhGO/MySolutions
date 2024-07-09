class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        generate_all(cur, n*2, ans);
        return ans;
    }

    void generate_all(string& current, int n, vector<string>& result) {
        if (n == current.size()) {
            if (valid(current)) {
                result.push_back(current);
            }
            return;
        }
        current += '(';
        generate_all(current, n, result);
        current.pop_back();
        current += ')';
        generate_all(current, n, result);
        current.pop_back();
    }

    bool valid(const string& str) {
        int balance = 0;
        for (auto x : str) {
            if (x == '(') {
                balance++;
            } else if (x == ')') {
                balance--;
            }
            if (balance < 0) {
                return false;
            }
        }
        return balance == 0;
    }
};

// 时间复杂度 O(2^2n*n)
// 空间复杂度 O(n)


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        helper(ans, cur, 0, 0, n);
        return ans;
    }

    void helper(vector<string>& ans, string& cur, int open, int close, int n) {
        if (cur.size() == 2*n) {
            ans.push_back(cur);
            return;
        }
        if (open < n) {
            cur.push_back('(');
            helper(ans, cur, open+1, close, n);
            cur.pop_back();
        }
        if (close < open) {
            cur.push_back(')');
            helper(ans, cur, open, close+1, n);
            cur.pop_back();
        }
    }
};

// 时间复杂度 O(4^n/n^(1/2))
// 空间复杂度 O(n)

//不是像 方法一 那样每次添加，我们可以通过跟踪到目前为止放置的左括号和右括号的数目来做到这一点。
//如果左括号数量不大于 nnn，我们可以放一个左括号。如果右括号数量小于左括号的数量，我们可以放一个右括号。