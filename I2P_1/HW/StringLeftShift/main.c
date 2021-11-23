#include <stdio.h>
#include "function.h"

void shift(char* start, char* end){
    char temp = *start;
    int i=0;
    while(start+i < end){
        *(start+i) = *(start+i+1);
		i++;
    }
    *end = temp;
}

int main(){
	char str[111];
	int n,l,r;
	scanf("%s",str);
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&l,&r);
		shift(&str[l-1], &str[r-1]);
	}
	printf("%s\n",str);

	return 0;
}