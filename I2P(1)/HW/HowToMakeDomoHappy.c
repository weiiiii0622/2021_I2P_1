#include <stdio.h>

int main(){

    int len;
    scanf("%d", &len);

    char a[len];
    int A[len], B, ans[len+2], prod, carry=0, end=len;
    
    scanf("%s", &a);
    for(int i=0; i<len; i++){
        A[i] = a[i]-'0';
    }

    scanf("%d", &B);

    int j=0;

    for(int i=len-1; i>=0; i--){
        if(i!=0){
            int x = A[i] * B;
            prod = x % 10 + carry;
            ans[j] = prod%10;
            carry = x/10 + prod/10;
            j++;
        }
        else{
            int x = A[i] * B;
            prod = x % 10 + carry;
            ans[j] = prod%10;
            carry = x/10 + prod/10;
            j++;
            if(carry>10){
                ans[j] = carry%10;
                ans[j+1] = carry/10;
                end += 2;
            }
            else if(carry<10 && carry>0){
                ans[j] = carry;
                end++;
            }
        }
    }

    for(int i=end-1; i>=0; i--){
        printf("%d", ans[i]);
    }

    return 0;
}

