#include <iostream>
using namespace std;

int main()
{
    int dur;
    cin>>dur;
    while(dur>0)
    {
	int deprecs, months, depmonth, i;
	double dwp, amt, val, cur_depval, iments, deps[100]={0.0};
	bool nend;
	
	cin>>dwp>>amt>>deprecs;
	for(i=0;i<deprecs;i++)
	    cin>>depmonth>>deps[depmonth];

	val = dwp+amt;
	iments = amt/dur;
	nend = true;
	
	for(months=0; ; ++months)
	{
	    if(deps[months]>0)
		cur_depval=deps[months];
	    val -= val*cur_depval;
	    if(val>amt)
		break;
	    amt -= iments;
	}
	if(months==1)
	    cout<<months<<" month\n";
	else
	    cout<<months<<" months\n";
	cin>>dur;
    }
    return 0;
}
