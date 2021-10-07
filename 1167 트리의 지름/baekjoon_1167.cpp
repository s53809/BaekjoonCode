#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<vector<pair<int, int>>> x; //근처 노드를 저장하는 배열으로 first에는 노드의 번호가 second에는 노드의 거리가 저장됨
int* dist;
bool* visited; //얘는 쓰다가 필요 없으면 걍 삭제

void DFS(int start) {
	queue<int> qu;
	qu.push(start);
	visited[start] = true;
	while (!qu.empty()) {
		int top = qu.front();
		qu.pop();
		for (int i = 0; i < x[top].size(); i++) {
			if (dist[x[top][i].first] == 0 || dist[x[top][i].first] < dist[top] + x[top][i].second) {
				if (visited[x[top][i].first] == false) {
					dist[x[top][i].first] = dist[top] + x[top][i].second;
					visited[x[top][i].first] = true;
					qu.push(x[top][i].first);
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	x.resize(N + 1);
	dist = new int[N + 1];
	visited = new bool[N + 1];
	for (int i = 0; i < N; i++) {
		int goNode, box = 0;
		bool isFirst = true;
		cin >> goNode;
		cin >> box;
		while (true) {
			int length, nodeNum;
			nodeNum = box;
			cin >> length;
			cin >> box;
			x[goNode].push_back({ nodeNum,length });
			if (box == -1) {
				break;
			}
		}
	}
	for (int i = 0; i < N + 1; i++) {
		dist[i] = 0;
		visited[i] = false;
	}
	DFS(1);
	int box = 0;
	int max = 0;
	for (int i = 1; i < N + 1; i++) {
		if (box < dist[i]) {
			box = dist[i];
			max = i;
		}
	}
	for (int i = 0; i < N + 1; i++) {
		dist[i] = 0;
		visited[i] = false;
	}
	DFS(max);
	int ans = 0;
	for (int i = 1; i < N + 1; i++) {
		if (ans < dist[i]) {
			ans = dist[i];
		}
	}
	cout << ans;
}