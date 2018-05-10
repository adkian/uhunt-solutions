#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
/*
rows
j 0 1 2 3 4
i
0 <0 1 0 1 0>
1 <0 1 0 1 0>
2 <0 0 0 0 0>
 */
// struct sq{
//     sq* N;
//     sq* S;
//     sq* E;
//     sq* W;
//     int count;
// };


char turn_left(char);
char turn_right(char);

int main(){
    int b, w, count[100][100]={0};
    vector<char> sq[100];
    string s;

    cin>>b>>w;
    while(b>0){
	int count[100][100]={0};
	vector<char> sq[100];
	string s;	
	
	for(int i=0;i<b;i++){
	    cin>>s;
	    for(int j=0;j<w;j++)
		sq[i].push_back(s[j]);
	}
	
	int j = 0, i=b-1;
	int wallj = 0, walli=b;
	char dir='E';
	bool returned=false;
	
	while(!returned){	    
	    if((walli<b && walli>=0) && (wallj>=0 && wallj<w))
		if(sq[walli][wallj]=='0'){
		    if(dir=='S'){
			walli--;
			wallj++;
		    }
		    else if(dir=='W'){
			walli++;
			wallj++;
		    }
		    else if(dir=='N'){
			walli++;
			wallj--;
		    }
		    else if(dir=='E'){
			walli--;
			wallj--;
		    }
		    dir = turn_right(dir);
		}
	    
	    if(dir=='E'){
		if(j+1<w && sq[i][j+1]=='0'){
		    j++;
		    wallj++;
		    count[i][j]++;
		}
		else{
		    dir = turn_left(dir);
		    walli--;
		    wallj++;
		}
	    }
	    else if(dir=='N'){
		if(i-1>=0 && sq[i-1][j]=='0'){
		    i--;
		    walli--;
		    count[i][j]++;
		}
		else{
		    dir = turn_left(dir);
		    walli--;
		    wallj--;
		}
	    }
	    else if(dir=='W'){
		if(j-1>=0 && sq[i][j-1]=='0'){
		    j--;
		    wallj--;
		    count[i][j]++;
		}
		else{
		    dir = turn_left(dir);
		    walli++;
		    wallj--;
		}
	    }
	    else if(dir=='S'){
		if(i+1<b && sq[i+1][j]=='0'){
		    i++;
		    walli++;
		    count[i][j]++;
		}
		else{
		    dir = turn_left(dir);
		    walli++;
		    wallj++;
		}
	    }
	    
	    if(i==b-1 && j==0)
		returned = true;
	}

	int visited[5]={0};
	for(int i=0; i<b; i++){
	    for(int j=0; j<w; j++){
		if(count[i][j]>4)
		    continue;
		else if(sq[i][j]=='0')
		    visited[count[i][j]]++;
	    }
	}
	for(int k=0; k<5; k++)
	    cout<<right<<setw(3)<<visited[k];
	cout<<endl;
	cin>>b>>w;
    }
}

char turn_left(char dir){
    char new_dir;
    if(dir=='E')
	new_dir = 'N';
    else if(dir=='N')
	new_dir = 'W';
    else if(dir=='W')
	new_dir = 'S';
    else if(dir == 'S')
	new_dir = 'E';
    return new_dir;
}

char turn_right(char dir){
    char new_dir;
    if(dir=='E')
	new_dir = 'S';
    else if(dir=='N')
	new_dir = 'E';
    else if(dir=='W')
	new_dir = 'N';
    else if(dir == 'S')
	new_dir = 'W';
    return new_dir;    
}
