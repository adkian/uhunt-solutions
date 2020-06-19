#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define NUM_COLORS 50

typedef struct {
    int c1, c2;
} bead;

bead *path;
int adj[NUM_COLORS][NUM_COLORS] = {{0}};
int path_counter = 0;

void find_path(int x, int y, int curr)
{
    bead new_bead = {x, y};    
    path[path_counter++] = new_bead;
    adj[x][y]-=1;
    adj[y][x]-=1;
    int new_x, new_y;
    int found = 0;
    switch (curr) {
    case 0:
	for (int i=0; i<NUM_COLORS && !found; i++) {
	    if (adj[x][i] >= 1) {
		new_x = x; new_y = i;
		found = 1;
	    }
	}
	break;
    case 1:
	for (int i=0; i<NUM_COLORS && !found; i++) {
	    if (adj[i][y] >= 1) {
		new_x = i; new_y = y;
		found = 1;
	    }
	}
    }
    
    if (found==0)
	return;
    curr = (curr+1)%2;
    find_path(new_x, new_y, curr);
    return;
}

int main()
{
    int tc, curr_tc = 0;
    scanf("%d", &tc);
    for (; curr_tc < tc; curr_tc++) {
	int num_beads;
	int start_x, start_y;
	int color_count[50] = {0}, repeated_count[50] = {0};
	
	scanf("%d", &num_beads);	
	path = malloc(sizeof(bead)*num_beads);
	
	int a, b;	
	for (int x = 0; x < num_beads; x++) {
	    scanf("%d %d", &a, &b);
	    adj[a-1][b-1] += 1;
	    adj[b-1][a-1] += 1;
	    
	    color_count[a-1] += 1;
	    color_count[b-1] += 1;
	    if (a == b) {
		repeated_count[a-1] += 2;
	    }	    
	    if (x == 0) {
		start_x = a-1;
		start_y = b-1;
	    }
	}
	int possible = 1;
	for (int x = 0; x < NUM_COLORS; x++) {
	    if (color_count[x] % 2 != 0) {
		possible = 0;
		break;
	    }
	    if (repeated_count[x] > 0 && color_count[x] < repeated_count[x]+2) {
		possible = 0;
		break;
	    }
	}
	printf("Case #%d\n", curr_tc+1);
	if (!possible) {
	    printf("some beads may be lost\n");
	}
	else {
	    path_counter = 0;
	    find_path(start_y, start_x, 0);
	    printf("path counter: %d\n", path_counter);
	    for (int x = 0; x < path_counter; x++) {
		if (x%2 != 0)
		    printf("%d %d\n", path[x].c1+1, path[x].c2+1);
		else
		    printf("%d %d\n", path[x].c2+1, path[x].c1+1);
	    }
	}
	
	printf("\n");	
	for (int x=0; x < NUM_COLORS; x++) {
	    for (int y=0; y < NUM_COLORS; y++) {
		adj[x][y] = 0;
		adj[y][x] = 0;
	    }
	}
	free(path);
    }
}
