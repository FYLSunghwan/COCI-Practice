//
//  C1_4_MALI(BOJ2923).cpp
//  COCI2009
//
//  Created by 김성환 on 30/10/2018.
//  Copyright © 2018 김성환. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
const int MAX=-1e9,MIN=1e9;
int main() {
    int n,a,b,amin=MIN,amax=MAX,bmin=MIN,bmax=MAX;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a>>b;
        amin=min(a,amin);
        amax=max(a,amax);
        bmin=min(b,amin);
        bmax=max(b,bmax);
        cout<<max(amax+bmin,amin+bmax)<<endl;
    }
    return 0;
}
