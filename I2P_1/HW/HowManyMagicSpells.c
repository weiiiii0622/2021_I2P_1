#include<stdio.h>
#include<string.h>
int t,q,l,r,ans[2005][2005],la,lb;
char a[2005],b[2005];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%s%s%d",a,b,&q);
        la = strlen(a), lb = strlen(b);
        for(int i=0;i<la;i++)
            for(int j=0;j<la;j++)
                ans[i][j] = 0;
        for(int i=0;i<la;i++){
            for(int j=0;j<lb && i+j<la;j++){
                if(a[i+j]!=b[j]) break;
                ans[i][i+j]++;
            }
        }
        for(int i=la-2;i>=0;i--)
            for(int j=0;j<la;j++){
                ans[i][j] += ans[i+1][j];
            }
                

        while(q--){
            scanf("%d%d",&l,&r);
            printf("%d\n",ans[l][r]+1);
        }
    }
}