

#pragma once

#include "BaseSolution.h"
#include "PrintTools.h"
#include <unordered_map>
class Contest360_2 : BaseSolution {
public:
    void test() {
        minimumPossibleSum(2,3);}
    long minimumPossibleSum(int n, int target) {
        long res = 0;
        unordered_set<int> data;
        int i=0,j=1;
        while(i<n) {
            if(data.find(j) == data.end()) {
                res += j;
                data.insert(target - j);
                ++i;
            }
            ++j;

        }
        return res;
    }
};