/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {

public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> m_map;
    for (int i = 0; i < nums.size(); i++) {
      if (m_map.find(nums[i]) != m_map.end()) {
        vector<int> res{m_map[nums[i]], i};
        return res;
      } else {
        m_map[target - nums[i]] = i;
      }
    }
    return vector<int>();
  }
};
// @lc code=end
