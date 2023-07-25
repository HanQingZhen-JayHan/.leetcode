/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (39.75%)
 * Likes:    9353
 * Dislikes: 349
 * Total Accepted:    976.4K
 * Total Submissions: 2.5M
 * Testcase Example:
 * '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given an m x n grid of characters board and a string word, return true if
 * word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring. The same
 * letter cell may not be used more than once.
 *
 *
 * Example 1:
 *
 *
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCCED"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "SEE"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCB"
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * m == board.length
 * n = board[i].length
 * 1 <= m, n <= 6
 * 1 <= word.length <= 15
 * board and word consists of only lowercase and uppercase English letters.
 *
 *
 *
 * Follow up: Could you use search pruning to make your solution faster with a
 * larger board?
 *
 */

// @lc code=start
#include "BaseSolution.h"
#include "PrintTools.h"
#include <vector>
class Solution79 : public BaseSolution {
public:
  void test() {
    vector<vector<char>> d{
        {'A', 'B', 'C', 'E'}, {'S', 'F', 'E', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCESEEEFS";
    bool r = exist(d, word);
    cout << "result: " << r << endl;
  }

public:
  bool exist(vector<vector<char>> &board, string word) {
    int r = board.size();
    int c = board[0].size();
    //O(mn(3mn-m-n))
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (board[i][j] == word.at(0)) {
          if (dfs(board, word, 0, i, j)) {
            return true;
          }
        }
      }
    }
    return false;
  }
  // A grid graph G_(m,n) has mn nodes and (m-1)n+(n-1)m=2mn-m-n edges
  // Time complexity is O(V+E) = O(mn+2mn-m-n)=O(3mn-m-n)
  bool dfs(vector<vector<char>> &board, const string word, int idx, int i,
           int j) {
    if (idx == word.size()) {
      return true;
    }
    int r = board.size();
    int c = board[0].size();
    if (i < 0 || i >= r || j < 0 || j >= c) {
      return false;
    }
    bool result = false;

    if (board[i][j] == word.at(idx)) {
      //mark
      board[i][j] = '@';
      result = dfs(board, word, idx + 1, i - 1, j) ||
               dfs(board, word, idx + 1, i + 1, j) ||
               dfs(board, word, idx + 1, i, j - 1) ||
               dfs(board, word, idx + 1, i, j + 1);
      //restore
      board[i][j] = word.at(idx);
    }

    return result;
  }
};
// @lc code=end
