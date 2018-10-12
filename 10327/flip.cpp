#include <iostream>
#include <vector>

int main(){
    int n;
    while(std::cin>>n){
	std::vector<int> nums;
	int num;       
	while(n--){
	    std::cin>>num;
	    nums.push_back(num);
	}
	int flips = 0;
	for(int i=0; i<nums.size()-1; i++){
	    for(int j=i+1; j<nums.size(); j++){
		if(nums[i]>nums[j])
		    flips+=1;
	    }
	}
	std::cout<<"Minimum exchange operations : "<<flips<<std::endl;
    }
}
