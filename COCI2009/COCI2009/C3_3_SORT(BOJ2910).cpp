//
//  C2_3_SORT(BOJ2910).cpp
//  COCI2009
//
//  Created by 김성환 on 05/11/2018.
//  Copyright © 2018 김성환. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

struct vcst{
    ll num;
    ll cnt;
    bool operator<(const vcst &cmp) const {
        return cnt>cmp.cnt;
    }
};

int ar[1000000001];
ll n,c,t;
set<ll> st;
vector<vcst> vc;

int main() {
    cin>>n>>c;
    for(int i=0;i<n;i++) {
        cin>>t;
        ar[t]++;
        st.insert(t);
    }
    for(auto i=st.begin();i!=st.end();i++) {
        ll a= *i;
        vc.push_back({a,ar[a]});
    }
    sort(vc.begin(),vc.end());
    for(auto &i:vc)
        while(i.cnt) {
            cout<<i.num<<" ";
            i.cnt--;
        }
    return 0;
}
