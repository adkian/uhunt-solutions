#include <iostream>
#include <string>
#include <ctype.h>
#include <stdlib.h>
using namespace std;

/*
legend:
f: free
a: attacked
P/p: pawn
B/b: bishop
N/n: knight
R/r: rook
Q/q: queen
K/k: king
 */

void addrookattack(string board[8][8], int row, int col); 
void addbishopattack(string board[8][8], int row, int col); 
void addattack(string board[8][8], string piece, int row, int col);
void printboard(string board[8][8]);

int main(){
  string board[8][8];
  string fen;//="rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
  while(cin>>fen){
    int row=0, col=0, index=0;
    while(row<8){
      int frees;
      while(fen[index]!='/' && fen[index]!=NULL){
	if(isdigit(fen[index])){
	  frees=fen[index]-'0'+col;
	  while(col<frees){board[row][col]="f"; col++; } 
	  index++;
	}
	else{
	  board[row][col]=fen[index]; 
	  col++;
	  index++;
	}
      } 
      row++;index++;col=0;
    }
    //for(row=0;row<8;row++){
    //cout<<endl;
    //for(col=0;col<8;col++)
    //cout<<board[row][col];
  
    row=col=0;
    while(row<8){
      if(board[row][col]=="f" || board[row][col]=="a");
      else addattack(board, board[row][col], row, col);
      col++;
      if(col>7) { row++;col=0; }
    }
    //    printboard(board);
    int counter=0;
    for(row=0;row<8;row++)
      for(col=0;col<8;col++)
	if(board[row][col]=="f") counter++;
    cout<<counter<<endl;
  }
  return 0;
}

void addattack(string board[8][8], string piece, int row, int col){
  
  if(piece=="k" || piece=="K") {

    if(col+1<=7 && board[row][col+1]=="f") board[row][col+1]="a";
    if(col-1>=0 && board[row][col-1]=="f") board[row][col-1]="a";

    if(row+1<=7){
      if(board[row+1][col]=="f") board[row+1][col]="a";
      if(col+1<=7 && board[row+1][col+1]=="f")  board[row+1][col+1]="a";
      if(col-1>=0 && board[row+1][col-1]=="f") board[row+1][col-1]="a";
    }
    if(row-1>=0){
      if(board[row-1][col]=="f") board[row-1][col]="a";
      if(col+1<=7 && board[row-1][col+1]=="f") board[row-1][col+1]="a";
      if(col-1>=0 && board[row-1][col-1]=="f") board[row-1][col-1]="a";
    }
  }

  else if(piece=="q" || piece=="Q") {
    addrookattack(board, row, col);
    addbishopattack(board, row, col);
  }
  else if(piece=="b" || piece=="B") { addbishopattack(board, row, col); }
  else if(piece=="r" || piece=="R") { addrookattack(board, row, col); } 
  else if(piece=="n" || piece=="N") {
    if(row+2<=7 && col+1<=7 && board[row+2][col+1]=="f") board[row+2][col+1]="a";
    if(row+2<=7 && col-1>=0 && board[row+2][col-1]=="f") board[row+2][col-1]="a";
    if(row-2>=0 && col+1<=7 && board[row-2][col+1]=="f") board[row-2][col+1]="a";
    if(row-2>=0 && col-1>=0 && board[row-2][col-1]=="f") board[row-2][col-1]="a";

    if(col+2<=7 && row+1<=7 && board[row+1][col+2]=="f") board[row+1][col+2]="a";
    if(col+2<=7 && row-1>=0 && board[row-1][col+2]=="f") board[row-1][col+2]="a";
    if(col-2>=0 && row+1<=7 && board[row+1][col-2]=="f") board[row+1][col-2]="a";
    if(col-2>=0 && row-1>=0 && board[row-1][col-2]=="f") board[row-1][col-2]="a";    
  }
  else if(piece=="p"){ 
    if(row+1<8 && col-1>=0 && board[row+1][col-1]=="f") board[row+1][col-1]="a";
    if(row+1<8 && col+1<=7 && board[row+1][col+1]=="f") board[row+1][col+1]="a";
  }
  else if(piece=="P"){
    if(row-1>=0 && col+1<=7 && board[row-1][col+1]=="f") board[row-1][col+1]="a";
    if(row-1>=0 && col-1>=0 && board[row-1][col-1]=="f") board[row-1][col-1]="a";
  }
}

void printboard(string board[8][8]){
  for(int r=0;r<8;r++){
    for(int c=0;c<8;c++){
      cout<<board[r][c]<<" ";
    }
    cout<<endl;
  }
}


void addbishopattack(string board[][8],int row, int col){
  bool conf=false;
  int trow=row, tcol=col;
  while(!conf){
    tcol++;trow++;
    if(tcol>=8 || trow>=8 || (board[trow][tcol]!="f" && board[trow][tcol]!="a")) conf=true;
    else board[trow][tcol]="a";
  }
  conf=false;
  trow=row;tcol=col;
  while(!conf){
    tcol++;trow--;
    if(tcol>=8 || trow<0 || (board[trow][tcol]!="f" && board[trow][tcol]!="a")) conf=true;
    else board[trow][tcol]="a";
  }
  conf=false;
  trow=row; tcol=col;
  while(!conf){
    tcol--;trow--;
    if(tcol<0 || trow<0 || (board[trow][tcol]!="f" && board[trow][tcol]!="a")) conf=true;
    else board[trow][tcol]="a";
  }
  conf=false;
  trow=row; tcol=col;
  while(!conf){
    tcol--;trow++;
    if(tcol<0 || trow>=8 || (board[trow][tcol]!="f" && board[trow][tcol]!="a")) conf=true;
    else board[trow][tcol]="a";
  }
}

void addrookattack(string board[][8], int row, int col){
  bool conf=false;
  int trow=row, tcol=col;
  while(!conf){
    trow++;
    if(trow>=8 || (board[trow][tcol]!="f" && board[trow][tcol]!="a")) conf=true;
    else board[trow][tcol]="a";
  }
  conf=false;
  trow=row; tcol=col;
  while (!conf){
    trow--;
    if(trow<0 || (board[trow][tcol]!="f" && board[trow][tcol]!="a")) conf=true;
    else board[trow][tcol]="a";
  }
  conf=false;
  trow=row; tcol=col; 
  while (!conf){
    tcol++;
    if(tcol>=8 || (board[trow][tcol]!="f" && board[trow][tcol]!="a")) conf=true;
    else board[trow][tcol]="a";
  }
  conf=false;
  trow=row;tcol=col; 
  while (!conf){
    tcol--;
    if(tcol<0 || (board[trow][tcol]!="f" && board[trow][tcol]!="a")) conf=true;
    else board[trow][tcol]="a";
  }
}
