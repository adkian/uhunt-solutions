#include <iostream>
using namespace std;

/*

for any nodes a, b
  if there exists c such that
    c in a.PI AND c in b.PI:
      NOT bicolorable   

for b in a.PI:
  for j in b.PI:
    if j in a.PI:
      return false

ABOVE ALGORITHM DOESNT WORK
cycles can consist of >=3 nodes (not bc when odd)
 */
bool findbc(int n, int adj[][200]);

int main(){
    int n, e;

    cin>>n;
    while(n){
	int adj[200][200]={0}, a, b;
	cin>>e;
	
	for(int i=0; i<e; i++){
	    cin>>a>>b;
	    adj[a][b]=1;
	    adj[b][a]=1;
	}				  

	bool bc = findbc(n, adj);

	if(!bc) cout<<"NOT BICOLORABLE.\n";
	else cout<<"BICOLORABLE.\n";

	cin>>n;
    };
}

bool findbc(int n, int adj[][200]){
    int clist[200]={0};
    clist[0]=1;
    for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
	    if(adj[i][j]==1)
		if(clist[j]==0 && clist[i]>0)
		    clist[j]=clist[i]==1 ? 2:1;
		else if(clist[i]==0 && clist[j]>0)
		    clist[i]=clist[j]==1 ? 2:1;
    for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
	    if(adj[i][j]==1)
		if(clist[j]==0 && clist[i]>0)
		    clist[j]=clist[i]==1 ? 2:1;
		else if(clist[i]==0 && clist[j]>0)
		    clist[i]=clist[j]==1 ? 2:1;
    for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
	    if(adj[i][j]==1 && clist[i]==clist[j])
		return false;

    return true;
}
