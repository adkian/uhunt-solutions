#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int find_gcd(int a, int b);
void printer(int c, int q, int num, int deno);

int main(){
    int n, cnum=0;
    cin>>n;
    
    while(n>0){
	cnum++;
	int nm, sum=0;
	for(int i=0; i<n; i++){
	    cin>>nm;
	    sum += nm;
	}
	int gcd;	
	int deno, num, q;
	if(abs(sum)>=n){
	    if(sum % n == 0){
		num = sum/n;
		deno = 0;
		q = 0;
	    }
	    else{
		gcd = find_gcd(sum,n);
		while(gcd != 1){
		    sum /= gcd;
		    n /= gcd;
		    gcd = find_gcd(sum,n);	    
		}
		q = (sum-(sum%n))/n;
		num = sum%n;
		deno = n;
	    }
	}
	else{ //abs(sum)<n
	    gcd = find_gcd(n,sum);
	    while(gcd != 1){
		sum /= gcd;
		n /= gcd;
		gcd = find_gcd(n,sum);	    
	    }
	    q = 0;
	    num = sum;
	    deno = n;
	}
	printer(cnum, q, num, deno);
        cin >> n;
	
    }
}

void printer(int c, int q, int num, int deno){
    int dl=0, ql=0, nl=0, x=deno, y=q, z = num;
    while (x /= 10)
	dl++;
    while(y /= 10)
	ql++;
    while(z /= 10)
	nl++;
    if(deno == 1 || deno == 0){
	if(num<0)
	    cout<<"Case "<<c<<":\n"<<"- "<<abs(num)<<endl;
	else
	    cout<<"Case "<<c<<":\n"<<num<<endl;
    }
    else if(q == 0){
	if(num<0 || deno<0){
	    cout<<"Case "<<c<<":\n";
	    for(int k=0;k<dl+2;k++) cout<<" ";	    
	    cout<<abs(num)<<endl;
	    cout<<"- ";
	    for(int k=0;k<dl+1;k++) cout<<"-";	    
	    cout<<endl;
	    cout<<"  "<<abs(deno)<<endl;	    
	}
	else{
	    cout<<"Case "<<c<<":\n";
	    for(int k=0;k<dl;k++) cout<<" ";	    
	    cout<<abs(num)<<endl;
	    for(int k=0;k<dl+1;k++) cout<<"-";	    
	    cout<<endl;
	    cout<<abs(deno)<<endl;
	}
    }
    else{
	if(num<0 || deno<0){
	    cout<<"Case "<<c<<":\n";
	    for(int k=0;k<dl+2+ql-nl+1;k++) cout<<" ";	    
	    cout<<abs(num)<<endl;
	    cout<<"- "<<abs(q);
	    for(int k=0;k<dl+1;k++) cout<<"-";	    
	    cout<<endl;
	    for(int k=0;k<3+ql;k++) cout<<" ";	    	    
	    cout<<abs(deno)<<endl;
	}
	else{
	    cout<<"Case "<<c<<":\n";
	    for(int k=0;k<dl+1+ql-nl;k++) cout<<" ";	    
	    cout<<num<<endl;
	    cout<<q;
	    for(int k=0;k<dl+1;k++) cout<<"-";	    
	    cout<<endl;
	    for(int k=0;k<2+ql-1;k++) cout<<" ";	    	    
	    cout<<deno<<endl;
	}
    }
}

int find_gcd(int a, int b){
    if(b==0)
	return a;
    else
	return find_gcd(b, a % b);
}
