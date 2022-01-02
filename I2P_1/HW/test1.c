#include <stdio.h>

int main(){

	printf("%d\n", (((20*20)^901)+901*901)%1000+1);

	return 0;
}