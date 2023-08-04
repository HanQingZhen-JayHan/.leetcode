/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
 *
 * https://leetcode.com/problems/push-dominoes/description/
 *
 * algorithms
 * Medium (52.36%)
 * Likes:    3236
 * Dislikes: 205
 * Total Accepted:    115.7K
 * Total Submissions: 202.9K
 * Testcase Example:  '"RR.L"'
 *
 * There are n dominoes in a line, and we place each domino vertically upright.
 * In the beginning, we simultaneously push some of the dominoes either to the
 * left or to the right.
 *
 * After each second, each domino that is falling to the left pushes the
 * adjacent domino on the left. Similarly, the dominoes falling to the right
 * push their adjacent dominoes standing on the right.
 *
 * When a vertical domino has dominoes falling on it from both sides, it stays
 * still due to the balance of the forces.
 *
 * For the purposes of this question, we will consider that a falling domino
 * expends no additional force to a falling or already fallen domino.
 *
 * You are given a string dominoes representing the initial state where:
 *
 *
 * dominoes[i] = 'L', if the i^th domino has been pushed to the left,
 * dominoes[i] = 'R', if the i^th domino has been pushed to the right, and
 * dominoes[i] = '.', if the i^th domino has not been pushed.
 *
 *
 * Return a string representing the final state.
 *
 *
 * Example 1:
 *
 *
 * Input: dominoes = "RR.L"
 * Output: "RR.L"
 * Explanation: The first domino expends no additional force on the second
 * domino.
 *
 *
 * Example 2:
 *
 *
 * Input: dominoes = ".L.R...LR..L.."
 * Output: "LL.RR.LLRRLL.."
 *
 *
 *
 * Constraints:
 *
 *
 * n == dominoes.length
 * 1 <= n <= 10^5
 * dominoes[i] is either 'L', 'R', or '.'.
 *
 *
 */

// @lc code=start
#include "BaseSolution.h"
#include "PrintTools.h"
#include <stack>
#include <vector>
class Solution838 : public BaseSolution {
public:
    void test() {
        // string data = ".L.R...LR..L..";
        // printInput(data);
        // printOutput(pushDominoes(data));
        // data = "R...R....";
        // printInput(data);
        // printOutput(pushDominoes(data));
        //  data = "...R";
        // printInput(data);
        // printOutput(pushDominoes(data));
        //  data = "..L..";
        // printInput(data);
        // printOutput(pushDominoes(data));
        //  data = "....LR....";
        // printInput(data);
        // printOutput(pushDominoes(data));
        string data = "RR.L";
        printInput(data);
        printOutput(pushDominoes(data));
    }

public:
    void addCharacter(stack<char>& status, int n, char c) {
        while(n > 0) {
            status.push(c);
            n--;
        }
    }
    string pushDominoes(string dominoes) {
        stack<char> status;
        char st = '.';
        int indexR = -1;
        for(int i = 0; i < dominoes.size(); ++i) {
            char c = dominoes[i];
            if(c == '.') {
                status.push(c);
            } else if(c == 'L') {
                int count = 1;
                //"..L"
                while(!status.empty() && status.top() == '.') {
                    count++;
                    status.pop();
                }
                //"R..L"
                if(indexR >= 0) {
                    int total = i - indexR + 1;
                    int half = total / 2;
                    // add Rs
                    addCharacter(status, half - 1, 'R');
                    if(total % 2 == 1) {
                        status.push('.');
                    }
                    // add Ls
                    addCharacter(status, half, 'L');
                    indexR = -1;
                } else {
                    // add Ls
                    addCharacter(status, count, 'L');
                }
            } else {
                //"R.R"
                if(indexR >= 0) {
                    int count = 0;
                    while(!status.empty() && status.top() == '.') {
                        count++;
                        status.pop();
                    }
                    // add Rs
                    addCharacter(status, count, 'R');
                }
                status.push('R');
                indexR = i;
            }
        }
        // “R.”
        if(indexR >= 0) {
            int count = 0;
            while(!status.empty() && status.top() == '.') {
                count++;
                status.pop();
            }
            // add Rs
            addCharacter(status, count, 'R');
        }
        vector<char> res;
        while(!status.empty()) {
            res.push_back(status.top());
            status.pop();
        }


        return string(res.crbegin(), res.crend());
    }
};
// @lc code=end
