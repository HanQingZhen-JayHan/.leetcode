#pragma once

#include "BaseSolution.h"
#include <unordered_map>
#include <vector>
class Contest361_3 : BaseSolution {
public:
    void test() {}

    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long res = 0;
        long long acc = 0;
        unordered_map<int, int> count;
        count[0] = 1;
        for(int a : nums) {
            acc = (acc + (a % modulo == k ? 1 : 0)) % modulo;
            res += count[(acc - k + modulo) % modulo];
            count[acc]++;
        }
        return res;
    }
};