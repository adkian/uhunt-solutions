#include <iostream>
using namespace std;

int main(){
  int inct;
  int origx, origy;
  int x, y;
  cin>>inct;
  while(inct!=0)
    {
      int loccnt=0;
      cin>>origx>>origy;
      while(loccnt<inct)
	{
	  cin>>x>>y;
	  x-=origx;y-=origy;
	  if(x==0 || y==0) cout<<"divisa"<<endl;
	  else if(x>0 && y>0) cout<<"NE"<<endl;
	  else if(x>0 && y<0) cout<<"SE"<<endl;
	  else if(x<0 && y>0) cout<<"NO"<<endl;
	  else if(x<0 && y<0) cout<<"SO"<<endl;
	  loccnt++;
	}
      cin>>inct;
    }
  return 0;
}
