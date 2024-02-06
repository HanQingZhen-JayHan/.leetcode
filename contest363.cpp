#pragma once

#include "BaseSolution.h"
#include "PrintTools.h"
#include <algorithm>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
class Contest363 : BaseSolution {
public:
    void test() {

        vector<int> data{ 4, 3, 2, 1 };
        printOutput(sumIndicesWithKSetBits(data, 2));
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {

        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(getSetBits(i) == k) {
                ans += nums[i];
            }
        }
        return ans;
    }
    int getSetBits(int n) {
        int c = 0;
        while(n > 0) {
            if(n & 0x1 != 0) {
                c++;
            }
            n = n >> 1;
        }
        return c;
    }

    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int ans = nums[0] < 1 ? 1 : 0;
        int c = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] < c) {
                c++;
            } else if(i + 1 > nums[i]) {
                ans++;
            }
        }
        return ans;
    }
};