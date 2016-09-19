#include <cstdio>
#include <algorithm>

typedef long l;
const int N = 5;
int L[N] = {8,5,8,1,16};

int main () {
    std::sort(L,L+N);
    int ans = 0;
    int w = 0;
    int cl = 0;

    while(w < N-1) {
        int t1 = w;
        int t2 = w+1;

        int cost = L[t1]+L[t2];
        ans += cost;
        L[t2] = cost;
        w++;
    }

    printf("%d\n",ans);
}
