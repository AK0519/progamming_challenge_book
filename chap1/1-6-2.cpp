#include <algorithm>
#include <iostream>
#include <cstdio>

int L=10,n=3,a[3]={2,6,7};
//int L=20,n=5,a[5]={2,6,7,10,11};

void solve() {
    int ans_min = 0;
    int ans_max = 0;
    
    for (int i=0; i<n; i++) {
        int min_pos = a[i] < L/2 ? a[i]:L-a[i];
        int max_pos = a[i] > L/2 ? a[i]:L-a[i];
        ans_min = std::max(ans_min, min_pos);
        ans_max = std::max(ans_max, max_pos);
    }
    printf("min=%d,max=%d\n",ans_min, ans_max);
}

int main() {
    solve();
    return 0;
}

