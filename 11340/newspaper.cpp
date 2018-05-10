#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main(){
    int tc;
    cin>>tc;
    for(int i=0; i<tc; i++){
	int k, costmap[256]={0}, lines, cost;
	double totcost=0;
	char c, line[10000];
	
	cin>>k;
	for(int j=0; j<k; j++){
	    cin>>c>>cost;
	    costmap[c+128] = cost;
	}
	
	cin>>lines;
	cin.ignore();
	for(int j=0; j<lines; j++){
	    cin.get(line, 10000);
	    for(int l=0; line[l]!='\n' && line[l]!='\r'; l++){
		totcost += costmap[line[l]+128];
	    }
	}
	cout.precision(2);
	cout<<fixed<<totcost/100<<"$\n";
    }
    return 0;
}
