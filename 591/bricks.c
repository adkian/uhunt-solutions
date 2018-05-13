#include <stdio.h>

int main(){
    int n, j=0;
    scanf("%d", &n);
    while(n>0){
	j++;
	int heights[100], avg, sum=0, i, moves=0, move, h;
	for(i=0; i<n; i++){
	    scanf("%d", &h);
	    sum+=h;
	    heights[i]=h;
	}
	avg = sum/n;
	for(i=0; i<n; i++){
	    move = avg-heights[i];
	    moves += (move < 0 ? move*-1 : move);
	}
	printf("Set #%d\nThe minimum number of moves is %d.\n\n", j, moves/2);
	scanf("%d", &n);
    }
    return 0;    
}
