//
//  C2_4_SJECISTA(BOJ3049).cpp
//  COCI2006
//
//  Created by 김성환 on 28/09/2018.
//  Copyright © 2018 김성환. All rights reserved.
//
/***********이딴노가다 하지 맙시다 하하하하하***********

#include <iostream>
using namespace std;
int ans[101]={0,1,0,},n;

int main() {
    cin>>n;
    for(int i=2;i<=n-3;i++)
        for(int j=1;j<=i;j++) {
            if(j==i) ans[j]=i-1;
            else ans[j]+=j;
        }
    printf("%d",ans[n]);
    return 0;
}

***********************************************/
#include <iostream>
int main() {
    int n;
    std::cin>>n;
    std::cout<<n*(n-1)*(n-2)*(n-3)/24;
    return 0;
}
