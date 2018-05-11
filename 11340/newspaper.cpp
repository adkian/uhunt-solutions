#include <iostream>
#include <string>
#include <cstdio>
#include <limits>
using namespace std;

int main(){
    int tc;
    cin>>tc;
    for(int i=0; i<tc; i++){
	int k, costmap[256]={0}, lines, cost;
	double totcost=0;
	unsigned char c;
	string line;
	cin>>k;
	for(int j=0; j<k; j++){
	    scanf("%hhu", &c);
	    scanf("%i", &cost);
	    costmap[c] = cost;
	}
	
	lines=cin.get();
	cin.ignore();
	for(int j=0; j<lines; j++){
	    getline(cin, line);
	    for(int l=0; line[l]!='\n' && line[l]!='\r'; l++){
		totcost += costmap[line[l]];
	    }
	}
	cout.precision(2);
	cout<<fixed<<totcost/100<<"$\n";
    }
    return 0;
}
