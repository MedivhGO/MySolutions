/*
 * [648] Replace Words
 *
 * https://leetcode.com/problems/replace-words/description/
 *
 * algorithms
 * Medium (47.47%)
 * Total Accepted:    12.1K
 * Total Submissions: 25.4K
 * Testcase Example:  '["cat", "bat", "rat"]\n"the cattle was rattled by the battery"'
 *
 * 
 * In English, we have a concept called root, which can be followed by some
 * other words to form another longer word - let's call this word successor.
 * For example, the root an, followed by other, which can form another word
 * another.
 * 
 * 
 * 
 * 
 * Now, given a dictionary consisting of many roots and a sentence. You need to
 * replace all the successor in the sentence with the root forming it. If a
 * successor has many roots can form it, replace it with the root with the
 * shortest length.
 * 
 * 
 * 
 * You need to output the sentence after the replacement.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: dict = ["cat", "bat", "rat"]
 * sentence = "the cattle was rattled by the battery"
 * Output: "the cat was rat by the bat"
 * 
 * 
 * 
 * 
 * Note:
 * 
 * The input will only have lower-case letters.
 * ⁠1 
 * ⁠1 
 * ⁠1 
 * ⁠1 
 * 
 * 
 */
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        string ans;
        if (dict.empty() || sentence.empty()) return ans;
        sort(dict.begin(),dict.end(),[](string s1,string s2) { return s1.size() < s2.size();});
        stringstream ss;
        ss<<sentence;
        string curstr;
        
        while (ss>>curstr) {
            int flag = 0;
            for (auto d : dict) {
                if (curstr.find(d) == 0) {
                    ans.append(d+" ");
                    flag = 1;
                    break;
                }
            }
            if (flag != 1)
                ans.append(curstr+" ");
            
        }
        ans.erase(ans.end()-1);
        
        return ans;
    }
};
