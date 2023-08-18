/*
 * @lc app=leetcode id=816 lang=cpp
 *
 * [816] Ambiguous Coordinates
 *
 * https://leetcode.com/problems/ambiguous-coordinates/description/
 *
 * algorithms
 * Medium (55.95%)
 * Likes:    300
 * Dislikes: 644
 * Total Accepted:    28.1K
 * Total Submissions: 49.9K
 * Testcase Example:  '"(123)"'
 *
 * We had some 2-dimensional coordinates, like "(1, 3)" or "(2, 0.5)". Then, we
 * removed all commas, decimal points, and spaces and ended up with the string
 * s.
 *
 *
 * For example, "(1, 3)" becomes s = "(13)" and "(2, 0.5)" becomes s =
 * "(205)".
 *
 *
 * Return a list of strings representing all possibilities for what our
 * original coordinates could have been.
 *
 * Our original representation never had extraneous zeroes, so we never started
 * with numbers like "00", "0.0", "0.00", "1.0", "001", "00.01", or any other
 * number that can be represented with fewer digits. Also, a decimal point
 * within a number never occurs without at least one digit occurring before it,
 * so we never started with numbers like ".1".
 *
 * The final answer list can be returned in any order. All coordinates in the
 * final answer have exactly one space between them (occurring after the
 * comma.)
 *
 *
 * Example 1:
 *
 *
 * Input: s = "(123)"
 * Output: ["(1, 2.3)","(1, 23)","(1.2, 3)","(12, 3)"]
 *
 *
 * Example 2:
 *
 *
 * Input: s = "(0123)"
 * Output: ["(0, 1.23)","(0, 12.3)","(0, 123)","(0.1, 2.3)","(0.1, 23)","(0.12,
 * 3)"]
 * Explanation: 0.0, 00, 0001 or 00.01 are not allowed.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "(00011)"
 * Output: ["(0, 0.011)","(0.001, 1)"]
 *
 *
 *
 * Constraints:
 *
 *
 * 4 <= s.length <= 12
 * s[0] == '(' and s[s.length - 1] == ')'.
 * The rest of s are digits.
 *
 *
 */

// @lc code=start
#include "BaseSolution.h"
#include "PrintTools.h"
#include <string>
#include <vector>
class Solution816 : BaseSolution {
public:
    void test() {
        string s = "(000123000)";
        print(ambiguousCoordinates(s));
    }

public:
    vector<string> ambiguousCoordinates(string s) {
        vector<string> collection;
        string pureDigits = s.substr(1, s.size() - 2);
        for(int i = 1; i < pureDigits.size(); i++) {

            string left = pureDigits.substr(0, i);
            string right = pureDigits.substr(i);

            vector<string> lc = compose(left);
            vector<string> rc = compose(right);
            if(lc.empty() || rc.empty()) {
                continue;
            }
            for(auto l : lc) {
                for(auto r : rc) {
                    collection.push_back("(" + l + ", " + r + ")");
                }
            }
        }
        return collection;
    }
    /*
    [0XXXX0] -> {}
    [0XXXXX] -> {0.XXXX}
    [XXXXX0] -> {XXXXX0}
    [XXXX] -> [XXXX]+[X.XXX]+[XX.XX]+[XXX.X]
    */
    vector<string> compose(const string& str) {

        int size = str.size();
        if(size == 0) {
            return {};
        }
        if(size == 1) {
            return { str };
        }
        if(str[0] == '0' && str[size - 1] == '0') {
            return {};
        }
        if(str[0] == '0') {
            return { "0." + str.substr(1, size - 1) };
        }
        if(str[size - 1] == '0') {
            return { str };
        }
        vector<string> collection;
        for(int i = 1; i < size; i++) {
            collection.push_back(str.substr(0, i) + "." + str.substr(i));
        }
        collection.push_back(str);
    }
};
// @lc code=end
