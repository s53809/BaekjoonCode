#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;

vector<vector<pair<int, int>>> adjNode;
vector<int> length;
int N;

void daExtra(int str) {
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, str));
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
				length[adjNode[now][i].first] = cost;
				pq.push(make_pair(-cost, adjNode[now][i].first));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	adjNode.resize(N + 1);
	length.resize(N + 1);
	for (int i = 0; i < N - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adjNode[a].push_back(make_pair(b, c));
		adjNode[b].push_back(make_pair(a, c));
	}
	for (int i = 0; i < N + 1; i++) {
		length[i] = INF;
	}
	daExtra(1);
	int maxNum = 1;
	for (int i = 1; i < N + 1; i++) {
		if (length[maxNum] < length[i] && length[i] != INF) {
			maxNum = i;
		}
	}
	for (int i = 1; i < N + 1; i++) {
		length[i] = INF;
	}
	daExtra(maxNum);
	maxNum = 0;
	for (int i = 1; i < N + 1; i++) {
		if (maxNum < length[i] && length[i] != INF) {
			maxNum = length[i];
		}
	}
	cout << maxNum;
}