#include <bits/stdc++.h>
using namespace std;
int n, ca[110], cb[110], ta[110], tb[110];
int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        ca[a]++; cb[b]++;
        for(int j=1; j<=100; j++) {
            ta[j] = ca[j];
            tb[j] = cb[j];
        }
        int j=1, k=100, res = 0;
        while(j<=100 && k>=1) {
            int mn = min(ta[j], tb[k]);
            if(mn > 0) res = max(res, j + k);
            ta[j] -= mn; tb[k] -= mn;
            while(!ta[j] && j<=100) j++;
            while(!tb[k] && k>=1) k--;
        }
        printf("%d\n", res);
    }
    return 0;
}
