#include <cstdio>
#include <algorithm>
#include <random>
#include <ctime>
#include <queue>

const int N = 10;
const int M = 10;
char meikyu[N][M];
int dist[N][M];
typedef std::pair<int,int> dot;

//init
void init() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++){
            meikyu[i][j] = '.';
        }
    }
    //適当に壁を作る
    srand( (int)time(NULL) );
    for(int i=0; i<30; i++) {
        int a = rand() % N;
        int b = rand() % M;
        meikyu[a][b] = '#';
    }
    int a = rand() % N;
    int b = rand() % M;
    meikyu[a][b] = 'S';
    a = rand() % N;
    b = rand() % M;
    meikyu[a][b] = 'G';
}

int bfs (int i, int j) {
    std::queue< dot > q;
    int step = 0;
    
    //移動パターン
    int x[4] = {-1,0,0,1};
    int y[4] = {0,-1,1,0};
    
    dist[i][j] = 0;
    //Sからの移動パターンをqueueに突っ込む
    for(int s=0; s<4; s++) {
        if (i+x[s] >= 0 && i+x[s] < N && j+y[s] >= 0 && j+y[s] < M) {
            if( meikyu[i+x[s]][j+y[s]] == '.' ) {
                q.push(dot(i+x[s],j+y[s]));
                meikyu[i+x[s]][j+y[s]] = '#';
                dist[i+x[s]][j+y[s]] = 1;
            } else if ( meikyu[i+x[s]][j+y[s]] == 'G') {
                return 1;
            }
        }
    }

    //queueがからになるまで実施
    int cnt = 0;
    while(q.size() != 0) {
        dot p = q.front();
        q.pop();
        for(int s=0; s<4; s++) {
            if (p.first+x[s] >= 0 && p.first+x[s] < N && p.second+y[s] >= 0 && p.second+y[s] < M) {
                int d = dist[p.first][p.second];
                if( meikyu[p.first+x[s]][p.second+y[s]] == '.' ) {
                    q.push(dot(p.first+x[s],p.second+y[s]));
                    meikyu[p.first+x[s]][p.second+y[s]] = '#';
                    if (dist[p.first+x[s]][p.second+y[s]] == 0 || dist[p.first+x[s]][p.second+y[s]] > d+1) {
                        dist[p.first+x[s]][p.second+y[s]] = d+1;
                    }
                } else if ( meikyu[p.first+x[s]][p.second+y[s]]  == 'G') {
                    if ( step == 0 || step > d+1) {
                        step = d+1;
                    }
                }
            }
        }
    }
    return step;
}

int main() {
    int result = 0;

    init();
    printf("今回の迷宮\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++){
            printf("%c",meikyu[i][j]);
        }
        printf("\n");
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if(meikyu[i][j] == 'S') {
                result = bfs(i,j);
                break;
            }
        }
    }

    printf("dist\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++){
            printf("%d\t",dist[i][j]);
        }
        printf("\n");
    }

    if (result > 0) {
        printf("最短%dステップで脱出できます\n",result);
    } else {
        printf("迷宮からは出られません");
    }
    return 0;
}

