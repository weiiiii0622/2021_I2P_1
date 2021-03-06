#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

unsigned*** new_3d_array(unsigned n,unsigned m,unsigned k){
    unsigned ***ln = (unsigned***) malloc(n*sizeof(unsigned**));
    unsigned **lm = (unsigned**) malloc(n*m*sizeof(unsigned*));
    unsigned *lk = (unsigned*) malloc(n*m*k*sizeof(unsigned));

    for(int i=0; i<n; i++){
        ln[i] = lm+m*i;
        for(int j=0; j<m; j++){
            lm[m*i+j] = lk+(m*i+j)*k;
        }
    }

    return ln;
}

unsigned*** new_4d_array(unsigned n,unsigned m,unsigned k,unsigned l){
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


void delete_3d_array(unsigned ***arr){
    free(arr[0][0]);
    free(arr[0]);
    free(arr);
}

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