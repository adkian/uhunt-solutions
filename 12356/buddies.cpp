#include <iostream>
using namespace std;

int main(){
    int s, r;
    scanf("%d %d", &s, &r);
    while(s>0){
	int line[100000]={0};
	for(int i=0; i<s; i++)
	    line[i]=1;

	int left, right;

	while(r--){
	    bool foundleft = false;
	    int left_seek, right_seek;
	    
	    scanf("%d %d", &left, &right);
	    
	    for(int i=left-1; i<right; i++)
		line[i]=0;
	    
	    for(left_seek=left-1; line[left_seek]==0
		    && left_seek>0; left_seek--);
	    for(right_seek=right-1; line[right_seek]==0
		    && right_seek<s; right_seek++);
	    
	    if(left_seek<=0 && line[left_seek]==0)
		printf("* ");
	    else
		printf("%d ", left_seek+1);

	    if(right_seek==s && line[right_seek]==0)
		printf("*\n");
	    else
		printf("%d\n", right_seek+1);
	}
	printf("-\n");
	scanf("%d %d", &s, &r);
    }
}
