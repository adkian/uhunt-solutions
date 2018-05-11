#include <iostream>
#include <string>
using namespace std;

int main(){
    int tc;
    cin>>tc;
    while(tc--){
	int k, costmap[500]={0}, lines, cost;
	double totcost=0;
	string line, s;
	cin>>k;
	while(k--){
	    cin>>s>>cost;
	    costmap[int(s[0])+128]=cost;
	}
	
	cin>>lines;
	cin.ignore();
	while(lines--){
	    getline(cin, line);
	    for(int l=0; l<line.length(); l++){
		totcost += costmap[line[l]+128];
	    }
	}
	cout.precision(2);
	cout<<fixed<<totcost/100<<"$\n";
    }
    return 0;
}
