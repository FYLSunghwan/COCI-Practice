//
//  C2_4_TURBO(BOJ3006).cpp
//  COCI2007
//
//  Created by 김성환 on 02/10/2018.
//  Copyright © 2018 김성환. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

/**********************Fenwick Tree**********************/
void update(vector<ll> &tree, int idx, int num) {
    while(idx<tree.size()) {
        tree[idx]+=num;
        idx+=(idx&-idx);
    }
}

ll sum(vector<ll> &tree, int idx) {
    ll ans=0;
    while(idx>0) {
        ans+=tree[idx];
        idx-=(idx&-idx);
    }
    return ans;
}
/********************************************************/

int main() {
    int n,inp[100001],t,s=1,e;
    cin>>n;
    vector<ll> tree(n+1);
    e=n;
    for(int i=1;i<=n;i++) {
        cin>>t;
        inp[t]=i;
    }
    for(int i=1;i<=n;i++) update(tree,i,1);
    for(int i=1;i<=n;i++) {
        if(i%2) {
            printf("%lld\n",sum(tree,inp[s]-1));
            update(tree,inp[s],-1);
            s++;
        }
        else {
            printf("%lld\n",sum(tree,n)-sum(tree,inp[e]-1)-1);
            update(tree,inp[e],-1);
            e--;
        }
    }
    return 0;
}
