#include <stdio.h>

int main(){
    int in;
    scanf("%d", &in);
    while(in>0){
	int len, temp=in, i;
	int a=0, b=0, curr_bit=0;
	
	for(len=0; temp!=0; len++)
	    temp>>=1;
	
	for(i=0; i<len; i++){
	    if(in & (1 << i)){
		if(curr_bit==0){
		    a |= (1 << i);
		    b |= (0 << i);
		}
		else{
		    b |= (1 << i);
		    a |= (0 << i);
		}
		curr_bit+=1;
		curr_bit%=2;
	    }
	    else{
		a |= (0 << i);
		b |= (0 << i);
	    }
	}
	printf("%d %d\n", a, b);
	scanf("%d", &in);
    }
}
