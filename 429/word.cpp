#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
using namespace std;

int get_dist(string a, string b);
void make_graph(vector<string> wlist, int map[][200]);
int bfs(int map[][200], int start, int dest, int s);

int main(){
    int tc;
    cin>>tc;
    while(tc--){
	string w="";
	vector<string> wlist;
	int map[200][200];
	while(w!="*"){
	    cin>>w;
	    wlist.push_back(w);
	}
	make_graph(wlist, map);
	cin.ignore();
	
	string line, s1, s2;
	getline(cin, line);
	while(line!=""){
	    int l1, l2;
	    istringstream iss(line);
	    iss>>s1>>s2;

	    for(int i=0; i<wlist.size(); i++){
		if(wlist[i]==s1)
		    l1 = i;
		else if(wlist[i]==s2)
		    l2 = i;
	    }
	    
	    cout<<s1<<" "<<s2<<" "<<bfs(map, l1, l2, wlist.size())<<"\n";
	    getline(cin, line);	    
	}
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

void make_graph(vector<string> wlist, int map[][200]){
    for(int i=0; i<wlist.size(); i++)
	for(int j=0; j<wlist.size(); j++)
	    if(i!=j && get_dist(wlist[i], wlist[j])==1){
		map[i][j] = 1;
		map[j][i] = 1;
	    }
}

int get_dist(string a, string b){
    int dist = 0;
    int len = a.length();    
    if(len == b.length())
	for(int i=0; i<len; i++)
	    if(a[i]!=b[i])
		dist++;
    return dist;
}
