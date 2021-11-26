#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct Node {
	char Num;
	bool visited = false;
};

int N, M;
vector<vector<Node>> x;
vector<vector<int>> x_cnt;
int d_x[] = { -1,1,0,0 };
int d_y[] = { 0,0,-1,1 };

void BFS() {
	queue<pair<int, int>> qu;
	qu.push(make_pair(0, 0));
	x_cnt[0][0] = 1;
	while (!qu.empty()) {
		pair<int, int> box;
		box = qu.front();
		qu.pop();
		for (int i = 0; i < 4; i++) {
			int dir_y = box.first + d_y[i];
			int dir_x = box.second + d_x[i];
			if (dir_y >= 0 && dir_y < N && dir_x >= 0 && dir_x < M) {
				if (x[dir_y][dir_x].visited == false && x[dir_y][dir_x].Num == '1') {
					qu.push(make_pair(dir_y, dir_x));
					x[dir_y][dir_x].visited = true;
					x_cnt[dir_y][dir_x] += x_cnt[box.first][box.second] + 1;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	x.resize(N);
	x_cnt.resize(N);
	for (int i = 0; i < N; i++) {
		x[i].resize(M);
		x_cnt[i].resize(M);
		for (int j = 0; j < M; j++) {
			cin >> x[i][j].Num;
			x_cnt[i][j] = 0;
		}
	}
	BFS();
	cout << x_cnt[N - 1][M - 1];
}