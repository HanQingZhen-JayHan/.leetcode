/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 *
 * https://leetcode.com/problems/word-ladder-ii/description/
 *
 * algorithms
 * Hard (27.10%)
 * Likes:    5539
 * Dislikes: 692
 * Total Accepted:    346.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * A transformation sequence from word beginWord to word endWord using a
 * dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... ->
 * sk such that:
 *
 *
 * Every adjacent pair of words differs by a single letter.
 * Every si for 1 <= i <= k is in wordList. Note that beginWord does not need
 * to be in wordList.
 * sk == endWord
 *
 *
 * Given two words, beginWord and endWord, and a dictionary wordList, return
 * all the shortest transformation sequences from beginWord to endWord, or an
 * empty list if no such sequence exists. Each sequence should be returned as a
 * list of the words [beginWord, s1, s2, ..., sk].
 *
 *
 * Example 1:
 *
 *
 * Input: beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log","cog"]
 * Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
 * Explanation: There are 2 shortest transformation sequences:
 * "hit" -> "hot" -> "dot" -> "dog" -> "cog"
 * "hit" -> "hot" -> "lot" -> "log" -> "cog"
 *
 *
 * Example 2:
 *
 *
 * Input: beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log"]
 * Output: []
 * Explanation: The endWord "cog" is not in wordList, therefore there is no
 * valid transformation sequence.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= beginWord.length <= 5
 * endWord.length == beginWord.length
 * 1 <= wordList.length <= 500
 * wordList[i].length == beginWord.length
 * beginWord, endWord, and wordList[i] consist of lowercase English
 * letters.
 * beginWord != endWord
 * All the words in wordList are unique.
 * The sum of all shortest transformation sequences does not exceed 10^5.
 *
 *
 */

