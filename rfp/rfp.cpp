#include <iostream>
#include <string>
using namespace std;

int main(){
    float req, pro;    
    cin>>req>>pro;
    int rfpnum=0;
    while(req>0)
    {
	int i, j, k;
	float cost,curcost=1000000000, comp, curcomp=0, numcomp;
	string trash, curname, name;
	++rfpnum;
	for(i=0; i<=req; i++)
	    getline(cin, trash);

	for(j=0; j<pro; j++){
	    getline(cin, name);
	    cin>>cost>>numcomp;
	    comp = numcomp/req;
	    
	    if(comp>curcomp || (comp==curcomp && cost<curcost)){
		curname = name;
		curcomp = comp;
		curcost = cost;
	    }
	    
	    for(k=0;k<=numcomp;k++)
		getline(cin, trash);
	}
	if(rfpnum>1) cout<<"\n";
	cout<<"RFP #"<<rfpnum<<"\n"<<curname<<"\n";
	cin>>req>>pro;					     
    }
    return 0;
}
