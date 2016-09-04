#include <algorithm>
#include <iostream>
#include <cstdio>

int n=10,m=410,k[10]={10,20,30,40,50,60,70,80,90,100};
int kk[100];

bool binary_search (int x) {
    int j=0,l=100;
    while(l-j>0) {
        int pivot = (j+l)/2;
        if(kk[pivot] == x) {
            return true;
        } else if(kk[pivot] > x) {
            l = pivot;
        } else {
            j = pivot+1;
        }
    }
    return false;
}

void solve() {
    
    //直積集合 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            kk[i+j] = k[i]+k[j];
        }
    }
    std::sort(kk, kk+100);
   
    bool f = false;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (binary_search(m-k[i]+k[j])) {
                printf("true\n");
                return;
            }
        }
    }
    printf("false\n");
    return;
}

int main() {
    solve();
    return 0;
}

