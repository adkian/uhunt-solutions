#include <iostream>
using namespace std;

int main(){
  int ct, x=0, ar[3], temp;
  cin>>ct;
  while(x<ct)
    {
      cin>>ar[0]>>ar[1]>>ar[2];
      bool sorted=false;
      while(!sorted)
	for(int i=1;i<3;i++)
	  {      
	    sorted=true;
	    if(ar[i]<ar[i-1])
	      {
		sorted=false;
		temp=ar[i-1];
		ar[i-1]=ar[i];
		ar[i]=temp;
	      }
	  }
      cout<<"Case "<<x+1<<": "<<ar[1]<<endl;;
      x++;
    }
}
    
