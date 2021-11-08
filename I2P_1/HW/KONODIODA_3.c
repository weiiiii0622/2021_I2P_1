#include <stdio.h>
#include <stdlib.h>

int main(){

    int T, n;
    scanf("%d", &T);
    scanf("%d", &n);
    
    //int A[n][n];
    for(int t=0;t<T;t++)
    {
        int D[2 * 2048 - 1][2] = {0}, R[2048] = {0}, C[2048] = {0}; 
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                int input; //A[i][j]只會在這裡用到故用input取代之
                scanf("%d", &input);
                if(input == 255)
                {
                    R[j]++; //A[x][j]為255的數量
                    C[i]++; //A[i][x]為255的數量
                    D[i - j + (n - 1)][0]++; //左上右下的對角線
                    D[i + j][1]++; //左下右上的對角線
                }
            }
        }
        int ans = 0;
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                int IsCenter = 0;
                if(R[j] == n)
                    IsCenter++;
                if(C[i] == n)
                    IsCenter++;
                int R_diagonal = D[i - j + (n - 1)][0];
                if(R_diagonal == n - abs(i - j))
                    IsCenter++;
                int L_diagonal = D[i + j][1];
                if(L_diagonal == n - abs((i + j) - (n - 1)))
                    IsCenter++;
                
                if(IsCenter == 4)
                {
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;  
}