#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> adj;
vector<bool> visited;

int BFS(int N) {
	if (visited[N] == true) {
		return -1;
	}
	queue<int> qu;
	qu.push(N);
	visited[N] = true;
	while (!qu.empty()) {
		int dist = qu.front();
		qu.pop();
		for (int i = 0; i < adj[dist].size(); i++) {
			if (visited[adj[dist][i]] == false) {
				visited[adj[dist][i]] = true;
				qu.push(adj[dist][i]);
			}
		}
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	adj.resize(N + 1);
	visited.resize(N + 1);
	for (int i = 1; i < N + 1; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		int result = BFS(i);
		if (result != -1) {
			cnt++;
		}
	}
	cout << cnt;
}