

#pragma once

#include "BaseSolution.h"
#include "PrintTools.h"
class Contest360_1 : BaseSolution {
public:
    void test() { printOutput(furthestDistanceFromOrigin("_R__LL_")); }
    int res=0;
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int res =1;
        int l=0;
        int r=0;
        int dash=0;
        for(int i=1;i<n;++i){
            if(moves[i]=='L'){
                l++;
            }else if(moves[i]=='R'){
                r++;
            }else{
                dash++;
            }
        }
        return max(l+dash,r+dash);
    }

    void dfs(string& moves, int index, int d) {
        if(index >= moves.size()) {
            res = max(res,abs(d));
            return;
        }
        if(moves[index] == 'L' || moves[index] == '_') {
            dfs(moves, index + 1, d-1);
        }
        if(moves[index] == 'R' || moves[index] == '_') {
            dfs(moves, index + 1, d+1);
        }
    }
};