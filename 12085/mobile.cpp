#include <iostream>
#include <string>
#include <math.h>
using namespace std;

void print_range(int, int, int);

int main(){
    int n, c=0;
    cin>>n;
    while(n>0){
	cout<<"Case "<<++c<<":\n";
	int i, nums[100000];
	for(i=0; i<n; i++)
	    cin>>nums[i];
	
	int higher, lower, len=1, temp = nums[0];
	while(temp /= 10)
	    len++;
	
	for(i=0; i<n; i++){
	    if(nums[i+1]-nums[i]==1){
		lower = nums[i];
		while(nums[i+1]-nums[i]==1){
		    i++;
		}
		higher = nums[i];
		print_range(lower, higher, len);		
	    }
	    else
		cout<<"0"<<nums[i]<<endl;
	}
	cout<<endl;
	cin>>n;
    }
}

void print_range(int lower, int higher, int len){
    int i, k;
    string num;
    for(i=len-1; ; i--){
	if(lower/int(pow(10.0,i)) != higher/int(pow(10.0,i)))
	    break;
    }
    for(k=len-(i+1); k<len; k++){
	num += to_string(higher)[k];	
    }
    cout<<"0"<<lower<<"-"<<num<<endl;
}
