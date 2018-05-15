#include <stdio.h>

/*
    
 */

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
	int i, f, e, a, b, x[100]={0}, y[100]={0};
	scanf("%d %d %d %d", &f, &e, &a, &b);
	
	for(i=0; i<e; i++)
	    scanf("%d %d", &x[i], &y[i]);

	int elev, found = 0;

	if(found==1)
	    printf("It is possible to move the furniture.\n");
	else
	    printf("The furniture cannot be moved.\n");
    }
    return 0;
}
