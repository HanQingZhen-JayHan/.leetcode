#pragma once

#include "BaseSolution.h"
#include "PrintTools.h"
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
class Contest359_3 : public BaseSolution {
public:
    void test() {

        vector<vector<int>> data = { { 0, 1, 4 }, { 0, 0, 9 }, { 0, 0, 9 } };
        printOutput(maximizeTheProfit(5, data));
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<int> dp(n + 1);
        /**
         * @brief 3 dimensions
         *  0-----------1-----------2
         *  |-[0,0,2]   |-[0,1,2]   |-[0,2,2]
         *  |-[0,0,2]   |-[0,1,2]   |-[0,2,2]
         * @return vector<vector<vector<int>>>
         */
        vector<vector<vector<int>>> buckets(n);
        for(vector<int>& a : offers) {
            buckets[a[1]].push_back(a);
        }
        for(int i =1;i<=n;++i){
            dp[i] = dp[i-1];
            for(auto & a: buckets[i-1]){
                dp[i] = max(dp[i], dp[a[0]] + a[2]);
            }
        }

        
        return dp[n];
    }
};
