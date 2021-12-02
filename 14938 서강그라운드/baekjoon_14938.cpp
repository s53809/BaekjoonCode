#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int N, M, R;

typedef struct Node {
	int item;
	vector<pair<int, int>> adjNode;
};

vector<Node> x;
vector<vector<int>> length;

void floydWarshall() {
	for (int k = 1; k < N + 1; k++) {
		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				if (length[i][k] + length[k][j] < length[i][j]) {
					length[i][j] = length[i][k] + length[k][j];
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> R;
	x.resize(N + 1);
	length.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		length[i].resize(N + 1);
		for (int j = 1; j <= N; j++) {
			if (i != j) {
				length[i][j] = INF;
			}
			else {
				length[i][j] = 0;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		cin >> x[i].item;
	}
	for (int i = 0; i < R; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		x[a].adjNode.push_back(make_pair(b, c));
		x[b].adjNode.push_back(make_pair(a, c));
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < x[i].adjNode.size(); j++) {
			length[i][x[i].adjNode[j].first] = x[i].adjNode[j].second;
		}
	}
	floydWarshall();
	int maximum = 0;
	for (int i = 1; i <= N; i++) {
		int stac = 0;
		for (int j = 1; j <= N; j++) {
			if (length[i][j] <= M) {
				stac += x[j].item;
			}
		}
		if (maximum < stac) {
			maximum = stac;
		}
	}
	cout << maximum;
}