#include <cstdio>
#include <sys/time.h>
#include <algorithm>

struct __bench__ {
  double start;
  __bench__() {
    start = sec();
  }
  ~__bench__() {
    fprintf(stderr, "%.6f sec\n", sec() - start); 
  }
  double sec() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec * 1e-6;
  }
  operator bool() { return false; }
};
#define benchmark if ( __bench__ __b__ = __bench__()); else

const int N = 10;
const int W = 8;
int w[N] = {2,1,3,2,3,2,4,3,1,2};
int v[N] = {3,2,4,2,5,4,3,2,1,1};
int memory[N+1][W+1];

int naive(int i, int j) {
    int res;
    if (i == N) {
        res = 0;
    } else if (j < w[i]) {
        res = naive(i+1,j);
    } else {
        res = std::max(naive(i+1,j), naive(i+1,j-w[i])+v[i]);
    }
    return res;    
}

int dp(int i, int j) {
    int res;
    if(memory[i][j] > -1) {
        return memory[i][j];
    }
    if (i == N) {
        res = 0;
    } else if (j < w[i]) {
        res = dp(i+1,j);
    } else {
        res = std::max(dp(i+1,j), dp(i+1,j-w[i])+v[i]);
    }
    return memory[i][j] = res;
}

int dp2() {
    for(int i=N-1; i>=0; i--) {
        for(int j=0; j<=W; j++) {
            if(j < w[i]) {
                memory[i][j] = memory[i+1][j];
            } else {
                memory[i][j] = std::max(memory[i+1][j],memory[i+1][j-w[i]]+v[i]); 
            }
        }
    }
    return memory[0][W];
}

int main() {
    printf("naive method\n");
    benchmark {
        int value = naive(0,W);
        printf("value:%d\n",value);
    }   
    printf("dp method\n");
    benchmark {
        /*
        for(int i=0; i<=N; i++) {
            for(int j=0; j<=W; j++) {
                memory[i][j] = -1;
            }
        }
        */
        memset(memory,-1,sizeof(memory));
        int value = dp(0,W);
        printf("value:%d\n",value);
    }
    printf("dp2 method\n");
    benchmark {
        /*
        for(int i=0; i<=N; i++) {
            for(int j=0; j<=W; j++) {
                memory[i][j] = 0;
            }
        }
        */
        memset(memory,0,sizeof(memory));
        int value = dp2();
        printf("value:%d\n",value);
    }
    return 1;
}
