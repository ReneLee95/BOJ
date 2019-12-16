#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define fio ios_base::sync_with_stdio(0), cin.tie(0)

using namespace std;

vector <string> v[201];

int main()
{
	fio;
	int N;
	cin>>N;
	
	for(int i =0; i<N; i++)
	{
		int k;
		string name;
		cin>>k>>name;
		v[k].push_back(name);
	}
	
	for(int i =0; i<201; i++)
	{
		for(int j =0; j<v[i].size(); j++)
		{
			cout<<i<<' '<<v[i][j]<<endl;
		}
	}
}
