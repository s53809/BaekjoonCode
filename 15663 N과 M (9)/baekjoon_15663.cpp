#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, num[8], result[8];
bool visited[8];

void backTracking(int count) {
	if (count == M) {
		for (int i = 0; i < M; i++) {
			cout << result[i] << ' ';
		}
		cout << '\n';
		return;
	}
	int prev_num = -1;
	
	for (int i = 0; i < N; i++) {
		if (!visited[i] && prev_num != num[i]) {
			visited[i] = true;
			result[count] = num[i];
			prev_num = num[i];
			backTracking(count + 1);
			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num, num + N);
	backTracking(0);
	return 0;
}