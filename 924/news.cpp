#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;

int getNumUnique(queue<int>q){
    vector<int>seen;
    int num_uniq = 0, curr;
    bool repeat;
    while(!q.empty()){
	repeat = false;
	curr = q.front();
	q.pop();
	for(int i=0; i<seen.size(); i++){
	    if(seen[i] == curr){
		repeat = true;
		break;
	    }
	}
	if(!repeat){
	    num_uniq++;
	    seen.push_back(curr);
	}
    }
    return num_uniq;
}

bool inQueue(queue<int>q, int num){
    int curr, qsize = q.size();
    for(int i=0; i<qsize; i++){
	curr = q.front();
	if(num == curr)
	    return true;
	q.pop();	    
    }
    return false;
}

int main(){
    int num_emps, num_conns, emp;
    cin>>num_emps;
    vector<vector<int>>adj;

    /* Make adjecency matrix */
    for(int i=0; i<num_emps; i++){
	cin>>num_conns;
	vector<int> adj_list;
	for(int j=0; j<num_conns; j++){
	    cin>>emp;
	    adj_list.push_back(emp);
	}
	adj.push_back(adj_list);
    }

    int tc, origin;
    cin>>tc;
    while(tc--){
	cin>>origin;
	/* bfs vars */
	queue<int> q;
	int max_num_depth, max_num, curr_size;
	int visited[num_emps] = {0}, emp_depth[num_emps] = {0};
	int curr_emp, curr_depth = 0;
	
	q.push(origin);
	curr_size = q.size();
	emp_depth[origin] = 0;
	max_num_depth = 0;
	max_num = 0;
	
	while(!q.empty()){
	    curr_emp = q.front();
	    visited[curr_emp] = 1;
	    if(emp_depth[curr_emp] > curr_depth){ /* depth increase */
		curr_depth+=1;
		curr_size = getNumUnique(q);
		if(curr_size > max_num){
		    max_num_depth = curr_depth;
		    max_num = curr_size;
		}
	    }
	    q.pop();
	    
	    for(int i=0; i<adj[curr_emp].size(); i++){
		if(!visited[adj[curr_emp][i]] &&
		   !inQueue(q, adj[curr_emp][i])){
		    q.push(adj[curr_emp][i]);
		    /* If first time seeing this emp, increase emp depth */
		    if(emp_depth[adj[curr_emp][i]] == 0)
			emp_depth[adj[curr_emp][i]] = curr_depth+1;
		}
	    }
	}
	
	if(max_num_depth == 0)
	    cout<<"0\n";
	else
	    cout<<max_num<<" "<<max_num_depth<<endl;
    }
}
