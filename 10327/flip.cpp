#include <iostream>
#include <vector>

//simple bubble sort for now, change later
std::vector<int> sort(std::vector<int> nums){
    int j, sorted = 0, temp;
    while(0 == sorted){
	sorted = 1;
	for(int i=0; i<nums.size()-1; i++){
	    j = i+1;
	    if(nums[i]>nums[j]){
		temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
		sorted = 0;
	    }
	}
    }
    return nums;
}

int main(){
    int n;
    while(std::cin>>n){
	std::vector<int> nums, sorted;
	int num;       
	while(n--){
	    std::cin>>num;
	    nums.push_back(num);
	}
	sorted = sort(nums);
	
	int mark[1000] = {0};
	int pos[1000] = {0};
	
	for(int i=0; i<nums.size(); i++){
	    for(int j=0; j<sorted.size(); j++){
		if(nums[i]==sorted[j] && mark[j]!=1){
		    pos[i] = j - i;
		    mark[j] = 1;
		    break;
		}
	    }
	}
	//
	std::cout<<"\n";
    }
}
