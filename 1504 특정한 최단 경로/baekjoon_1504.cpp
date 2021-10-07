#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct Node {
	vector<pair<int, int>> adjNode;
	int length = 0;
};

vector<Node> x;
int N, E;
int A, B;

int daExtra(int start,int target) {
	if (start == target) {
		return 1;
	}
	queue<int> qu;
	qu.push(start);
	bool isGam = false;
	while (!qu.empty()) {
		int top = qu.front();
		qu.pop();
		for (int i = 0; i < x[top].adjNode.size(); i++) {
			if (x[x[top].adjNode[i].first].length == 0 || x[x[top].adjNode[i].first].length > x[top].length + x[top].adjNode[i].second) {
				x[x[top].adjNode[i].first].length = x[top].length + x[top].adjNode[i].second;
				if (x[top].adjNode[i].first == target) {
					isGam = true;
				}
				else {
					qu.push(x[top].adjNode[i].first);
				}
			}
		}
	}
	if (isGam == true) {
		return 1;
	}
	else {
		return -1;
	}
}

int daExtraAll(int start) {
	queue<int> qu;
	qu.push(start);
	while (!qu.empty()) {
		int top = qu.front();
		qu.pop();
		for (int i = 0; i < x[top].adjNode.size(); i++) {
			if (x[x[top].adjNode[i].first].length == 0 || x[x[top].adjNode[i].first].length > x[top].length + x[top].adjNode[i].second) {
				if (x[top].adjNode[i].first != 1) {
					x[x[top].adjNode[i].first].length = x[top].length + x[top].adjNode[i].second;
					qu.push(x[top].adjNode[i].first);
				}
			}
		}
	}
	if (A != 1) {
		if (x[A].length == 0 || x[B].length == 0 || x[N].length == 0) {
			return -1;
		}
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> E;
	x.resize(N + 1);
	for (int i = 0; i < E; i++) {
		int box1, box2, box3;
		cin >> box1 >> box2 >> box3;
		x[box1].adjNode.push_back({ box2,box3 });
		x[box2].adjNode.push_back({ box1,box3 });
	}
	cin >> A >> B;
	int panstar = daExtraAll(1);
	if (panstar == -1) {
		cout << "-1";
		return 0;
	}
	int goToA = x[A].length;
	int goToB = x[B].length;
	for (int i = 0; i <= N; i++) {
		x[i].length = 0;
	}
	panstar = daExtra(A, B);
	if (panstar == -1) {
		cout << "-1";
		return 0;
	}
	int AToB = x[B].length;
	for (int i = 0; i <= N; i++) {
		x[i].length = 0;
	}
	panstar = daExtra(A, N);
	int AToN = x[N].length;
	for (int i = 0; i <= N; i++) {
		x[i].length = 0;
	}
	if (B == N) {
		
	}
	panstar = daExtra(B, N);
	int BToN = x[N].length;
	int ans1 = goToA + AToB + BToN;
	int ans2 = goToB + AToB + AToN;
	if (ans1 > ans2) {
		cout << ans2;
	}
	else {
		cout << ans1;
	}
	return 0;
}