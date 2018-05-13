#include <stdio.h>

int main(){
    int tc;
    scanf("%d", &tc);
    int k;
    for(k=1; k<=tc; k++){
	int i, j, sum=0;
	scanf("%d\n%d", &i, &j);
	for(;i<=j ; i++){
	    if(i%2)
		sum+=i;		
	}
	printf("Case %d: %d\n", k, sum);
    }
    return 0;
}
