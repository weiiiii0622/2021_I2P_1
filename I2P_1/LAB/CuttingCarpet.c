#include <stdio.h>
#include <limits.h>

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    int carpet[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &carpet[i][j]);
        }
    }

    int max = INT_MIN, cur = 0;
    
    if(m >= n){
        for(int a=1; a<=n; a++){
            for(int i=0; i<=n-a; i++){
                for(int j=0; j<m; j++){

                    for(int k=0; k<a; k++){
                        cur += carpet[i+k][j];
                    }

                    if(cur > max){
                        max = cur;
                    }
                    if(cur < 0){
                        cur = 0;
                    }
                }
                cur = 0;
            }
        }        
    }
    else{
        for(int a=1; a<=m; a++){
            for(int i=0; i<=m-a; i++){
                for(int j=0; j<n; j++){

                    for(int k=0; k<a; k++){
                        cur += carpet[j][i+k];
                    }

                    if(cur > max){
                        max = cur;
                    }
                    if(cur < 0){
                        cur = 0;
                    }
                }
                cur = 0;
            }
        }
    }
    printf("%d\n", max);
    return 0;
}