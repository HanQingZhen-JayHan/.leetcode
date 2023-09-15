/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 *
 * https://leetcode.com/problems/largest-divisible-subset/description/
 *
 * algorithms
 * Medium (40.62%)
 * Likes:    4907
 * Dislikes: 185
 * Total Accepted:    193.3K
 * Total Submissions: 458.9K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct positive integers nums, return the largest subset
 * answer such that every pair (answer[i], answer[j]) of elements in this
 * subset satisfies:
 *
 *
 * answer[i] % answer[j] == 0, or
 * answer[j] % answer[i] == 0
 *
 *
 * If there are multiple solutions, return any of them.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3]
 * Output: [1,2]
 * Explanation: [1,3] is also accepted.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,4,8]
 * Output: [1,2,4,8]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 1000
 * 1 <= nums[i] <= 2 * 10^9
 * All the integers in nums are unique.
 *
 *
 */

// @lc code=start
#include "BaseSolution.h"
#include "PrintTools.h"
#include <algorithm>
#include <vector>
class Solution368 : BaseSolution {
public:
    void test() {
        vector<int> data{ 3, 4, 16, 8 };
        printOutput(largestDivisibleSubset(data));
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> dp;
        int index = 0;
        dp.push_back({nums[0]});
        for(int i = 1; i < nums.size(); i++) {
            vector<int> tmp;
            for(int j = i - 1; j >= 0; j--) {
                if(nums[i] % dp[j].back() == 0) {
                    if(tmp.size() < dp[j].size() + 1) {
                        tmp = dp[j];
                        tmp.push_back(nums[i]);
                    }
                }
            }
            if(tmp.empty()) {
                tmp.push_back(nums[i]);
            }
            dp.push_back(tmp);

            if(dp[index].size() < tmp.size()) {
                index = i;
            }
        }
        return dp[index];
    }
};
// @lc code=end
