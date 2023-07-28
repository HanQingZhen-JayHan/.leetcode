/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (44.65%)
 * Likes:    14690
 * Dislikes: 622
 * Total Accepted:    1.4M
 * Total Submissions: 3M
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a string s and a dictionary of strings wordDict, return true if s can
 * be segmented into a space-separated sequence of one or more dictionary
 * words.
 *
 * Note that the same word in the dictionary may be reused multiple times in
 * the segmentation.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "leetcode", wordDict = ["leet","code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "applepenapple", wordDict = ["apple","pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 300
 * 1 <= wordDict.length <= 1000
 * 1 <= wordDict[i].length <= 20
 * s and wordDict[i] consist of only lowercase English letters.
 * All the strings of wordDict are unique.
 *
 *
 */

// @lc code=start
#include "BaseSolution.h"
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
class Solution139 : public BaseSolution {
public:
    void test() {
        string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
                   "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
                   "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
        vector<string> wordDict{ "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa" };
        cout << wordBreak(s, wordDict) << endl;
    }
    /**
     * |l|e|e|t|c|o|d|e| |
     *          j       i
     */
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> check(wordDict.begin(), wordDict.end());
        int len = s.size();
        bool dp[len + 1];
        dp[0] = true;
        for(int i = 1; i <= len; ++i) {
            for(int j = 0; j < i; ++j) {
                dp[i] = dp[j] && (check.find(s.substr(j, i - j)) != check.end());
                if(dp[i]) {
                    break;
                }
            }
        }
        return dp[len];
    }
};
// @lc code=end
