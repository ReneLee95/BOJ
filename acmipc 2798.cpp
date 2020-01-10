#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	std::vector<int> vector;
	std::vector<int> vector2;
	std::vector<int> vector3;
	int N,M;
	cin>>N>>M;
	
	int cardNum;
	
	for(int i =0; i<N; i++)
	{
		cin>>cardNum;
		vector.push_back(cardNum);
	}
	sort(vector.begin(),vector.end(),compare);
	
	for(int i =0; i<=N-3; i++)
	{
		for(int j = i+1; j<N; j++)
		{
			for(int k = j+1; k<N; k++)
			{
				if(vector[i]+vector[j]+vector[k]<=M)
				{
					vector2.push_back(vector[i]+vector[j]+vector[k]);
				}
			}
		}
	}
	
	sort(vector2.begin(),vector2.end(),compare);
	
	std::cout<<vector2[0];
}
