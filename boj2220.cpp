#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swapHeap(vector<int>& vector, int a ,int b)
{
	int temp = vector[a];
	vector[a] = vector[b];
	vector[b] = temp;
}

int main()
{
	int num;
	cin>>num;
	vector<int> vector(num+1,0);
	vector[1] = 1;
	for(int i = 2; i<=num; i++)
	{
		vector[i] = i;
		int j = i-1;
		swapHeap(vector[i],vector[i-1]);
		
		do
		{
			swap(vector[j], vector[j >>1]);
			j = j/2;
		}while(j!=1);
	}
	
	for(int i = 1; i<=num; i++)
	{
		cout<<vector[i]<<" ";
	}
	
	return 0;
}