// @lc code=start
#include "BaseSolution.h"
#include "PrintTools.h"
#include <cstdint>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
class Solution126 : public BaseSolution {
public:
    void test() {
        vector<string> wordList{
            "aaaaa", "caaaa", "cbaaa", "daaaa", "dbaaa", "eaaaa", "ebaaa", "faaaa",
            "fbaaa", "gaaaa", "gbaaa", "haaaa", "hbaaa", "iaaaa", "ibaaa", "jaaaa",
            "jbaaa", "kaaaa", "kbaaa", "laaaa", "lbaaa", "maaaa", "mbaaa", "naaaa",
            "nbaaa", "oaaaa", "obaaa", "paaaa", "pbaaa", "bbaaa", "bbcaa", "bbcba",
            "bbdaa", "bbdba", "bbeaa", "bbeba", "bbfaa", "bbfba", "bbgaa", "bbgba",
            "bbhaa", "bbhba", "bbiaa", "bbiba", "bbjaa", "bbjba", "bbkaa", "bbkba",
            "bblaa", "bblba", "bbmaa", "bbmba", "bbnaa", "bbnba", "bboaa", "bboba", "bbpaa",
            "bbpba", "bbbba", "abbba", "acbba", "dbbba", "dcbba", "ebbba", "ecbba", "fbbba",
            "fcbba", "gbbba", "gcbba", "hbbba", "hcbba", "ibbba", "icbba", "jbbba", "jcbba",
            "kbbba", "kcbba", "lbbba", "lcbba", "mbbba", "mcbba", "nbbba", "ncbba", "obbba",
            "ocbba", "pbbba", "pcbba", "ccbba", "ccaba", "ccaca", "ccdba", "ccdca", "cceba",
            "cceca", "ccfba", "ccfca", "ccgba", "ccgca", "cchba", "cchca", "cciba", "ccica",
            "ccjba", "ccjca", "cckba", "cckca", "cclba", "cclca", "ccmba", "ccmca", "ccnba",
            "ccnca", "ccoba", "ccoca", "ccpba", "ccpca", "cccca", "accca", "adcca", "bccca",
            "bdcca", "eccca", "edcca", "fccca", "fdcca", "gccca", "gdcca", "hccca", "hdcca",
            "iccca", "idcca", "jccca", "jdcca", "kccca", "kdcca", "lccca", "ldcca", "mccca",
            "mdcca", "nccca", "ndcca", "occca", "odcca", "pccca", "pdcca", "ddcca", "ddaca",
            "ddada", "ddbca", "ddbda", "ddeca", "ddeda", "ddfca", "ddfda", "ddgca", "ddgda",
            "ddhca", "ddhda", "ddica", "ddida", "ddjca", "ddjda", "ddkca", "ddkda", "ddlca",
            "ddlda", "ddmca", "ddmda", "ddnca", "ddnda", "ddoca", "ddoda", "ddpca", "ddpda",
            "dddda", "addda", "aedda", "bddda", "bedda", "cddda", "cedda", "fddda", "fedda",
            "gddda", "gedda", "hddda", "hedda", "iddda", "iedda", "jddda", "jedda", "kddda",
            "kedda", "lddda", "ledda", "mddda", "medda", "nddda", "nedda", "oddda", "oedda",
            "pddda", "pedda", "eedda", "eeada", "eeaea", "eebda", "eebea", "eecda", "eecea",
            "eefda", "eefea", "eegda", "eegea", "eehda", "eehea", "eeida", "eeiea", "eejda",
            "eejea", "eekda", "eekea", "eelda", "eelea", "eemda", "eemea", "eenda", "eenea",
            "eeoda", "eeoea", "eepda", "eepea", "eeeea", "ggggg", "agggg", "ahggg", "bgggg",
            "bhggg", "cgggg", "chggg", "dgggg", "dhggg", "egggg", "ehggg", "fgggg", "fhggg",
            "igggg", "ihggg", "jgggg", "jhggg", "kgggg", "khggg", "lgggg", "lhggg", "mgggg",
            "mhggg", "ngggg", "nhggg", "ogggg", "ohggg", "pgggg", "phggg", "hhggg", "hhagg",
            "hhahg", "hhbgg", "hhbhg", "hhcgg", "hhchg", "hhdgg", "hhdhg", "hhegg", "hhehg",
            "hhfgg", "hhfhg", "hhigg", "hhihg", "hhjgg", "hhjhg", "hhkgg", "hhkhg", "hhlgg",
            "hhlhg", "hhmgg", "hhmhg", "hhngg", "hhnhg", "hhogg", "hhohg", "hhpgg", "hhphg",
            "hhhhg", "ahhhg", "aihhg", "bhhhg", "bihhg", "chhhg", "cihhg", "dhhhg", "dihhg",
            "ehhhg", "eihhg", "fhhhg", "fihhg", "ghhhg", "gihhg", "jhhhg", "jihhg", "khhhg",
            "kihhg", "lhhhg", "lihhg", "mhhhg", "mihhg", "nhhhg", "nihhg", "ohhhg", "oihhg",
            "phhhg", "pihhg", "iihhg", "iiahg", "iiaig", "iibhg", "iibig", "iichg", "iicig",
            "iidhg", "iidig", "iiehg", "iieig", "iifhg", "iifig", "iighg", "iigig", "iijhg",
            "iijig", "iikhg", "iikig", "iilhg", "iilig", "iimhg", "iimig", "iinhg", "iinig",
            "iiohg", "iioig", "iiphg", "iipig", "iiiig", "aiiig", "ajiig", "biiig", "bjiig",
            "ciiig", "cjiig", "diiig", "djiig", "eiiig", "ejiig", "fiiig", "fjiig", "giiig",
            "gjiig", "hiiig", "hjiig", "kiiig", "kjiig", "liiig", "ljiig", "miiig", "mjiig",
            "niiig", "njiig", "oiiig", "ojiig", "piiig", "pjiig", "jjiig", "jjaig", "jjajg",
            "jjbig", "jjbjg", "jjcig", "jjcjg", "jjdig", "jjdjg", "jjeig", "jjejg", "jjfig",
            "jjfjg", "jjgig", "jjgjg", "jjhig", "jjhjg", "jjkig", "jjkjg", "jjlig", "jjljg",
            "jjmig", "jjmjg", "jjnig", "jjnjg", "jjoig", "jjojg", "jjpig", "jjpjg", "jjjjg",
            "ajjjg", "akjjg", "bjjjg", "bkjjg", "cjjjg", "ckjjg", "djjjg", "dkjjg", "ejjjg",
            "ekjjg", "fjjjg", "fkjjg", "gjjjg", "gkjjg", "hjjjg", "hkjjg", "ijjjg", "ikjjg",
            "ljjjg", "lkjjg", "mjjjg", "mkjjg", "njjjg", "nkjjg", "ojjjg", "okjjg", "pjjjg",
            "pkjjg", "kkjjg", "kkajg", "kkakg", "kkbjg", "kkbkg", "kkcjg", "kkckg", "kkdjg",
            "kkdkg", "kkejg", "kkekg", "kkfjg", "kkfkg", "kkgjg", "kkgkg", "kkhjg", "kkhkg",
            "kkijg", "kkikg", "kkljg", "kklkg", "kkmjg", "kkmkg", "kknjg", "kknkg", "kkojg",
            "kkokg", "kkpjg", "kkpkg", "kkkkg", "ggggx", "gggxx", "ggxxx", "gxxxx", "xxxxx",
            "xxxxy", "xxxyy", "xxyyy", "xyyyy", "yyyyy", "yyyyw", "yyyww", "yywww", "ywwww",
            "wwwww", "wwvww", "wvvww", "vvvww", "vvvwz", "avvwz", "aavwz", "aaawz", "aaaaz"
        };
        string beginWord = "aaaaa";
        string endWord = "ggggg";
        printOutput(findLadders(beginWord, endWord, wordList));
    }

private:
    class Node {
    public:
        string word;
        vector<string> v;
        Node(const string& w, const vector<string>& l) : word(w), v(l) {
            v.push_back(w);
        }
    };

public:
    vector<vector<string>>
    findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> visited;
        unordered_map<string, vector<string>> wordMap;
        int len = beginWord.size();
        //build word map. e.g[*it:hit,git]
        for(auto word : wordList) {
            string w = word;
            for(int i = 0; i < len; ++i) {
                char temp = w.at(i);
                w.at(i) = '*';
                wordMap[w].push_back(word);
                w.at(i) = temp;
            }
        }
        print(wordMap);
        queue<Node> q;
        int shortest = INT32_MAX;
        //build the first word
        q.push(Node(beginWord, vector<string>()));
        while(!q.empty()) {
            Node& node = q.front();
            visited.insert(node.word);
            if(node.v.size() < shortest) {
                if(node.word.compare(endWord) == 0) {
                    res.push_back(node.v);
                    shortest = node.v.size();
                } else {
                    string word = node.word;
                    //find the next possible words
                    for(int i = 0; i < len; ++i) {
                        char temp = word.at(i);
                        word.at(i) = '*';
                        vector<string>& l = wordMap[word];
                        word.at(i) = temp;
                        for(auto w : l) {
                            if(visited.find(w) == visited.end()) {
                                q.push(Node(w, node.v));
                            }
                        }
                    }
                }
            }
            q.pop();
        }
        return res;
    }
};
// @lc code=end
