#include <stdio.h>
int x[100000];
int y[100000];
int pasTri[101][101];
#define PRIME 10007

int main()
{

    for (int i = 0; i <= 100; i++){
        for (int j = 0; j <= i; j++){
            if (j == 0 || j == i) pasTri[i][j] = 1;
            else pasTri[i][j] = (pasTri[i - 1][j] + pasTri[i - 1][j - 1]) % PRIME;
        }
    }

    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &(x[i]));
    for (int i = 0; i < N; i++)
        scanf("%d", &(y[i]));

    int res = 1;
    for (int i = 0; i < N; i++){
        res = (res * pasTri[x[i]][y[i]]) % PRIME;
    }
    printf("%d\n", res);
    return 0;
}
