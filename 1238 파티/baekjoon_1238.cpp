#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct Node {
	vector<pair<int, int>> adjNode;
};
int N, M, X;
vector<Node> x;
int* dist;
int *students;

void daExtra(int start) {
	queue<int> qu;
	qu.push(start);
	while (!qu.empty()) {
		int top = qu.front();
		qu.pop();
		for (int i = 0; i < x[top].adjNode.size(); i++) {
			if (dist[x[top].adjNode[i].first] == 0 || dist[x[top].adjNode[i].first] > dist[top] + x[top].adjNode[i].second) {
				if (x[top].adjNode[i].first != start) {
					dist[x[top].adjNode[i].first] = dist[top] + x[top].adjNode[i].second;
					qu.push(x[top].adjNode[i].first);
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> X;
	x.resize(N + 1);
	dist = new int[N + 1];
	students = new int[N + 1 ];
	for (int i = 0; i <= N; i++) {
		dist[i] = 0;
		students[i] = 0;
	}
	for (int i = 0; i < M; i++) {
		int startNode, endNode, length;
		cin >> startNode >> endNode >> length;
		x[startNode].adjNode.push_back({ endNode,length });
	}
	for (int i = 0; i <= N; i++) {
		dist[i] = 0;
	}
	int max = 0;
	for (int i = 1; i <= N; i++) {
		if (i != X) {
			daExtra(i);
		}
		students[i] += dist[X];
		for (int j = 0; j <= N; j++) {
			dist[j] = 0;
		}
	}
	daExtra(X);
	for (int i = 1; i <= N; i++) {
		students[i] += dist[i];
		if (max < students[i]) {
			max = students[i];
		}
	}
	cout << max;
	return 0;
}