#include <iostream>
#include <string>
using namespace std;

void addattack(int, int, int[][8]);
void addbishopattack(int, int, int[][8]);

int main(){
    string fen;

    while(cin>>fen){
	int board[8][8] = {0};
	int j=0, i=0, gap;
	for(int fenindex=0; fenindex<fen.length(); fenindex++){
	    if(fen[fenindex]=='/'){
		i++; j=0;
		continue;
	    }
	    else if((int)fen[fenindex]<=56 && (int)fen[fenindex]>=49){
		gap=j+(int)fen[fenindex] % 48;
		for(;j<gap; j++);		    
	    }
	    else{
		board[i][j++] = (int)fen[fenindex];
	    }
	}
	
	for(int i=0; i<8; i++){
	    for(int j=0; j<8; j++){
		if(board[i][j]>0){		    
		    addattack(i, j, board);
		}
	    }
	}
	
	int counter=0;
	for(int i=0;i<8;i++)
	    for(int j=0;j<8;j++)
		if(board[i][j]==0)
		    counter++;
	cout<<counter<<endl;	
	
    }
    
}

void addattack(int i, int j, int board[][8]){
    
    //PAWNS
    if(board[i][j]==112){ //p
	if(i+1<8 && j-1>=0 && board[i+1][j-1]==0)
	    board[i+1][i-1]=1;
	if(i+1<8 && j+1<=7 && board[i+1][j+1]==0)
	    board[i+1][j+1]=1;
    }
    else if(board[i][j]==80){//P
	if(i-1>=0 && j+1<=7 && board[i-1][j+1]==0)
	    board[i-1][j+1]=0;
	if(i-1>=0 && j-1>=0 && board[i-1][j-1]==0)
	    board[i-1][j-1]=1;
    }
    
    //KNIGHTS
    else if(board[i][j]==110 || board[i][j]==78) { 
	if(i+2<=7 && j+1<=7 && board[i+2][j+1]==0) board[i+2][j+1]=1;
	if(i+2<=7 && j-1>=0 && board[i+2][j-1]==0) board[i+2][j-1]=1;
	if(i-2>=0 && j+1<=7 && board[i-2][j+1]==0) board[i-2][j+1]=1;
	if(i-2>=0 && j-1>=0 && board[i-2][j-1]==0) board[i-2][j-1]=1;

	if(j+2<=7 && i+1<=7 && board[i+1][j+2]==0) board[i+1][j+2]=1;
	if(j+2<=7 && i-1>=0 && board[i-1][j+2]==0) board[i-1][j+2]=1;
	if(j-2>=0 && i+1<=7 && board[i+1][j-2]==0) board[i+1][j-2]=1;
	if(j-2>=0 && i-1>=0 && board[i-1][j-2]==0) board[i-1][j-2]=1;    
    }

    //KINGS
    else if(board[i][j]==75 || board[i][j]==107) {
	if(j+1<=7 && board[i][j+1]==0) board[i][j+1]=1;
	if(j-1>=0 && board[i][j-1]==0) board[i][j-1]=1;

	if(i+1<=7){
	    if(board[i+1][j]==0) board[i+1][j]=1;
	    if(j+1<=7 && board[i+1][j+1]==0)  board[i+1][j+1]=1;
	    if(j-1>=0 && board[i+1][j-1]==0) board[i+1][j-1]=1;
	}
	if(i-1>=0){
	    if(board[i-1][j]==0) board[i-1][j]=1;
	    if(j+1<=7 && board[i-1][j+1]==0) board[i-1][j+1]=1;
	    if(j-1>=0 && board[i-1][j-1]==0) board[i-1][j-1]=1;
	}
    }

    //BISHOPS
    else if(board[i][j]==98 || board[i][j]==66){
	addbishopattack(i, j, board);
    }

}


void addbishopattack(int i, int j, int board[][8]){
    bool conf=false;
    int trow=i, tcol=j;
    while(!conf){
	tcol++;trow++;
	if(tcol>=8 || trow>=8 || (board[trow][tcol]!=0 && board[trow][tcol]!=1))
	    conf=true;
	else board[trow][tcol]=1;
    }
    
    conf=false;
    trow=i;tcol=j;
    while(!conf){
	tcol++;trow--;
	if(tcol>=8 || trow<0 || (board[trow][tcol]!=0 && board[trow][tcol]!=1))
	    conf=true;
	else board[trow][tcol]=1;
    }
    
    conf=false;
    trow=i; tcol=j;
    while(!conf){
	tcol--;trow--;
	if(tcol<0 || trow<0 || (board[trow][tcol]!=0 && board[trow][tcol]!=1))
	    conf=true;
	else board[trow][tcol]=1;
    }
    
    conf=false;
    trow=i; tcol=j;
    while(!conf){
	tcol--;trow++;
	if(tcol<0 || trow>=8 || (board[trow][tcol]!=0 && board[trow][tcol]!=1))
	    conf=true;
	else board[trow][tcol]=1;
    }
}
