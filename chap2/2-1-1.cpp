#include <cstdio>
#include <algorithm>

int n = 4;
int k = 13;
int a[4] = {1,2,4,7};

bool dfs (int m, int sum) {
    
    if (m == n) return k == sum;

    if( dfs(m+1,sum) ) return true;

    if( dfs(m+1,sum+a[m]) ) return true;

    return false;
}

int main() {
    if (dfs(0,0) == true) {
        printf("true\n");
    } else {
        printf("false\n");
    }
}

