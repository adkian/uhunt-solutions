#include <stdio.h>
#include <stdlib.h>
#define mil 1000000

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    while(n>0 || m>0){
	int i, j, start, end, mult, s, s2, conflict=0, interval;
	unsigned int *bitset;
	bitset = (int*) calloc(mil, sizeof(unsigned int));
	
	for(i=0; i<n && !conflict; i++){
	    scanf("%d %d", &start, &end);
	    if(end-start == 1){
		if(bitset[start] == 1 && bitset[end] == 1)
		    conflict=1;
	    }
	    for(s=start; s<=end && !conflict; s++){
		if(s > start && bitset[s] == 1 && s < end)
		    conflict=1;
		bitset[s]|=1;
	    }
	}
	for(i=0; i<m && !conflict; i++){
	    scanf("%d %d %d", &start, &end, &mult);
	    interval=start-end;
	    for(s=start; s<mil && !conflict; s+=mult){
		for(s2=s; s2<=s+interval; s2++){
		    if(s2>s && s2<(s+interval) && bitset[s2] == 1){
			conflict=1;
			break;
		    }
		    bitset[s2]|=1;
		}
	    }
	}
	if(conflict==1)
	    printf("CONFLICT\n");
	else
	    printf("NO CONFLICT\n");
	free(bitset);
	
	scanf("%d %d", &n, &m);
    }
}
