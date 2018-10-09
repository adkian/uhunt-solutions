#include <iostream>

int ceil(float a){
    float dec = a - (int)a;
    if(dec>0)
	return (int)a+1;
    return (int)a;
}

int main(){
    int n, r, c, bignum, smallnum;
    char p;
    std::cin>>n;    
    while(n--){
	std::cin>>p>>r>>c;
	if(r > c){
	    bignum = r;
	    smallnum = c;
	}
	else{
	    bignum = c;
	    smallnum = r;
	}
	    

	switch(p){
	case 'r':
	    std::cout<<smallnum<<std::endl;
	    break;
	case 'K':
	    std::cout<<ceil((float)smallnum/2)*ceil((float)bignum/2)
		     <<std::endl;
	    break;
	case 'k':		
	    std::cout<<(smallnum*ceil((float)bignum/2)-
			(bignum%2==0 ? 0 : (int)smallnum/2))<<std::endl;
	    break;
	case 'Q':
	    std::cout<<smallnum<<std::endl;
	    break;
	}	    	
    }
}
