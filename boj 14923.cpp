#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stdlib.h>
#include <string.h>

using namespace std;

int maparr[1001][1001];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

queue<vector<int>> q;

int N,M;
int Hx,Hy;
int Ex,Ey;

bool visit[1001][1001][2] = {false};

int BFS() {
	
	while(!q.empty()) {
		int x = q.front()[0];
		int y = q.front()[1];
		int z = q.front()[2];
		int check = q.front()[3];
		
		q.pop();
		
		if(x == Ex - 1 && y == Ey - 1) {
			return z;
		}
		
		for(int i = 0; i<4; i++) {	
			int newX = x + dy[i];
			int newY = y + dx[i];
			
			if(newX < 0 || newX >= N || newY < 0 || newY >= M) continue;
			
			if (maparr[newX][newY] == 1) {
				if (visit[newX][newY][1] || check != 0) continue;
				q.push({ newX, newY, z + 1, 1 });
				visit[newX][newY][1] = true;
			}
			else {
				if (visit[newX][newY][check]) continue;
				q.push({ newX, newY, z + 1, check });
				visit[newX][newY][check] = true;
			}
		}	
	}
	return -1;
}

int main() {
	scanf("%d %d",&N,&M);
	scanf("%d %d",&Hx,&Hy);
	scanf("%d %d",&Ex,&Ey);
	
	for(int i = 0; i<N; i++) {
		for(int j = 0; j<M; j++) {
			scanf("%d",&maparr[i][j]);
		}
	}
		
	q.push({Hx-1,Hy-1,0,0});
	visit[Hx-1][Hy-1][0] = true;

	printf("%d\n",BFS());
	
	return 0;
}
