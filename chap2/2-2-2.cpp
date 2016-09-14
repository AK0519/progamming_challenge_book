#include <cstdio>
#include <algorithm>

const int c = 5;
int start[5] = {1,2,4,6,8};
int stop[5] = {3,5,7,9,10};

int main () {
    int work = 0;
    int end = 0;
    int i = 0;
    while (i < c) {
        if (end <= start[i]) {
            work++;
            end = stop[i];
        }
        i++;
    }
    printf("仕事は%dつ\n",work);
    return 0;
}
