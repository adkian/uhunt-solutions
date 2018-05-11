#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int n;
    while(cin>>n){
	int nums[3000], diffs[2999]={0}, i;
	bool jolly=true;
	for(i=0; i<n; i++)
	    cin>>nums[i];
	for(i=1; i<n; i++)
	    diffs[abs(nums[i]-nums[i-1])]=1;
	for(i=1; i<n; i++){
	    if(diffs[i]==0){
		jolly=false;
		break;
	    }	
	}
	if(jolly)
	    cout<<"Jolly\n";
	else
	    cout<<"Not jolly\n";
    }
    return 0;
}
