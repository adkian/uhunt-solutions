#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
using namespace std;

void makeGraph(vector<string> wlist, int map[][200]);
int getDist(string a, string b);
int bfs(int map[][200], int start, int dest, int s);

int main(){
    int tc;
    cin>>tc;
    while(tc--){
	string w="";
	vector<string> wlist;
	int map[200][200] = {0};
	cin>>w;
	while(w!="*"){
	    wlist.push_back(w);
	    cin>>w;
	}
	makeGraph(wlist, map);
	cin.ignore();
	
	string line, s1, s2;
	getline(cin, line);
	while(line!=""){
	    int l1, l2; /* indices to words in map */
	    istringstream iss(line);
	    iss>>s1>>s2;

	    for(int i=0; i<wlist.size(); i++){
		if(wlist[i]==s1)
		    l1 = i;
		if(wlist[i]==s2)
		    l2 = i;
	    }
	    int dist;

	    dist = bfs(map, l1, l2, wlist.size());
	    cout<<s1<<" "<<s2<<" "<<dist<<"\n";
	    getline(cin, line);	    
	}
	if(tc>0)
	    cout<<endl;
    }
}

/*
pred=[] pred list
q=[] queue
q.add(startnode)

while !q.empty
  node_A = dequeue q
  for each unvisited node_B adj to node_A
    pred[node_B]=node_A
    q.add(node_B)    
 */

int bfs(int map[][200], int start, int dest, int s){
    queue<int> q;
    int pred[200], n;
    bool visited[200] = {false};    
    
    q.push(start);
    while(!q.empty()){
	n = q.front();
	q.pop();
	for(int i=0; i<s; i++){
	    if(visited[i]==false && map[n][i]==1){
		q.push(i);
		visited[i]=true;
		pred[i]=n;
	    }		
	}
    }

    int len = 0, k=dest;    
    while(k!=start){
	k = pred[k];
	len++;
    }
    return len;
}

void makeGraph(vector<string> wlist, int map[][200]){    
    for(int i=0; i<wlist.size(); i++)
	for(int j=0; j<wlist.size(); j++)
	    if(i!=j && getDist(wlist[i], wlist[j])==1){
		map[i][j] = 1;
		map[j][i] = 1;
	    }
}

int getDist(string a, string b){
    int dist = 0;
    string longer, shorter;

    if(a.length() > b.length()){
	longer = a;
	shorter = b;
    }
    else{ /* Also accounts for equal length */
	longer = b;
	shorter = a;
    }
    dist += longer.length() - shorter.length();
    
    for(int i=0; i<shorter.length(); i++)
	if(shorter[i]!=longer[i])
	    dist+=1;

    return dist;
}
