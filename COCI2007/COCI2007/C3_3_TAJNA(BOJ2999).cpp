//
//  C3_3_TAJNA(BOJ2999).cpp
//  COCI2007
//
//  Created by 김성환 on 04/10/2018.
//  Copyright © 2018 김성환. All rights reserved.
//
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string text;
int r,c;

int main() {
    cin>>text;
    int sq = (int)sqrt(text.size());
    for(int i=sq;i>=1;i--)
        if((int)text.size()%i==0) {r=i;c=(int)text.size()/r;break;}
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cout<<text.at(i+r*j);
        }
    }
    return 0;
}
