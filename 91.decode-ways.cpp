/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (30.40%)
 * Likes:    10437
 * Dislikes: 4328
 * Total Accepted:    1.1M
 * Total Submissions: 3.2M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z can be encoded into numbers using the
 * following mapping:
 *
 *
 * 'A' -> "1"
 * 'B' -> "2"
 * ...
 * 'Z' -> "26"
 *
 *
 * To decode an encoded message, all the digits must be grouped then mapped
 * back into letters using the reverse of the mapping above (there may be
 * multiple ways). For example, "11106" can be mapped into:
 *
 *
 * "AAJF" with the grouping (1 1 10 6)
 * "KJF" with the grouping (11 10 6)
 *
 *
 * Note that the grouping (1 11 06) is invalid because "06" cannot be mapped
 * into 'F' since "6" is different from "06".
 *
 * Given a string s containing only digits, return the number of ways to decode
 * it.
 *
 * The test cases are generated so that the answer fits in a 32-bit integer.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "12"
 * Output: 2
 * Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
 *
 *
 * Example 2:
 *
 *
 * Input: s = "226"
 * Output: 3
 * Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2
 * 2 6).
 *
 *
 * Example 3:
 *
 *
 * Input: s = "06"
 * Output: 0
 * Explanation: "06" cannot be mapped to "F" because of the leading zero ("6"
 * is different from "06").
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 100
 * s contains only digits and may contain leading zero(s).
 *
 *
 */

// @lc code=start
#include "BaseSolution.h"
#include "PrintTools.h"
#include <string>
#include <vector>
class Solution91 : BaseSolution {
public:
    void test() {
        // printOutput(numDecodings("226"));
        // printOutput(numDecodings("236"));
        printOutput(numDecodings("11110"));
    }

public:
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0') {
            return 0;
        }
        int n = s.size();
        vector<int> dp(n + 1, 0);
        for(int i = n; i >= 0; --i) {
            if(i == n) {
                dp[i] = 1;
            } else {
                //22 6
                if(s[i] != '0') {
                    dp[i] = dp[i + 1];
                }
                //2 26
                if(i < n - 1) {
                    int d = stoi(s.substr(i, 2));
                    if(d >= 10 && d <= 26) {
                        dp[i] += dp[i + 2];
                    }
                }
            }
        }
        return dp[0];
    }
};
// @lc code=end
