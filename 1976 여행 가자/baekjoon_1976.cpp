#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> inputNum;
vector<int> parent;
vector<int> level;

int find(int u) {
	if (parent[u] == u) {
		return u;
	}
	return parent[u] = find(parent[u]);
}

void marge(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) {
		return;
	}

	if (level[u] > level[v]) {
		swap(u, v);
	}

	parent[u] = v;

	if (level[u] == level[v]) {
		level[v]++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;

	inputNum.resize(N + 1);
	parent.resize(N + 1);
	level.resize(N + 1);
	
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		level[i] = 1;
	}

	for (int i = 1; i <= N; i++) {
		inputNum[i].resize(N + 1);
		for (int j = 1; j <= N; j++) {
			cin >> inputNum[i][j];
			if (inputNum[i][j] == 1) {
				marge(i, j);
			}
		}
	}
	int a;
	cin >> a;
	int resultNumber = find(a);
	bool cantGo = false;
	for (int i = 1; i < M; i++) {
		int box;
		cin >> box;
		if (resultNumber != find(box)) {
			cantGo = true;
			break;
		}
	}
	if (cantGo) {
		cout << "NO";
	}
	else {
		cout << "YES";
	}
}