/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (31.83%)
 * Likes:    26191
 * Dislikes: 1545
 * Total Accepted:    2.5M
 * Total Submissions: 7.7M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, return the longest palindromic substring in s.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "babad"
 * Output: "bab"
 * Explanation: "aba" is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "cbbd"
 * Output: "bb"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 1000
 * s consist of only digits and English letters.
 *
 *
 */

// @lc code=start
#include "BaseSolution.h"
#include "PrintTools.h"
#include <algorithm>
class Solution : public BaseSolution {
public:
  void test() {
    printInput(data.palindromic);
    printOutput(longestPalindrome(data.palindromic));
  }

public:
  int maxLen(int lower, int upper, const string &str) {
    for (; lower >= 0 && upper < str.size();) {
      if (str.at(lower) == str.at(upper)) {
        --lower;
        ++upper;
      }else{
        break;
      }
    }
    return upper - lower -1;
  }
  string longestPalindrome(string s) {
    int size = s.size();
    int index=0;
    int len = 0;
    for (int i = 0; i < size; ++i) {

      int bb = maxLen(i-1, i, s);
      int aba = maxLen(i - 1, i + 1, s);
      if(bb>len || aba>len){
        len = max(bb,aba);
        index = i - (len / 2);
      }
    }
    // print(s.substr(lowerIndex, upperIndex));
    return s.substr(index, len);
  }

};
// @lc code=end
