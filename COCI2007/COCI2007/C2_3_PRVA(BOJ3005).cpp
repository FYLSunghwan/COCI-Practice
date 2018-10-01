//
//  C2_3_PRVA(BOJ3005).cpp
//  COCI2007
//
//  Created by 김성환 on 01/10/2018.
//  Copyright © 2018 김성환. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char map[21][21],tmp[21];
vector<string> ans;
string tmp2;
int r,c;

int main() {
    cin>>r>>c;
    for(int i=0;i<r;i++) scanf("%s",map[i]);
    //가로
    for(int i=0;i<r;i++) {
        int cnt=0,lastpos=0;
        for(int j=0;j<c;j++) {
            if(map[i][j]=='#') {
                if(cnt>1) {
                    int iter=0;
                    for(int k=lastpos;k<j;k++) tmp[iter++]=map[i][k];
                    tmp[iter]='\0';
                    tmp2=tmp;
                    ans.push_back(tmp2);
                    cnt=0;
                    lastpos=j+1;
                }
                else {
                    cnt=0;
                    lastpos=j+1;
                }
            }
            else ++cnt;
        }
        if(cnt>1) {
            int iter=0;
            for(int k=lastpos;k<c;k++) tmp[iter++]=map[i][k];
            tmp[iter]='\0';
            tmp2=tmp;
            ans.push_back(tmp2);
        }
    }
    //세로
    for(int i=0;i<c;i++) {
        int cnt=0,lastpos=0;
        for(int j=0;j<r;j++) {
            if(map[j][i]=='#') {
                if(cnt>1) {
                    int iter=0;
                    for(int k=lastpos;k<j;k++) tmp[iter++]=map[k][i];
                    tmp[iter]='\0';
                    tmp2=tmp;
                    ans.push_back(tmp2);
                    cnt=0;
                    lastpos=j+1;
                }
                else {
                    cnt=0;
                    lastpos=j+1;
                }
            }
            else ++cnt;
        }
        if(cnt>1) {
            int iter=0;
            for(int k=lastpos;k<r;k++) tmp[iter++]=map[k][i];
            tmp[iter]='\0';
            tmp2=tmp;
            ans.push_back(tmp2);
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.front();
    return 0;
}
