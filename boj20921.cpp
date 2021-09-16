#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
deque<int> dq;
vector<int> v;

int main() {
	int n,k;
	
	cin>>n>>k;
	
	for(int i = 0; i<n; i++) {
		dq.push_back(i+1);
	}
	for(int i = 1; i<=n; i++) {
		if(n-i <= k) {
			v.push_back(dq.back());
			dq.pop_back();
			k -= n-i;
		}
		else {
			v.push_back(dq.front());
			dq.pop_front();
		}
	}
	for(int i = 0; i<n; i++) {
		cout<<v[i]<<" ";
	}
}
