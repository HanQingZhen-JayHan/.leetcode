/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (40.63%)
 * Likes:    17658
 * Dislikes: 396
 * Total Accepted:    1.5M
 * Total Submissions: 3.6M
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given an integer array coins representing coins of different
 * denominations and an integer amount representing a total amount of money.
 *
 * Return the fewest number of coins that you need to make up that amount. If
 * that amount of money cannot be made up by any combination of the coins,
 * return -1.
 *
 * You may assume that you have an infinite number of each kind of coin.
 *
 *
 * Example 1:
 *
 *
 * Input: coins = [1,2,5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 *
 *
 * Example 2:
 *
 *
 * Input: coins = [2], amount = 3
 * Output: -1
 *
 *
 * Example 3:
 *
 *
 * Input: coins = [1], amount = 0
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= coins.length <= 12
 * 1 <= coins[i] <= 2^31 - 1
 * 0 <= amount <= 10^4
 *
 *
 */

// @lc code=start
#include "BaseSolution.h"
#include "PrintTools.h"
#include <algorithm>
#include <climits>
#include <map>
#include <queue>
#include <unordered_set>
#include <vector>
class Solution322 : BaseSolution {
public:
    void test() {
        vector<int> data{ 186, 419, 83, 408 };
        printOutput(coinChange(data, 6249));
    }

public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        vector<int> dp(amount + 1, amount+1);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++) {
            for(auto c : coins) {
                if(i >= c) {
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }
        return dp[amount]>amount ? -1: dp[amount];
    }
};
// @lc code=end
