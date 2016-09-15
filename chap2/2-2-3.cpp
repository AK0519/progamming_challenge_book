#include <cstdio>
#include <algorithm>

const int c = 6;
char S[6] = {'A','C','D','B','C','B'};

int main () {
    /* 
    この方法だと比較文字列が同じ時に次の文字列の比較が考慮されていない
    int i = 0;
    int j = c-1;
    int cnt = 0;
    while(cnt != c) {
        if (S[i] < S[j]) {
            printf("%c",S[i++]);
        } else {
            printf("%c",S[j--]);
        }
        cnt++;
    }
    printf("\n");
    */
    
    int i = 0;
    int j = c-1;
    bool flag = false;
    while(i <= j) {
        for(int k=i; k<j; k++){
            if (S[k] < S[j]) {
                flag = true;
                break;
            } else if(S[k] > S[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            printf("%c",S[i++]);
        } else {
            printf("%c",S[j--]);
        }
    }
    printf("\n");
}
