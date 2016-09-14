#include <cstdio>
#include <algorithm>

int coin[6] = {1,5,10,50,100,500};
int coin_count[6] = {3,2,1,3,0,2};
int A = 620;

int main () {
    int count = 0;
    for (int i=5; i>=0; i--) {
        //大きい順に支払いの可否を確認する
        int a = std::min(A/coin[i], coin_count[i]);
        A -= a*coin[i];
        count += a;
    }
    printf("%d枚\n",count);
    return 0;
}
