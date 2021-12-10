#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"



ll* matrix_multiply(ll* A, ll* B, ll m){
    ll* result = (ll*) malloc(4*sizeof(ll*));

    result[0] = (A[0]*B[0] + A[1]*B[2])%m;
    result[1] = (A[0]*B[1] + A[1]*B[3])%m;
    result[2] = (A[2]*B[0] + A[3]*B[2])%m;
    result[3] = (A[2]*B[1] + A[3]*B[3])%m;

    return result;
}

ll* matrix_pow(ll *A, ll b, ll m){

    ll* result = (ll*) malloc(4*sizeof(ll*));
    
    if(b == 0){
        result[0] = 1;
        result[1] = 0;
        result[2] = 0;
        result[3] = 1;
        return result;
    }

    ll* temp_1 = matrix_pow(A, b/2, m);

    if(b%2 == 0){
        //result = matrix_multiply(temp_1, temp_1, m);
        result[0] = (temp_1[0]*temp_1[0] + temp_1[1]*temp_1[2])%m;
        result[1] = (temp_1[0]*temp_1[1] + temp_1[1]*temp_1[3])%m;
        result[2] = (temp_1[2]*temp_1[0] + temp_1[3]*temp_1[2])%m;
        result[3] = (temp_1[2]*temp_1[1] + temp_1[3]*temp_1[3])%m;
    }
    else{
        //result = matrix_multiply(temp_1, temp_1, m);
        result[0] = (temp_1[0]*temp_1[0] + temp_1[1]*temp_1[2])%m;
        result[1] = (temp_1[0]*temp_1[1] + temp_1[1]*temp_1[3])%m;
        result[2] = (temp_1[2]*temp_1[0] + temp_1[3]*temp_1[2])%m;
        result[3] = (temp_1[2]*temp_1[1] + temp_1[3]*temp_1[3])%m;
        ll temp_2[4];
        temp_2[0] = (result[0]+result[1])%m;
        temp_2[1] = result[0]%m;
        temp_2[2] = (result[2]+result[3])%m;
        temp_2[3] = result[2]%m;

        for(int i=0; i<4; i++){
            result[i] = temp_2[i];
        }
    }
    free(temp_1);
    return result;
}




typedef long long ll;
int main() {
    ll n, m;
    scanf("%lld %lld", &n, &m);     // Get n and m
    ll A[4];
    A[0] = 1; A[1] = 1;
    A[2] = 1; A[3] = 0;             // Define what matrix A is
    ll *An = matrix_pow(A, n, m);   // Calculate A^n
    for(int i=0; i<4; i++){
        if(i==2) printf("\n");
        printf("%lld ", An[i]);
    }
    //printf("%lld\n", An[2]);        // Fn = An[2][1]*F1 + An[2][2]*F0 = An[2][1] (F0=0, F1=1)
    return 0;
}
