/*
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (19.77%)
 * Total Accepted:    148.5K
 * Total Submissions: 750.9K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * the length of shortest transformation sequence from beginWord to endWord,
 * such that:
 * 
 * 
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 * 
 * 
 * 
 * For example,
 * 
 * 
 * Given:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * 
 * As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * return its length 5.
 * 
 * 
 * 
 * Note:
 * 
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * 
 * 
 * 
 * 
 * UPDATE (2017/1/20):
 * The wordList parameter had been changed to a list of strings (instead of a
 * set of strings). Please reload the code definition to get the latest
 * changes.
 * 
 */
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        queue<string> toVisit;
        bfs(beginWord,dict,toVisit);
        int dist = 2;
        while (!toVisit.empty()) {
            int n = toVisit.size();
            for (int  i = 0; i < n;i++) {
                string word = toVisit.front();
                toVisit.pop();
                if (word == endWord) return dist;
                bfs(word,dict,toVisit);
            }
            dist++;
        }
        return 0;
    }
   
    void bfs(string word,unordered_set<string>& dict, queue<string>& toVisit) {
        dict.erase(word);
        for (int i=0;(int) i < word.size();i++) {//逐个将word中的每个字母进行替换
            char letter = word[i];
            for (int k = 0; k < 26;k++) {//所有可能生成的新单词
                word[i] = 'a' + k;
                if (dict.find(word)!=dict.end()){ //如果新生成的单词在字典中可以找到，就以该单词为起点进行广度优先搜索，并将该单词从字典中删除。
                    toVisit.push(word);
                    dict.erase(word);
                }
            }
            word[i] = letter; //恢复word中被改变的字母，保证每次循环只改变一个字母。
        }
    }
};
