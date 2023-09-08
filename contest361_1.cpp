#pragma once

#include "BaseSolution.h"
#include <string>
class Contest361_1 : BaseSolution {
public:
    void test() {}
    int countSymmetricIntegers(int low, int high) {
        int res=0;
        for(int i=low;i<=high;++i){
            string s = to_string(i);
            if(s.size()%2==0){
                int sum=0;
                for(int j=0;j<s.size();++j){
                    if(j<(s.size()/2)){
                        sum += s[j];
                    }else{
                        sum -=s[j];
                    }
                }
                if(sum==0){
                    res++;
                }
            }
        }
        return res;
    }
};