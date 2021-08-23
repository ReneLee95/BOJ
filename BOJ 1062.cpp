#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
#include <math.h>

using namespace std;

bool visit[26] = { false, };
int n, k;
int result = 0;
char name[16];
vector<char> check[51];

void checking() {
	int count = 0;
	int set = 0;
	for (int i = 0; i < n; i++) {
		bool count = true;
		for (int j = 0; j < check[i].size(); j++) {
			if (visit[check[i][j] - 'a'] == false) {
				count = false;
				break;
			}
		}
		if (count == true) {
			set++;
		}
	}
	result = max(result, set);
	return;
}

void findsearch(int start, int cur) {
	if (start == k - 5) {
		checking();
		return;
	}
	for (int i = cur; i < 26; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			findsearch(start + 1, i + 1);
			visit[i] = false;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> name;
		for (int j = 4; j < strlen(name) - 4; j++) {
			check[i].push_back(name[j]);
		}
	}

	visit['a' - 'a'] = true;
	visit['n' - 'a'] = true;
	visit['t' - 'a'] = true;
	visit['i' - 'a'] = true;
	visit['c' - 'a'] = true;

	if (k < 5 || k == 26) {
		if (k == 26) cout << n << endl;
		else cout << "0" << endl;
	}
	else {
		findsearch(0, 0);
		cout << result << endl;
	}
}
