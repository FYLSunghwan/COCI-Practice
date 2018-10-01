//
//  C4_4_ZBRKA(BOJ3037).cpp
//  COCI2006
//
//  Created by 김성환 on 28/09/2018.
//  Copyright © 2018 김성환. All rights reserved.
//

#include <iostream>
#include <string.h>

const int MOD = 1000000007;
int dp[1001][10001],N,C;

int f(int n, int k) {
    if(dp[n][k]!=-1) return dp[n][k];
    int& ret=dp[n][k];
    if(k<1) {ret = 1; return ret;}
    if(n<1) {ret = 0; return ret;}
    if(k-n>=0)
        ret = ((f(n,k-1)%MOD + f(n-1,k)%MOD)%MOD-f(n-1,k-n)+MOD)%MOD;
    else
        ret = (f(n,k-1)%MOD + f(n-1,k)%MOD)%MOD;
    return ret;
}

int main() {
    memset(dp,-1,sizeof(dp));
    std::cin>>N>>C;
    std::cout<<f(N,C);
    return 0;
}
