//
//  C1_3_MRAVOJED(BOJ2967).cpp
//  COCI2008
//
//  Created by 김성환 on 10/10/2018.
//  Copyright © 2018 김성환. All rights reserved.
//

#include <cstdio>
int R,C,ans[2][3],cnt;
char map[101][101];

int getSize(int r, int c) {
    int size=1;
    while(++size) {
        if(r+size-1>R || c+size-1>C) break;
        int sw=0;
        for(int i=0;i<size;i++)
            if(map[r+size-1][c+i]=='.') sw=1;
        for(int i=0;i<size-1;i++)
            if(map[r+i][c+size-1]=='.') sw=1;
        if(sw) break;
    }
    for(int i=r;i<r+size-1;i++)
        for(int j=c;j<c+size-1;j++)
            map[i][j]='.';
    return size-1;
}

int main() {
    scanf("%d%d",&R,&C);
    for(int i=1;i<=R;i++) scanf("%s",map[i]+1);
    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++)
            if(map[i][j]=='x') {
                ans[cnt][0]=i; ans[cnt][1]=j; ans[cnt++][2]=getSize(i,j);
            }
    if(ans[1][0]==0) {
        ans[1][0]=ans[0][0]; ans[1][1]=ans[0][1]; ans[1][2]=1;
    }
    for(int i=0;i<2;i++) printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
    return 0;
}
