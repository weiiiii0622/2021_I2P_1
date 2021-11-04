#include <stdio.h>

int main(){
    int T;
    scanf("%d", &T);

    int m, n, t;

    for(int i=0; i<T; i++){
        scanf("%d %d %d", &m, &n, &t);
        char wave[m];

        if(t < n){
            for(int i=0; i<t; i++){
                wave[i] = '^';
            }
            for(int i=t; i<m; i++){
                wave[i] = '-';
            }
        }
        else if((t-n+1) <= m){
            for(int i=0; i<(t-n); i++){
                wave[i] = '-';
            }
            if(t<=m){
                for(int i=(t-n); i<t; i++){
                    wave[i] = '^';
                }
                for(int i=t; i<m; i++){
                    wave[i] = '-';
                }
            }
            else{
                for(int i=(t-n); i<m; i++){
                    wave[i] = '^';
                }
            }

        }
        else{
            for(int i=0; i<m; i++){
                wave[i] = '-';
            }
        }

        for(int k=0; k<m; k++){
            printf("%c", wave[k]);
        }
        printf("\n");

    }

    return 0;
}