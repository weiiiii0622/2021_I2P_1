#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

unsigned*** new_3d_array(unsigned n,unsigned m,unsigned k){
    // unsigned*** ln;
    // unsigned** lm;
    // unsigned* lk;

    // ln = (unsigned***) malloc(n*sizeof(unsigned***));
    // lm = (unsigned**) malloc(n*m*sizeof(unsigned**));
    // lk = (unsigned*) malloc(n*m*k*sizeof(unsigned));

    // for(int i=0; i<n; i++){
    //     ln[i] = lm + i*m;
    //     for(int j=0; j<m; j++){
    //         lm[i*m+j] = lk + (i*m+j)*k;
    //     }
    // }

    unsigned*** arr;

    arr=(unsigned ***)malloc(sizeof(unsigned **) * n);
    for(int i=0;i<n;i++){
        arr[i]=(unsigned **)malloc(sizeof(unsigned*) * m);
        for(int j=0;j<m;j++){
            arr[i][j]=(unsigned *)malloc(sizeof(unsigned) * k);
        }
    }

    return arr;
}


void delete_3d_array(unsigned ***arr){
    free(arr[0][0]);
    free(arr[0]);
    free(arr);
}
