#include <iostream>
#include <vector>
#include <string>
using namespace std;

int get_dist(string a, string b);
void make_graph(vector<string> wlist, int map[][200]);
bool get_pathlen(int map[][200], vector<string> wlist, int start, int dest, string &path, bool visited[]);

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
	
	string s1, s2;
	while(cin>>s1>>s2){
	    int l1, l2;
	    for(int i=0; i<wlist.size(); i++){
		if(wlist[i]==s1)
		    l1 = i;
		else if(wlist[i]==s2)
		    l2 = i;
	    }
	    int len = 0;
	    bool visited[200];
	    string path;
	    get_pathlen(map, wlist, l1, l2, path, visited);
	    cout<<s1<<" "<<s2<<" "<<path.length()-1<<endl;
	}
    }
}

bool get_pathlen(int map[][200], vector<string> wlist, int start, int dest, string &path, bool visited[]){
    if(start==dest){
	path+="a";
	return true;
   }
    else{
	visited[start]=true;
	for(int j=0; j<26; j++){
	    if(map[start][j]==1 && visited[j]==false){
		visited[j]=true;
		if(get_pathlen(map, wlist, j, dest, path, visited) == true){
		    path+="a";
		    return true;
		}
	    }
	}
	return false;
    }
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
