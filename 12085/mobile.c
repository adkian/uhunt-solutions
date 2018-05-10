#include <stdio.h>

int main(){
    int n;
    cin>>n;
    while(n>0){
	int i, nums[100000];
	for(i=0; i<n; i++)
	    cin>>nums[i];
	for(i=n-2; i>=0; i--){
	    while(nums[i+1]-nums[i]==1){
		nums[i]=0;
	    }
	}	
	cin>>n
    }
}
