#include <stdio.h>

int main(){
    int tc;
    scanf("%d", &tc);
    while(tc--){
	int s, d, s1, s2;
	scanf("%d %d", &s, &d);

	if(s < d || (s-d)%2!=0){
	    printf("impossible\n");
	}
	else{
	    s1 = (s-d)/2;
	    s2 = s1+d;
	    printf("%d %d\n", s2, s1);
	}
    }   
}
