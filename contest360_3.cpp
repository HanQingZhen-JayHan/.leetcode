

#pragma once

#include "BaseSolution.h"
#include "PrintTools.h"
#include <algorithm>
#include <cstdint>
#include <queue>
#include <unordered_map>
#include <vector>
class Contest360_3 : BaseSolution {
public:
    void test() {
        vector<int> data = { 1, 32, 1, 2 };
        printOutput(minOperations(data, 12));
    }
    int minOperations(vector<int>& nums, int target) {
        int res = 0;
        int sum = 0;
        // max heap
        priority_queue<int> q;
        for(auto it : nums) {
            q.push(it);
            sum += it;
        }
        while(target > 0) {
            int top = q.top();
            sum -= top;
            q.pop();
            if(top <= target) {
                target -= top;
            } else if(sum < target && top > target) {
                sum += top;
                q.push(top / 2);
                q.push(top / 2);
                res++;
            }
            if(q.empty() && target != 0) {
                return -1;
            }
        }
        return res;
    }
};