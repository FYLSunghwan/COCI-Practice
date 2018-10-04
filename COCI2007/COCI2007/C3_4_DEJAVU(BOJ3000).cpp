//
//  C3_4_DEJAVU(BOJ3000).cpp
//  COCI2007
//
//  Created by 김성환 on 04/10/2018.
//  Copyright © 2018 김성환. All rights reserved.
//
//공식 해설 (freq(x)-1) * (freq(y)-1)
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

vector<pair<int,int>> cord;

int frx[100001],fry[100001];
int x,y,n;
ll ans;
int main() {
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>x>>y;
        frx[x]++;
        fry[y]++;
        cord.push_back({x,y});
    }
    for(auto &it:cord)
        ans+=(frx[it.first]-1LL)*(fry[it.second]-1LL);
    cout<<ans;
    return 0;
}
