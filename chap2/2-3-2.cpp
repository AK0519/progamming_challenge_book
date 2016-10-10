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

const int N = 4;
const int W = 4;
int lcs[N+1][W+1];
char s[N] = {'a','b','c','d'};
char t[W] = {'b','e','c','d'};

int dp(int i, int j) {
    int res;
    for(int i=0; i<N; i++) {
        for(int j=0; j<W; j++) {
            if (s[i] == t[j]) {
                lcs[i+1][j+1] = lcs[i][j]+1;
            } else {
                lcs[i+1][j+1] = std::max(lcs[i][j+1],lcs[i+1][j]);
            }
        }
    }
    return lcs[N][W];
}

int main() {
    benchmark {
        memset(lcs,0,sizeof(lcs));
        int value = dp(0,0);
        printf("lcs:%d\n",value);
    }
    return 1;
}
