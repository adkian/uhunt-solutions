#include <stdio.h>
#include <string.h>

void rotate(int s, int small[][100]);
int find(int big[][100], int small[][100], int i, int j, int s);

int main(){
    int b, s;
    scanf("%d %d", &b, &s);
    while(b>0){
	int big[100][100], small[100][100], i, j;
	char str[100];
	for(i=0; i<b; i++){
	    scanf("%s", &str);
	    for(j=0; j<b; j++)
		big[i][j]=(int)str[j];
	}
	for(i=0; i<s; i++){
	    scanf("%s", &str);
	    for(j=0; j<s; j++)
		small[i][j]=(int)str[j];
	}
	
	int rots, finds[4]={0};
	for(rots=0; rots<4; rots++){
	    /* search logic */
	    for(i=0; i<b-s+1; i++){
		for(j=0; j<b-s+1; j++){
		    if(big[i][j]==small[0][0]){
			finds[rots]+=find(big, small, i, j, s);
		    }
		}
	    }
	    rotate(s, small);
	}
	
	printf("%d %d %d %d\n", finds[0], finds[3],  finds[2], finds[1]);;       
	scanf("%d %d", &b, &s);
    }
    return 0;
}

/* 
i' = -j+(s-1)
j' = i
*/
void rotate(int s, int small[][100]){
    int i, j, rotsmall[100][100];    
    for(i=0; i<s; i++)
	for(j=0; j<s; j++)
	    rotsmall[(s-1)-j][i]=small[i][j];
    memcpy(small, rotsmall, sizeof(int)*100*100);
}

int find(int big[][100], int small[][100], int i, int j, int s){
    int yes = 1, si, sj, bj;
    for(si=0;si<s; i++, si++){
	for(sj=0, bj=j; sj<s; bj++, sj++){
	    if(big[i][bj]!=small[si][sj]){
		yes = 0;
		break;
	    }	
	}
	if(yes==0)
	    break;
	
    }
    return yes;
}
