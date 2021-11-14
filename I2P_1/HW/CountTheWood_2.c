#include <stdio.h>

int main(void){

    
    char wood[1001][1001];
    
    int T;
    scanf("%d", &T);

    for(int a=0; a<T; a++){
        int count_o = 0, count_sharp = 0, MAX_O = 0, MAX_sharp = 0;
        int N, M;
        scanf("%d %d", &N, &M);

        for(int i=0; i<N; i++){
            scanf("%s", &wood[i]);
        }

        for(int i=0; i<N; i++){
            int j=0;
            while(j < M){
                if(wood[i][j] == 'o'){
                    for(count_o=0; (j+count_o)<M && wood[i][j+count_o]=='o'; count_o++);
                    if(count_o > MAX_O){
                        MAX_O = count_o;
                    }
                    j += count_o;
                }
                else{
                    for(count_sharp=0; (j+count_sharp)<M && wood[i][j+count_sharp]=='#'; count_sharp++);
                    if(count_sharp > MAX_sharp){
                        MAX_sharp = count_sharp;
                    }
                    j += count_sharp;
                }
            }
        }

        for(int j=0; j<M; j++){
            int i=0;
            while(i < N){
                if(wood[i][j] == 'o'){
                    for(count_o=0; (i+count_o)<N && wood[i+count_o][j]=='o'; count_o++);
                    if(count_o > MAX_O){
                        MAX_O = count_o;
                    }
                    i += count_o;
                }
                else{
                    for(count_sharp=0; (i+count_sharp)<N && wood[i+count_sharp][j]=='#'; count_sharp++);
                    if(count_sharp > MAX_sharp){
                        MAX_sharp = count_sharp;
                    }
                    i += count_sharp;
                }
            }
        }

        printf("%d %d\n", MAX_O, MAX_sharp);
    }

    return 0;
}