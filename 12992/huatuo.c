#include <stdio.h>

int main(){
    int n, j=0;
    scanf("%d", &n);
    while(n--){
	j++;
	int b;	
	scanf("%d", &b);
	printf("Case #%d: %d\n", j, b*2-1);
    }
}
