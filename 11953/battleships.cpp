#include <iostream>
#include <string>
using namespace std;

int finddir(int i, int j, int n, int map[][100]);
bool isship(int, int, int [][100]);

int main(){
    int tc;
    cin>>tc;
    for(int ca = 1; ca<=tc; ca++){
	int n;	
	string s;
	int map[100][100];
	cin>>n;
	for(int i=0; i<n; i++){
	    cin>>s;
	    for(int j=0; j<n; j++)
		map[i][j]=(int)s[j];		    
	}

	int dir, shipcount =0;
	bool broken=true;
	for(int i=0; i<n; i++){
	    for(int j=0; j<n; j++){
		if(isship(i, j, map)){
		    broken = true;
		    dir = finddir(i, j, n, map);
		    if(dir == 1){
			//up
			int up = i-1;
			for(; up>=0 && isship(up,j, map); up--){
			    if(map[up][j]==120)
				broken=false;
			    map[up][j]=0;
			}
			//down
			int down = i+1;
			for(; down<n && isship(down,j,map); down++){
			    if(map[down][j]==120)
				broken=false;
			    map[down][j]=0;			    
			}
		    }
		    else if(dir == 2){
			//right
			int right = j+1;
			for(; right<n && isship(i,right,map); right++){
			    if(map[i][right]==120)
				broken=false;
			    map[i][right]=0;			    
			}
			//left
			int left = j-1;
			for(; left>=0 && isship(i,left,map); left--){
			    if(map[i][left]==120)
				broken=false;
			    map[i][left]=0;			    
			}
		    }
		    else{
			if(map[i][j]==120)
			    broken=false;
			map[i][j]=0;			
		    }
		    if(map[i][j]==120)
			broken=false;
		    
		    map[i][j]=0;
		    if(broken == false)
			shipcount++;
		    
		}
	    }
	}
	cout<<"Case "<<ca<<": "<<shipcount<<endl;
    }
}

// 1: vertical, 2: horizontal, 0: alone
int finddir(int i, int j, int n, int map[][100]){
    int dir;
    if(i+1<n && (map[i+1][j]==64 || map[i+1][j] == 120))
	dir = 1;
    else if(i-1>0 && (map[i-1][j]==64 || map[i-1][j] == 120))
	dir = 1;
    else if(j+1<n && (map[i][j+1]==64 || map[i][j+1] == 120))
	dir = 2;
    else if(j-1>n && (map[i][j-1]==64 || map[i][j-1] == 120))
	dir = 2;
    else
	dir =0;
    return dir;
}

bool isship(int i, int j, int map[][100]){
    return (map[i][j]==64 || map[i][j] == 120);
}
