#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
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
	parent.resize(N + 1);
	level.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		level[i] = 1;
	}
	for (int i = 0; i < M; i++) {
		int input, a, b;
		cin >> input >> a >> b;
		if (input == 0) {
			marge(a, b);
		}
		if (input == 1) {
			int parentA = find(a);
			int parentB = find(b);
			if (parentA == parentB) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
	return 0;
}