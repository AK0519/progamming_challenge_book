#include <cstdio>
#include <algorithm>

const int N = 6;
const int R = 10;
int X[6] = {1,7,15,20,30,50};

int main () {
    int cnt = 0;
    int pivot = 0;
    int i = 1;

    std::sort(X,X+N);
    
    while(i < N) {
        if(X[i] > R) {
            pivot = X[i-1];
            cnt++;
            break;
        }
        i++;
    }
    
    printf("%d ",pivot);
    while(i < N) {
        if (i < N && pivot+R < X[i]) {
            cnt++;
            pivot = X[i];
            printf("%d ",pivot);
        }
        i++;
    }
    printf("cnt=%d\n",cnt);
}
