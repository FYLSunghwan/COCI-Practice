//
//  main.cpp
//  COCI2009
//
//  Created by 김성환 on 26/10/2018.
//  Copyright © 2018 김성환. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

char data[102];
long long int cache[101][2][101][2];

bool isVowel(char c) {return c=='A'||c=='E'||c=='I'||c=='O'||c=='U';}

long long int dp(int pos, int vow, int seq, int isL) {
    long long int& ret = cache[pos][vow][seq][isL];
    if(ret!=-1) return ret;
    if(!data[pos]) return ret=isL;
    ret=0;
    if(data[pos]=='_') {
        if(vow) {
            ret+=20*dp(pos+1,0,1,isL)+dp(pos+1,0,1,1);
            if(seq<2) ret+=5*dp(pos+1,1,seq+1,isL);
        }
        else {
            ret+=5*dp(pos+1,1,1,isL);
            if(seq<2) ret+=20*dp(pos+1,0,seq+1,isL)+dp(pos+1,0,seq+1,1);
        }
    }
    else {
        if(data[pos]=='L') isL=1;
        if(isVowel(data[pos])) {
            if(!vow) ret+=dp(pos+1,1,1,isL);
            else if(seq<2) ret+=dp(pos+1,1,seq+1,isL);
        }
        else {
            if(vow) ret+=dp(pos+1,0,1,isL);
            else if(seq<2) ret+=dp(pos+1,0,seq+1,isL);
        }
    }
    return ret;
}

int main() {
    cin>>data;
    memset(cache,-1,sizeof(cache));
    cout<<dp(0,0,0,0);
    return 0;
}
