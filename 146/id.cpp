#include <iostream>
#include <string.h>
#include <algorithm>

int main(){
    char s[50];
    std::cin>>s;
    while(s[0]!='#'){
	if(std::next_permutation(s, s+strlen(s)))
	   std::cout<<s<<std::endl;
	else
	    std::cout<<"No Successor\n";
	std::cin>>s;
    }
}
