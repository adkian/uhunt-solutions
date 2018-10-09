#include <iostream>
#include <vector>

//simple bubble sort for now, change later
vector<int> sort(vector<int> nums){
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
	vector<int> nums, sorted, pos;
	int num;       
	while(n--){
	    std::cin>>num;
	    nums.push_back(num);
	}
	sorted = sort(nums);

	int nums_idex=0; 
	for(int sort_idex=0;
	    i<sorted.size() && nums_idex < sorted.size(); i++){
	    if(sorted[sort_idex] == nums[nums_idex]){
		pos.push_back(nums_idex - sort_idex);
		nums_idex++;
	    }
	}
	
    }
}
