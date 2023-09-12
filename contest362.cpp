#pragma once

#include "BaseSolution.h"
#include <algorithm>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
class Contest362 : BaseSolution {
public:
    void test() {}

    int numberOfPoints(vector<vector<int>>& nums) {
        unordered_set<int> col;
        for(auto it : nums) {
            for(int i = it[0]; i <= it[1]; i++) {
                col.insert(i);
            }
        }
        return col.size();
    }
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && sy == fy) {
            return t != 1;
        }
        int m = abs(fx - sx);
        int n = abs(fy - sy);
        return max(m, n) <= t;
    }

    int minimumMoves(vector<vector<int>>& grid) {
        unordered_set<int> col;
        queue<vector<int>> q;
        for(auto it : grid) {
            if(it[2] == 0) {
                col.insert(calculate(it[0], it[1]));
            } else if(it[2] > 1) {
                q.push(it);
            }
        }
        int ans;
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it[0];
            int y = it[1];
            int value = it[2];
            if(x - 1 >= 0 && y - 1 >= 0 && value > 1) {
                int c = calculate(x - 1, y - 1);
                if(col.find(c) != col.end()) {
                    col.erase(c);
                    value--;
                }
            }
            if(x + 1 <= 3 && y - 1 >= 0 && value > 1) {
                int c = calculate(x + 1, y - 1);
                if(col.find(c) != col.end()) {
                    col.erase(c);
                    value--;
                }
            }
            if(x - 1 >= 0 && y + 1 <= 3 && value > 1) {
                int c = calculate(x - 1, y + 1);
                if(col.find(c) != col.end()) {
                    col.erase(c);
                    value--;
                }
            }
            if(x + 1 <= 3 && y + 1 <= 3 && value > 1) {
                int c = calculate(x + 1, y + 1);
                if(col.find(c) != col.end()) {
                    col.erase(c);
                    value--;
                }
            }
            if(value > 1) {
                it[2] = value;
                q.push(it);
            }
        }
    }
    int calculate(int x, int y) { return 3 * y + x; }
};