#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

pair<string,string> p[10001];

bool compare(pair<string,string> p1, pair<string,string> p2)
{
	if(p1.first != p2.first)
	{
		return p1.first < p2.first;
	}
	
	return p1.second < p2.second;
}

int main()
{
	int a;
	string b,c;
	
	cin>>a;
	
	for(int i =0; i<a; i++)
	{
		cin>>b>>c;
		
		p[i] = make_pair(b,c);
	}
	
	sort(p,p+a,compare);
	
	for(int i =0; i<a; i++)
	{
		cout<<p[i].first<<' '<<p[i].second<<endl;
	}
	
	return 0;
}
