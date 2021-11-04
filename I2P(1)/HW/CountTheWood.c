#include <stdio.h>

int check_right(int, int, char x);
int check_down(int, int, char x);

char woods[1001][1001];
int n, m;

int main(){
    int T;
    scanf("%d", &T);

    for(int a=0; a<T; a++){
        int o_max = 0, sharp_max = 0;
        scanf("%d %d", &n, &m);

        for(int i=0; i<n; i++){
            scanf("%s", woods[i]);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(woods[i][j] == 'o'){
                    int x, y;
                    x = check_right(i, j, 'o');
                    y = check_down(i, j, 'o');

                    if(x >= y){
                        if(x > o_max){
                            o_max = x;
                        }
                    }
                    else{
                        if(y > o_max){
                            o_max = y;
                        }
                    }
                }
                else{
                    int x, y;
                    x = check_right(i, j, '#');
                    y = check_down(i, j, '#');

                    if(x >= y){
                        if(x > sharp_max){
                            sharp_max = x;
                        }
                    }
                    else{
                        if(y > sharp_max){
                            sharp_max = y;
                        }
                    }
                }
            }
        }
        printf("%d %d\n", o_max, sharp_max);
    }

    return 0;
}

int check_right(int i, int j, char x){
    int count = 1;
    if(j == 0 && j != m-1){
        j++;

        while(woods[i][j] == x){
            count++;
            if(j < (m-1)){
                j++;
            }
            else{
                break;
            }
        }
        return count;
    }
    else if(j == m-1){
        return 1;
    }
    else{
        if(woods[i][j-1] == x){
            return 1;
        }
        else{
            j++;

            while(woods[i][j] == x){
                count++;
                if(j < (m-1)){
                    j++;
                }
                else{
                    break;
                }
            }
            return count;
        }
    }
}

int check_down(int i, int j, char x){
    int count = 1;
    if(i == 0 && i != n-1){
        i++;
        
        while(woods[i][j] == x){
            count++;
            if(i < (n-1)){
                i++;
            }
            else{
                break;
            }
        }
        return count;
    }
    else if(i == n-1){
        return 1;
    }
    else{
        if(woods[i-1][j] == x){
            return 1;
        }
        else{
            i++;
            
            while(woods[i][j] == x){
                count++;
                if(i < (n-1)){
                    i++;
                }
                else{
                    break;
                }
            }
            return count;
        }
    }
}