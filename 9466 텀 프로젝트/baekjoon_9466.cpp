#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adjNode;
bool visited[100001];
bool finished[100001];
int T, N;
int cnt;

void dfs(int now) {
	visited[now] = true;
	int next = adjNode[now];
	if (!visited[next]) dfs(next);
	if (visited[next] == true && finished[next] == false) { 
		int temp = next;
		while (temp != now) {
			temp = adjNode[temp];
			cnt++;
		}cnt++;
	}
	finished[now] = true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		for (int i = 1; i <= N; i++) {
			visited[i] = false;
			finished[i] = false;
		}
		cin >> N;
		adjNode.resize(N + 1);
		for (int i = 1; i <= N; i++) {
			cin >> adjNode[i];
		}
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) dfs(i);
		}
		cout << N - cnt << '\n';
		cnt = 0;
	}
}