#include <stdio.h>

int main(){

    int T;
    scanf("%d", &T);

    for(int a=0; a<T; a++){

        int count_o = 0, count_sharp = 0, max_o = 0, max_sharp = 0;

        int n, m;
        scanf("%d %d", &n, &m);

        char woods[n+1][m+1];
        for(int i=0; i<n; i++){
            scanf("%s", &woods[i]);
        }

        for(int i=0; i<n; i++){
            int j=0;
            while(j < m){
                if(woods[i][j] == 'o'){
                    for(count_o=0; (j+count_o)<m && woods[i][j+count_o] == 'o'; count_o++);
                    if(count_o > max_o){
                        max_o = count_o;
                    }
                    j += count_o;
                }
                else{
                    for(count_sharp=0; (j+count_sharp)<m && woods[i][j+count_sharp] == '#'; count_sharp++);
                    if(count_sharp > max_sharp){
                        max_sharp = count_sharp;
                    }
                    j += count_sharp;
                }
            }
        }

        for(int j=0; j<m; j++){
            int i=0;
            while(i < n){
                if(woods[i][j] == 'o'){
                    for(count_o=0; (i+count_o)<n && woods[i+count_o][j] == 'o'; count_o++);
                    if(count_o > max_o){
                        max_o = count_o;
                    }
                    i += count_o;
                }
                else{
                    for(count_sharp=0; (i+count_sharp)<n && woods[i+count_sharp][j] == '#'; count_sharp++);
                    if(count_sharp > max_sharp){
                        max_sharp = count_sharp;
                    }
                    i += count_sharp;
                }
            }
        }

        for(int i=0; i<n; i++){
            int temp_i = i, temp_j = 0;
            while(temp_i < n && temp_j < m){

                if(woods[temp_i][temp_j] == 'o'){
                    for(count_o=0; (temp_i+count_o)<n && (temp_j+count_o)<m && woods[temp_i+count_o][temp_j+count_o] == 'o'; count_o++);
                    if(count_o > max_o){
                        max_o = count_o;
                    }

                    temp_i += count_o;
                    temp_j += count_o;
                }
                else{
                    for(count_sharp=0; (temp_i+count_sharp)<n && (temp_j+count_sharp)<m && woods[temp_i+count_sharp][temp_j+count_sharp] == '#'; count_sharp++);
                    if(count_sharp > max_sharp){
                        max_sharp = count_sharp;
                    }

                    temp_i += count_sharp;
                    temp_j += count_sharp;
                }
            }

            temp_i = i;
            temp_j = m-1;

            while(temp_i < n && temp_j >= 0){

                if(woods[temp_i][temp_j] == 'o'){
                    for(count_o=0; (temp_i+count_o)<n && (temp_j-count_o)>=0 && woods[temp_i+count_o][temp_j-count_o] == 'o'; count_o++);
                    if(count_o > max_o){
                        max_o = count_o;
                    }

                    temp_i += count_o;
                    temp_j -= count_o;
                }
                else{
                    for(count_sharp=0; (temp_i+count_sharp)<n && (temp_j+count_sharp)>=0 && woods[temp_i+count_sharp][temp_j-count_sharp] == '#'; count_sharp++);
                    if(count_sharp > max_sharp){
                        max_sharp = count_sharp;
                    }

                    temp_i += count_sharp;
                    temp_j -= count_sharp;
                }
            }
        }

        for(int j=0; j<m; j++){
            int temp_i = 0, temp_j = j;
            while(temp_i < n && temp_j < m){

                if(woods[temp_i][temp_j] == 'o'){
                    for(count_o=0; (temp_i+count_o)<n && (temp_j+count_o)<m && woods[temp_i+count_o][temp_j+count_o] == 'o'; count_o++);
                    if(count_o > max_o){
                        max_o = count_o;
                    }

                    temp_i += count_o;
                    temp_j += count_o;
                }
                else{
                    for(count_sharp=0; (temp_i+count_sharp)<n && (temp_j+count_sharp)<m && woods[temp_i+count_sharp][temp_j+count_sharp] == '#'; count_sharp++);
                    if(count_sharp > max_sharp){
                        max_sharp = count_sharp;
                    }

                    temp_i += count_sharp;
                    temp_j += count_sharp;
                }
            }

            temp_i = 0;
            temp_j = j;

            while(temp_i < n && temp_j >= 0){

                if(woods[temp_i][temp_j] == 'o'){
                    for(count_o=0; (temp_i+count_o)<n && (temp_j-count_o)>=0 && woods[temp_i+count_o][temp_j-count_o] == 'o'; count_o++);
                    if(count_o > max_o){
                        max_o = count_o;
                    }

                    temp_i += count_o;
                    temp_j -= count_o;
                }
                else{
                    for(count_sharp=0; (temp_i+count_sharp)<n && (temp_j+count_sharp)>=0 && woods[temp_i+count_sharp][temp_j-count_sharp] == '#'; count_sharp++);
                    if(count_sharp > max_sharp){
                        max_sharp = count_sharp;
                    }

                    temp_i += count_sharp;
                    temp_j -= count_sharp;
                }

            }
        }

        printf("%d %d\n", max_o, max_sharp);
    }

    return 0;
}