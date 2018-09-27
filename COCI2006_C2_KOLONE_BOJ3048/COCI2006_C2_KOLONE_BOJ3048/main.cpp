//
//  main.cpp
//  COCI2006_C2_KOLONE_BOJ3048
//
//  Created by 김성환 on 25/09/2018.
//  Copyright © 2018 김성환. All rights reserved.
//

#include <cstdio>

int n1,n2,t,s[100],p1=1,p2=1,k;
char c1[100],c2[100];
int main() {
    scanf("%d%d%s%s%d",&n1,&n2,c1+1,c2+1,&t);
    p1=n1;
    for(int i=0;i<n1;i++) if(i<t) s[n1-i]=t-i<n2?t-i:n2;
    for(int i=1;i<=n1;i++) {
        s[i]-=k;
        int cnt=s[i];
        while(cnt--) printf("%c",c2[p2++]) ;
        printf("%c",c1[p1--]);
        k+=s[i];
    }
    while(n2>=p2) printf("%c",c2[p2++]);
    return 0;
}
