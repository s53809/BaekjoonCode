#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;

vector<vector<int>> x;
bool*** visited = new bool** [2];
int d_x[] = { 0,0,-1,1 };
int d_y[] = { -1,1,0,0 };
int*** dist = new int** [2];
typedef struct zwaPyo {
	int x;
	int y;
	bool isBreak = false;
};

void BFS(zwaPyo SoHardVariableName) {
	queue<zwaPyo> qu;
	qu.push(SoHardVariableName);
	while (!qu.empty()) {
		zwaPyo box = qu.front();
		qu.pop();
		for (int i = 0; i < 4; i++) {
			int dir_x = box.x + d_x[i];
			int dir_y = box.y + d_y[i];
			if (dir_x >= 0 && dir_x < M && dir_y >= 0 && dir_y < N) {
				if (x[dir_y][dir_x] == 1) {
					if (box.isBreak == false && visited[0][dir_y][dir_x] == false) {
						visited[1][dir_y][dir_x] = true;
						dist[1][dir_y][dir_x] = dist[0][box.y][box.x] + 1;
						zwaPyo bax;
						bax.isBreak = true;
						bax.x = dir_x;
						bax.y = dir_y;
						qu.push(bax);
					}
				}
				else {
					if (visited[box.isBreak][dir_y][dir_x] == false) {
						visited[box.isBreak][dir_y][dir_x] = true;
						dist[box.isBreak][dir_y][dir_x] = dist[box.isBreak][box.y][box.x] + 1;
						zwaPyo bax;
						bax.isBreak = box.isBreak;
						bax.x = dir_x;
						bax.y = dir_y;
						qu.push(bax);
					}
				}
				if (dir_x == M - 1 && dir_y == N - 1) {
					printf("%d", dist[box.isBreak][box.y][box.x] + 1);
					return;
				}
			}
		}
	}
	printf("-1");
	return;
}

int main() {
	scanf("%d %d", &N, &M);
	x.resize(N);
	dist[0] = new int* [N];
	dist[1] = new int* [N];
	visited[0] = new bool* [N];
	visited[1] = new bool* [N];
	for (int i = 0; i < N; i++) {
		dist[0][i] = new int[M];
		dist[1][i] = new int[M];
		visited[0][i] = new bool[M];
		visited[1][i] = new bool[M]; 
	}
	for (int i = 0; i < N; i++) {
		x[i].resize(M);
		for (int j = 0; j < M; j++) {
			dist[0][i][j] = 0;
			dist[1][i][j] = 0;
			visited[0][i][j] = false;
			visited[1][i][j] = false;
			scanf("%1d", &x[i][j]);
		}
	}
	dist[0][0][0] = 1;
	dist[1][0][0] = 1;
	zwaPyo ah;
	ah.isBreak = false;
	ah.x = 0;
	ah.y = 0;
	if (N == 1 && M == 1) {
		printf("1");
		return 0;
	}
	BFS(ah);
	return 0;
}