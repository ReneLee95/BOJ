#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <queue>

using namespace std;

int **map;
vector<int> trans[100001];
bool *visit;
bool *tvisit;

vector<int> v[100001];

int n,l;
int start = 0;
int goal = 0;
int result = 0;

queue<int> q;

int board() {
	while(!q.empty()) {
		int k = q.front();
		visit[k] = true;
		if(tvisit[v[k]] == false) {
			tvisit[v[k]] = true;
		}
	}
	for(int i = 0; i<v[k].size(); i++) {
			
	}
}

int main() {
	cin>>n>>l;
	
	visit = (bool *)malloc(sizeof(bool) * n + 1);
	tvisit = (bool *)malloc(sizeof(bool) * l + 1);
	
	int input;
	int count = 0;
	
	while(count <l) {
		cin>>input;
		if(input == -1) count++;
		else {
			if(count == l -1) break;
			trans[count+1].push_back(input);
			v[input].push_back(count + 1);
		}
	}
	cin>>start>>goal;
	q.push(start);
	board();
	
	cout<<result<<endl;
	
	return 0;
}
