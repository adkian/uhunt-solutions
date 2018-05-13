#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;

bool print_path(int [][26], int start, int dest, string &path, bool visited[]);
int main(){
    int tc;
    cin>>tc;
    while(tc--){
	int r, q, c1, c2;
	char city1[100], city2[100];

	int map[26][26] = {0};		
	cin>>r>>q;
	while(r--){
	    cin>>city1>>city2;
	    c1 = (int)city1[0] % 65;
	    c2 = (int)city2[0] % 65;

	    map[c1][c2] = 1;
	    map[c2][c1] = 1;
	}       

	while(q--){
	    string path=""; int i=0;bool viz[26];
	    cin>>city1>>city2;
	    c1 = (int)city1[0] % 65;
	    c2 = (int)city2[0] % 65;

	    print_path(map, c1, c2, path, viz);
	    cout<<path<<endl;
	}
    }
}

bool print_path(int map[26][26], int start, int dest, string &path, bool visited[]){
    if(start==dest){
	path+=char(start+65);
	return true;
   }
    else{
	visited[start]=true;
	for(int j=0; j<26; j++){
	    if(map[start][j]==1 && visited[j]==false){
		visited[j]=true;
		if(print_path(map, j, dest, path, visited) == true){
		    path+=char(start+65);
		    return true;
		}
	    }
	}
	return false;
    }
}

/*

FIND(dest, node)
  if node == dest:
    path+=node
    return true
  else
    for node in unvisited(node.pi)
      visited[node]=true
      if(FIND(dest, node))
        path+=node  
*/
