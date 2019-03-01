#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int tc;
    char *word = malloc(10);
    size_t st = 10;
    scanf("%d", &tc);
    while(tc--){
	getline(&word, &st, stdin); /* blank line after tc number */
	char dict[200][10];
	int i = 0;
	
	getline(&word, &st, stdin);
	while(word[0]!='*'){
	    memcpy(dict[i++], word, st);
	    getline(&word, &st, stdin);
	}
	int j=0;
	for(;j<i; j++){
	    printf("%s", dict[j]);
	}
    }
}
