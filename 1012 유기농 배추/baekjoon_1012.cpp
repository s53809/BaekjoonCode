#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> x;
int M, N, K;
int d_x[] = { -1,1,0,0 };
int d_y[] = { 0,0,-1,1 };

void BFS(int xPos, int yPos) {
	x[yPos][xPos] = 0;
	queue<pair<int, int>> qu;
	qu.push(make_pair(yPos, xPos));
	while (!qu.empty()) {
		for (int i = 0; i < 4; i++) {
			int dir_y = qu.front().first + d_y[i];
			int dir_x = qu.front().second + d_x[i];
			if (dir_y >= 0 && dir_y < N && dir_x >= 0 && dir_x < M) {
				if (x[dir_y][dir_x] == 1) {
					qu.push(make_pair(dir_y, dir_x));
					x[dir_y][dir_x] = 0;
				}
			}
		}
		qu.pop();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T > 0) {
		cin >> M >> N >> K;
		x.resize(N);
		for (int i = 0; i < N; i++) {
			x[i].resize(M);
			for (int j = 0; j < M; j++) {
				x[i][j] = 0;
			}
		}
		for (int i = 0; i < K; i++) {
			int xPos, yPos;
			cin >> xPos >> yPos;
			x[yPos][xPos] = 1;
		}
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (x[i][j] == 1) {
					BFS(j, i);
					ans++;
				}
			}
		}
		cout << ans << '\n';
		T--;
	}
}