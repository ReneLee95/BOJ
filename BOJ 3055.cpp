#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int arrow[4] = { 1,-1,0,0 };
int arrow2[4] = { 0,0,1,-1 };

queue<pair<int, int>> q;
queue<pair<int, int>> wq;

int R, C;
int x, y;
int wx, wy;

void bfs(char** arr, int** visit) {

	while (!q.empty()) {
		int cat2 = q.size();
		int cat = wq.size();
		for (int i = 0; i < cat; i++) {
			wx = wq.front().first;
			wy = wq.front().second;
			wq.pop();
			for (int j = 0; j < 4; j++) {
				if (((wx + arrow[j] >= 0) && (wx + arrow[j] < R)) && ((wy + arrow2[j] >= 0) && (wy + arrow2[j] < C))) {
					if (visit[wx + arrow[j]][wy + arrow2[j]] == 0 && arr[wx + arrow[j]][wy + arrow2[j]] != 'D') {
						wq.push(make_pair(wx + arrow[j], wy + arrow2[j]));
						visit[wx + arrow[j]][wy + arrow2[j]] = -1;
					}
				}
			}
		}

		for (int m = 0; m < cat2; m++) {
			x = q.front().first;
			y = q.front().second;
			if (arr[x][y] == 'D') {
				cout << visit[x][y] - 1 << endl;
				return;
			}
			q.pop();
			for (int i = 0; i < 4; i++) {
				if (((x + arrow[i] >= 0) && (x + arrow[i] < R)) && ((y + arrow2[i] >= 0) && (y + arrow2[i] < C))) {
					if (visit[x + arrow[i]][y + arrow2[i]] == 0) {
						q.push(make_pair(x + arrow[i], y + arrow2[i]));
						visit[x + arrow[i]][y + arrow2[i]] = visit[x][y] + 1;
					}
				}
			}
		}
	}
	cout << "KAKTUS" << endl;
	return;
}

int main() {
	char space;
	cin >> R >> C;
	char** arr = (char**)malloc(sizeof(char*) * R);
	int** visit = (int**)malloc(sizeof(int*) * R);
	for (int i = 0; i < R; i++) {
		arr[i] = (char*)malloc(sizeof(char) * C);
		visit[i] = (int*)malloc(sizeof(int) * C);
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			visit[i][j] = 0;
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> space;
			arr[i][j] = space;
			if (arr[i][j] == '*') {
				wq.push(make_pair(i, j));
				visit[i][j] = -1;
			}
			if (arr[i][j] == 'X') {
				visit[i][j] = 1;
			}
			if (arr[i][j] == 'S') {
				q.push(make_pair(i, j));
				visit[i][j] = 1;
			}
		}
	}

	bfs(arr, visit);

	for (int i = 0; i < R; i++) {
		free(arr[i]);
		free(visit[i]);
	}
	free(arr);
	free(visit);
	return 0;
}
