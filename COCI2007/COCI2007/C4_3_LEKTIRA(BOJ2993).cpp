//
//  C4_3_LEKTIRA(BOJ2993).cpp
//  COCI2007
//
//  Created by 김성환 on 04/10/2018.
//  Copyright © 2018 김성환. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string src,f,m,b,n,mi;
int main() {
    cin>>src;
    mi=src;
    for(int i=0;i<src.size()-2;i++) {
        for(int j=i+1;j<src.size()-1;j++) {
            f=src.substr(0,i+1);
            m=src.substr(i+1,j-i);
            b=src.substr(j+1,src.size()-j-1);
            reverse(f.begin(),f.end());
            reverse(m.begin(),m.end());
            reverse(b.begin(),b.end());
            n=f+m+b;
            if(n.compare(mi)<0) mi=n;
        }
    }
    cout<<mi;
    return 0;
}
