#include <stdio.h>
#include <stdlib.h>

int greedy(int c[], int size)
{
    int k = 0, curr_sum = c[0];
    int types = 2, x;
    for (x=1; x < size-1; x++) {
	if (c[x] + curr_sum < c[x+1]) {
	    curr_sum += c[x];
	    types++;
	}
    }
    return types;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while (tc--) {	
	int n, c[1000], x;
	scanf("%d", &n);
	for (x=0; x<n; x++) {
	    int k;
	    scanf("%d", &k);
	    c[x] = k;
	}
	int types = greedy(c, n);
	
	printf("%d\n", types);
    }
}
