#include <stdio.h>

char getProd(int arr[100000], int begin, int end){
    int negative_ct = 0;
    int i = begin-1;
    for(i;i<=end-1; i++){
	if(arr[i] == 0)
	    return '0';
	else if(arr[i] < 0)
	    negative_ct++;
    }
    if(negative_ct % 2 == 0)
	return '+';
    else
	return '-';
}

int main(){
    int arr[100000], n, k, i, j, num;
    int begin, end;
    char c;
    
    while(scanf("%d %d", &n, &k)!=EOF){
	j = 0;	
	for(i=0; i<n; i++){
	    scanf("%d", &num);
	    if(num == 0)
		arr[j++] = 0;
	    else
		arr[j++] = num > 0 ? 1 : -1;	
	}
       
	scanf("\n", &c);	
	for(i=0; i<k; i++){
	    scanf("%c %d %d\n", &c, &begin, &end);
	    if(c == 'C'){
		if(end == 0)
		    arr[begin-1] = 0;
		else
		    arr[begin-1] = end > 0 ? 1 : -1;
	    }
	    else
		printf("%c", getProd(arr, begin, end));
	}
	printf("\n");
    }
}
