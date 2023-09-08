#pragma once

#include "BaseSolution.h"
#include <algorithm>
#include <queue>
#include <vector>
class Contest361_2 : BaseSolution {
public:
    void test() {}

    int minimumOperations(string num) {
        int n = num.size();
        vector<vector<int>> cache(n, vector<int>(25, -1));
        return dfs(num, 0, 0, cache);
    }
    // 2575%25 = (2500+75)%25
    int dfs(string& num, int index, int digit, vector<vector<int>>& cache) {
        if(index == num.size()) {
            if(digit == 0) {
                return 0;
            }
            return num.size();
        }
        if(cache[index][digit] != -1) {
            return cache[index][digit];
        }
        int take = dfs(num, index + 1, (digit * 10 + num[index] - '0') % 25, cache);
        int not_take = dfs(num, index + 1, digit, cache);
        cache[index][digit] = min(take, 1 + not_take);
        return cache[index][digit];
    }
};