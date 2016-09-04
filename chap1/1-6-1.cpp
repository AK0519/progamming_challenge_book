#include <algorithm>
#include <iostream>
#include <cstdio>

int n=10,a[10]={1,2,3,4,5,6,7,8,9,10};

void solve() {
    int ans = 0;
    
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            for (int k=j+1; k<n; k++) {
                //三角形の長さ
                int len = a[i] + a[j] + a[k];
                //最大の辺を獲得
                int ma = std::max(a[i], std::max(a[j],a[k]));
                //残りの2辺の和
                int rest = len - ma;

                if(ma < rest) {
                    //三角形を作れる
                    ans = std::max(ans, len);
                }
            }
        }
    }
    printf("%d\n",ans);
}

int main() {
    solve();
    return 0;
}

