class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) {
            return s;
        }
        int maxlen = 1;
        int begin = 0;
        vector<vector<int>> dp(n, vector<int>(n, 1));
        for (int L = 2; L <= n; ++L) {
            for (int i = 0; i < n; ++i) {
                int j = L + i - 1;
                if (j >= n) {
                    break;
                }
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                if (dp[i][j] && j - i + 1 > maxlen) {
                    maxlen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxlen);
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return s;
        }
        if (s.size() < 2) {
            return s;
        }
        int start = 0, end = 0;
        int len = INT_MIN;
        for (int i = 0; i < s.size(); ++i) {
            int len1 = longestHelper(i, i, s);
            int len2 = longestHelper(i, i+1, s);
            if (len < max(len1, len2)) {
                len = max(len1, len2);
                start = i - (len - 1) / 2;
                end = i + len/2;
            }
        }
        return s.substr(start, end - start + 1);
    }
    
    int longestHelper(int m, int n, string s) {
        while (m >= 0 && n < s.size() && s[m] == s[n]) {
            m--;
            n++;
        }
        return n - m - 1;
    }
};