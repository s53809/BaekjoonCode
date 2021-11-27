#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

typedef struct Node {
	std::vector<std::pair<int, int>> adjNode;
	int length = 1e9;
};

int V, E, startNode;
std::vector<Node> x;

void daExtra(int strNode) {
	std::priority_queue<std::pair<int, int>> qu;
	qu.push({ 0, strNode });
	x[strNode].length = 0;
	while (!qu.empty()) {
		int dist = -qu.top().first;
		int now = qu.top().second;
		qu.pop();
		if (x[now].length < dist) {
			continue;
		}
		for (int i = 0; i < x[now].adjNode.size(); i++) {
			int cost = dist + x[now].adjNode[i].second;
			if (cost < x[x[now].adjNode[i].first].length) {
				x[x[now].adjNode[i].first].length = cost;
				qu.push({ -cost, x[now].adjNode[i].first }); // 작은 값을 출력하기 위해 -를 붙힘
			}
		}
	}
}

int main() {
	using namespace std;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> V >> E;
	cin >> startNode;
	x.resize(V + 1);
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		x[u].adjNode.push_back(make_pair(v, w));
	}
	daExtra(startNode);
	for (int i = 1; i <= V; i++) {
		if (i == startNode) {
			cout << 0 << '\n';
		}
		else if (x[i].length == 1e9) {
			cout << "INF\n";
		}
		else {
			cout << x[i].length << '\n';
		}
	}
	return 0;
}