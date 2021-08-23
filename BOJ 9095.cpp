#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int m;
int arr[12] = {0, };

int dp(int k) {
	if(k == n) return arr[k] = arr[k-1] + arr[k-2] + arr[k-3];
	else {
		arr[k] = arr[k-1] + arr[k-2] + arr[k-3];
		return dp(k+1);
	}
}

int main() {
	cin>>m;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	
	int k;
	
	for(int i = 0; i<m; i++) {
		cin>>n;
		if(n<=3) cout<<arr[n]<<endl;
		else {
			cout<<dp(4)<<endl;
		}
	}
}
