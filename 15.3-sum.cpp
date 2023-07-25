/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (31.21%)
 * Likes:    17973
 * Dislikes: 1726
 * Total Accepted:    2M
 * Total Submissions: 6.3M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an integer array nums, return all the triplets [nums[i], nums[j],
 * nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
 * nums[k] == 0.
 *
 * Notice that the solution set must not contain duplicate triplets.
 *
 *
 * Example 1:
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Example 2:
 * Input: nums = []
 * Output: []
 * Example 3:
 * Input: nums = [0]
 * Output: []
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 *
 *
 */

// @lc code=start
#include "BaseSolution.h"
#include "PrintTools.h"
#include <algorithm>
#include <unordered_set>
#include <vector>
class Solution15 : public BaseSolution {
public:
  void test() {
    vector<int> d = {-1, 0, 1, 2, -1, -4};
    printInput(d);
    printOutput(threeSum(d));
  }

public:
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    // 1.unsort +based on 2sum
    // 2.sort,then based on two pointers
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    set<tuple<int, int, int>> s;

    for (int i = 0; i < nums.size(); ++i) { // o(n)
      int lower = i + 1, upper = nums.size() - 1;
      while (lower < upper) { // o(logn)
        int sum = nums[lower] + nums[upper];
        if (sum + nums[i] == 0) {
          auto r = s.insert({nums[i], nums[lower], nums[upper]}); // o(logn)
          if (r.second) {
            res.push_back(vector<int>{nums[i], nums[lower], nums[upper]});
          }

          ++lower;
          --upper;
        } else if (sum + nums[i] > 0) {
          --upper;
        } else {
          ++lower;
        }
      }
    }
    return res;
  }
};
// @lc code=end
