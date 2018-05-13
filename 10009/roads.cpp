#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;

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
	    string path="";
	    cin>>city1>>city2;
	    c1 = (int)city1[0] % 65;
	    c2 = (int)city2[0] % 65;

	    //BFS 
	    bool visited[26]={false};
	    stack<int> s;
	    stack<string> p;
	    int start = c1;
	    string c;	    
	    s.push(start);
	    
	    c = char(s.top()+65);
	    p.push(c);
	    p.push(c);
	    while(s.top()!=c2){		
		start = s.top();
		s.pop();
		visited[start]=true;	       
		for(int i=0; i<26; i++)
		    if(start!=i && map[start][i]==1 && !visited[i])
			    s.push(i);
	    }
	    
	    // for(int i=0; i<s.size(); i++){
	    // 	c= char(s.top()+65);
	    // 	path+=c;
	    // 	s.pop();
	    // }
	    
	    cout<<path<<endl;
	} 	
    }
}

