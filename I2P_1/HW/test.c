#include<stdio.h>
#include<stdlib.h>

unsigned**** new_4d_array(unsigned n,unsigned m,unsigned k,unsigned l){
    unsigned**** ln;
    unsigned*** lm;
    unsigned** lk;
    unsigned* ll;

    ln = (unsigned****) malloc(n*sizeof(unsigned***));
    lm = (unsigned***) malloc(n*m*sizeof(unsigned**));
    lk = (unsigned**) malloc(n*m*k*sizeof(unsigned*));
    ll = (unsigned*) malloc(n*m*k*l*sizeof(unsigned));

    for(int i=0; i<n; i++){
        ln[i] = lm + i*m;
        for(int j=0; j<m; j++){
            lm[i*m+j] = lk + (i*m+j)*k;
            for(int t=0; t<k; t++){
                lk[(i*m+j)*k+t] = ll + ((i*m+j)*k+t)*l;
            }
        }
    }

    return ln;
}


int main(){
	int n,m,k,l;
	scanf("%d%d%d%d",&n,&m,&k,&l);
    unsigned ****arr=new_4d_array(n,m,k,l);
    int i,j,q,p,count=0;
    for(i=0;i<n;++i){
        for(j=0;j<m;++j){
            for(q=0;q<k;++q){
                for(p=0;p<l;p++){
                    arr[i][j][q][p]=count;
                    count++;
                }
            }
        }
    }

    for(i=0;i<n;++i){
        for(j=0;j<m;++j){
            for(q=0;q<k;++q){
                for(p=0;p<l;p++){
                    printf("%3u ", arr[i][j][q][p]);
                }
                printf("\n");
            }
            printf("\n");
        }
        printf("\n");
    }

	return 0;
}