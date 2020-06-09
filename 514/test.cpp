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
	int x;
	for(int i=0; i<num && possible; i++){
	    cin>>x;
	    while(!in(s, x)){
		s.push(orig.top());
		orig.pop();
	    }
	    if(x!=s.top())
		possible=false;

	}
	possible? cout<<"Yes\n" : cout<<"No\n";
	cin>>num;
    }
}
