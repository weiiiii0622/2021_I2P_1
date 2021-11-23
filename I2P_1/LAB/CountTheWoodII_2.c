#include<stdio.h>
#define MAX(a, b) a = (a>b?a:b)
int t,n,m,ans[2],cnt;
char c[1005][1005];
void main(){
	scanf("%d\n",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		ans[0] = ans[1] = 0;
		for(int i=0;i<n;i++){
			scanf("%s",c[i]);
		} 
		for(int i=0;i<n;i++)                           //each row
			for(int j=0;j<m;j++){
				if(j==0 || c[i][j]!=c[i][j-1])
					cnt = 1;
				else
					cnt++; 
				MAX(ans[c[i][j]=='#'], cnt);
			}
		for(int j=0;j<m;j++)                           //each column
			for(int i=0;i<n;i++){
				if(i==0 || c[i][j]!=c[i-1][j])
					cnt = 1;
				else
					cnt++; 
				MAX(ans[c[i][j]=='#'], cnt);
			}
        for(int i=0;i<n;i++)                           //lower left corner
            for(int k=0;i+k<n && k<m;k++){
                printf("%d %d\n", i+k, i);
                if(k==0 || c[i+k][k]!=c[i+k-1][k-1])

                    cnt = 1;
                else
                    cnt++; 
                MAX(ans[c[i+k][k]=='#'], cnt);
            }
		for(int j=0;j<m;j++)                           //upper right corner
			for(int k=0;k<n && j+k<m;k++){
				if(k==0 || c[k][j+k]!=c[k-1][j+k-1])
					cnt = 1;
				else
					cnt++; 
				MAX(ans[c[k][j+k]=='#'], cnt);
			}
		for(int j=0;j<m;j++)                           //upper left corner
			for(int k=0;k<n && j-k>=0;k++){
				if(k==0 || c[k][j-k]!=c[k-1][j-k+1])
					cnt = 1;
				else
					cnt++; 
				MAX(ans[c[k][j-k]=='#'], cnt);
			}
		for(int i=0;i<n;i++)                           //down right corner
			for(int k=0;i+k<n && m-1-k>=0;k++){
				if(k==0 || c[i+k][m-1-k]!=c[i+k-1][m-k])
					cnt = 1;
				else
					cnt++; 
				MAX(ans[c[i+k][m-1-k]=='#'], cnt);
			}
		printf("%d %d\n",ans[0],ans[1]);
	}
}