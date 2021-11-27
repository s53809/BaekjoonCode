#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int N, M;
vector<vector<pair<int, int>>> adjNode;
vector<int> length;
vector<int> route;
vector<int> rouute;

void daExtra(int str) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, str });
	length[str] = 0;
	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (length[now] < dist) {
			continue;
		}
		for (int i = 0; i < adjNode[now].size(); i++) {
			int cost = dist + adjNode[now][i].second;
			if (cost < length[adjNode[now][i].first]) {
				route[adjNode[now][i].first] = now;
				length[adjNode[now][i].first] = cost;
				pq.push({ -cost, adjNode[now][i].first });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	length.resize(N + 1);
	adjNode.resize(N + 1);
	route.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		length[i] = INF;
	}
	for (int i = 0; i < M; i++) {
		int s, e, g;
		cin >> s >> e >> g;
		adjNode[s].push_back(make_pair(e, g));
	}
	int strNode, endNode;
	cin >> strNode >> endNode;
	daExtra(strNode);
	cout << length[endNode] << '\n';
	int temp = endNode;
	while (temp) {
		rouute.push_back(temp);
		temp = route[temp];
	}
	cout << rouute.size() << '\n';
	for (int i = rouute.size() - 1; i >= 0; i--) {
		cout << rouute[i] << ' ';
	}
	cout << '\n';
}