#include <stdio.h>

int main(){
    int s, r;
    scanf("%d %d", &s, &r);
    while(s>0){

	int left, right, i;
	int gapsl[100000], gapsr[100000], gap_index=0;	
	
	while(r--){
	    int left_seek, right_seek, curr_gapindex;
	    
	    scanf("%d %d", &left, &right);

	    left--; right--; /* adjust for 0 index */
	    
	    curr_gapindex = gap_index++;	    
	    gapsl[curr_gapindex]=left;
	    gapsr[curr_gapindex]=right;

	    left_seek=left-1;
	    right_seek=right+1;
	    
	    int gap_collision=0;
	    for(i=0; i<=curr_gapindex; i++){
		while(gapsl[i]<=left_seek && gapsr[i]>=left_seek){
		    left_seek--;
		    gap_collision=1;
		}
		if(gap_collision){  
		    i=-1;
		    gap_collision=0;
		}
	    }
	    if(left_seek<0)
		printf("* ");
	    else
		printf("%d ", left_seek+1);

	    gap_collision=0;
	    for(i=0; i<=curr_gapindex; i++){
		while(gapsr[i]>=right_seek && gapsl[i]<=right_seek){
		    right_seek++;
		    gap_collision=1;
		}
		if(gap_collision){
		    i=-1;
		    gap_collision=0;
		}
	    }
	    if(right_seek>=s)
		printf("*\n");
	    else
		printf("%d\n", right_seek+1);
	}
	
	printf("-\n");
	scanf("%d %d", &s, &r);
    }
    return 0;
}
