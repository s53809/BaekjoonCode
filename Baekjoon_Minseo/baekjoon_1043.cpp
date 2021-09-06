#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct Node {
	bool isLie = false;
	vector<int> adjNode;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	int lyerCnt;
	cin >> lyerCnt;
	vector<int> lyer;
	lyer.resize(lyerCnt);
	for (int i = 0; i < lyerCnt; i++) {
		cin >> lyer[i];
	}
	vector<Node> x;
	vector<vector<int>> partyMember;
	partyMember.resize(M);
	x.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int Num;
		cin >> Num;
		vector<int> box;
		box.resize(Num);
		for (int j = 0; j < Num; j++) {
			cin >> box[j];
			partyMember[i].push_back(box[j]);
		}
		for (int j = 0; j < Num; j++) {
			for (int u = 0; u < Num; u++) {
				if (box[j] == box[u]) {
					continue;
				}
				x[box[j]].adjNode.push_back(box[u]);
			}
		}
	}
	queue<int> qu;
	for (int i = 0; i < lyerCnt; i++) {
		x[lyer[i]].isLie = true;
		qu.push(lyer[i]);
	}
	while (!qu.empty()) {
		int top = qu.front();
		qu.pop();
		for (int i = 0; i < x[top].adjNode.size(); i++) {
			if (x[x[top].adjNode[i]].isLie == false) {
				qu.push(x[top].adjNode[i]);
				x[x[top].adjNode[i]].isLie = true;
			}
		}
	}
	int cnt = 0;
	bool isLiee = false;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < partyMember[i].size(); j++) {
			if (x[partyMember[i][j]].isLie == true) {
				isLiee = true;
				break;
			}
		}
		if (isLiee == false) {
			cnt++;
		}
		else {
			isLiee = false;
		}
	}
	cout << cnt;
}