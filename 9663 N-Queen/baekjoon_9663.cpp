#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>>x;
int N, ans = 0;

int Gomsa(int xPos, int yPos) {
	if (xPos == 0) {
		return 1;
	}
	for (int i = 0; i < N; i++) {
		if (x[yPos][i] == 1) {
			return 0;
		}
		if (x[i][xPos] == 1) {
			return 0;
		}
	}
	int xcpy = xPos, ycpy = yPos;
	while (xcpy > 0 && ycpy > 0) {
		xcpy--;
		ycpy--;
		if (x[ycpy][xcpy] == 1) {
			return 0;
		}
	}
	xcpy = xPos;
	ycpy = yPos;
	while (xcpy > 0 && ycpy < N - 1) {
		xcpy--;
		ycpy++;
		if (x[ycpy][xcpy] == 1) {
			return 0;
		}
	}
	return 1;
}

void nQueen(int xStep) {
	if (xStep >= N) {
		ans++;
		return;
	}
	for (int i = 0; i < N; i++) {
		x[i][xStep] = 0;
	}
	for (int i = 0; i < N; i++) {
		if (Gomsa(xStep, i) == 1) {
			x[i][xStep] = 1;
			nQueen(xStep + 1);
			x[i][xStep] = 0;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	x.resize(N);
	for (int i = 0; i < N; i++) {
		x[i].resize(N);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			x[i][j] = 0;
		}
	}
	x[0][0] = 1;
	nQueen(0);
	cout << ans;
}