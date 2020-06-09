#include <iostream>
#include <stack>
using namespace std;

bool in(stack<int> s, int num){
    bool found=false;
    while(!found && s.size()>0){
	found=(s.top()==num);
	s.pop();
    }
    return found;
}

int main(){
    int num;
    cin>>num;
    while(num!=0){
	stack<int> s, orig;
	for(int i=num; i>0; i--)
	    orig.push(i);
	
	bool possible=true, end=false;

	while(!end){
	    int x;
	    cin>>x;
	    if(x==0){
		cout<<endl;
		end=true;
	    }
	    else{
		for(int i=0; i<num-1 && possible; i++){
		    while(!in(s, x)){
			s.push(orig.top());
			orig.pop();
		    }
		    if(x!=s.top())
			possible=false;
		    cin>>x;
		}
		possible? cout<<"Yes\n" : cout<<"No\n";
	    }
	}
	cin>>num;
    }
}
