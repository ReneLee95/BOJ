#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

void function(int N,int K,int *visit) {
	queue<int> q;
	
	q.push(N);
	
	visit[N] = 1;
	
	while(!q.empty()) {
		int start = q.front();
		q.pop();
		if(start == K) {
			cout<<visit[start]-1;
			break;
		}
		
		if(start-1>=0 && visit[start-1] == 0) {
			q.push(start -1);
			visit[start-1] = visit[start] + 1;
		}
		
		if(start+1 <=100000 && visit[start+1] == 0) {
			q.push(start+1);
			visit[start+1] = visit[start] + 1;
		}
		if(start*2 <=100000 && visit[start *2] == 0) {
			q.push(start * 2);
			visit[start * 2] = visit[start] + 1;
		}
	}
}

int main() {
	int visit[100001];
	memset(visit,0,sizeof(int) * 100001);
	int N,K;
	cin>>N>>K;
	function(N,K,visit);
	
	return 0;
}
