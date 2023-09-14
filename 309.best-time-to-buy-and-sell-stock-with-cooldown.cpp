/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (52.63%)
 * Likes:    8910
 * Dislikes: 292
 * Total Accepted:    444.9K
 * Total Submissions: 777.3K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * You are given an array prices where prices[i] is the price of a given stock
 * on the i^th day.
 *
 * Find the maximum profit you can achieve. You may complete as many
 * transactions as you like (i.e., buy one and sell one share of the stock
 * multiple times) with the following restrictions:
 *
 *
 * After you sell your stock, you cannot buy stock on the next day (i.e.,
 * cooldown one day).
 *
 *
 * Note: You may not engage in multiple transactions simultaneously (i.e., you
 * must sell the stock before you buy again).
 *
 *
 * Example 1:
 *
 *
 * Input: prices = [1,2,3,0,2]
 * Output: 3
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 *
 *
 * Example 2:
 *
 *
 * Input: prices = [1]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= prices.length <= 5000
 * 0 <= prices[i] <= 1000
 *
 *
 */

// @lc code=start
#include "BaseSolution.h"
#include "PrintTools.h"
#include <algorithm>
#include <vector>
class Solution309 : BaseSolution {
public:
    void test() {
        vector<int> data{ 1, 2, 5, 0, 5, 7 };
        printOutput(maxProfit(data));
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> buy(n + 1, 0);
        vector<int> sell(n + 1, 0);
        vector<int> rest(n + 1, 0);
        buy[0] = -prices[0];
        for(int i = 0; i < n; i++) {
            rest[i + 1] = max(rest[i], sell[i]);
            buy[i + 1] = max(buy[i], rest[i] - prices[i]);
            sell[i + 1] = buy[i] + prices[i];
        }
        return max(sell[n], rest[n]);
    }
};
// @lc code=end
