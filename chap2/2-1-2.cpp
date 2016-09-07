#include <cstdio>
#include <algorithm>
#include <random>
#include <ctime>

const int N = 10;
const int M = 10;
char garden[N][M];

//init
void init() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++){
            garden[i][j] = '.';
        }
    }
    srand( (int)time(NULL) );
    for(int i=0; i<10; i++) {
        int a = rand() % N;
        int b = rand() % M;
        garden[a][b] = 'W';
    }
}

void dfs (int i, int j) {
    for (int x=-1; x<=1; x++) {
        for (int y=-1; y<=1; y++) {
            if (i+x >= 0 && i+x < N && j+y >= 0 && j+y < M && garden[i+x][j+y] == 'W') {
                garden[i+x][j+y] = '.';
                dfs(i+x,j+y);
            }
        }
    }
}

int main() {
    init();
    printf("水たまり\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++){
            printf("%c",garden[i][j]);
        }
        printf("\n");
    }

    int count = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++){
            if (garden[i][j] == 'W') {
                dfs(i,j);
                count++;
            }
        }
    }
    printf("count:%d\n",count);
    return 0;
}

