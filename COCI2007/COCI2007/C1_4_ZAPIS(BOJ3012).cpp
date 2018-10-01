//
//  C1_4_ZAPIS(BOJ3012).cpp
//  COCI2007
//
//  Created by 김성환 on 30/09/2018.
//  Copyright © 2018 김성환. All rights reserved.
//

#include <cstdio>
#include <string.h>

char str[1000],open[4]="([{",close[4]=")]}";
int N,isBig;
long long dp[202][202];
const int MOD = 100000;

long long f(int s, int e) {
    long long& ret = dp[s][e];
    if(ret!=-1) return ret;
    ret=0;
    if(s>e) {ret=1; return ret;}
    for(int i=s+1;i<=e;i++)
        for(int j=0;j<3;j++)
            if(str[s]==open[j] || str[s]=='?')
                if(str[i]==close[j]||str[i]=='?') {
                    ret+=(f(s+1,i-1)*f(i+1,e));
                    if(ret>=MOD) {
                        isBig = 1;
                        ret=MOD+ret%MOD;
                    }
                }
    return ret;
}

int main() {
    memset(dp,-1,sizeof(dp));
    scanf("%d%s",&N,str+1);
    long long ans=f(1,N);
    if(ans>MOD) printf("%05lld",ans-MOD);
    else printf("%lld",ans);
    return 0;
}
