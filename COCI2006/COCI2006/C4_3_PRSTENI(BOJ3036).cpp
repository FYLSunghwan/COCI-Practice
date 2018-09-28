//
//  C4_3_PRSTENI(BOJ3036).cpp
//  COCI2006
//
//  Created by 김성환 on 28/09/2018.
//  Copyright © 2018 김성환. All rights reserved.
//

#include <cstdio>
int n,f,t;
int gcd(int a, int b) {return b?gcd(b,a%b):a;}
int main() {
    scanf("%d%d",&n,&f);
    for(int i=1;i<n;i++) {
        scanf("%d",&t);
        int g=gcd(f,t);
        printf("%d/%d\n",f/g,t/g);
    }
    return 0;
}
