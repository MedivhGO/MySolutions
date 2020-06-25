/*
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (28.05%)
 * Total Accepted:    96.7K
 * Total Submissions: 344.6K
 * Testcase Example:  '"0000"'
 *
 * Given a string containing only digits, restore it by returning all possible
 * valid IP address combinations.
 * 
 * 
 * For example:
 * Given "25525511135",
 * 
 * 
 * return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 * 
 */
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if (s.empty()) return ans;
        string ip;
        dfs(s,0,0,ip,ans);
        return ans;
    }
    void dfs(string s,int start,int step,string ip,vector<string>& ans) {
        if (s.size() - start > (4 - step) * 3) 
            return ;
        if (s.size() - start < (4 - step))
            return ;
        if (start == s.size() && step == 4) {
            ip.resize(ip.size()-1);
            ans.push_back(ip);
            return;
        }
        int num = 0;
        for (int i = start;i<start+3;i++) {
            num = num*10+(s[i]-'0');
            if (num<=255) {
                ip+=s[i];
                dfs(s,i+1,step+1,ip+'.',ans);
            }
            if (num == 0) break;
        }
    }
};
