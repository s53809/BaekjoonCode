#include <iostream>
#include <vector>
#include <algorithm>

int N, C;
std::vector<int> x;

int main() {
	using namespace std;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> C;
	x.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}
	sort(x.begin(), x.end());
	int low = 0;
	int high = x[N - 1];
	int count = 0;
	int box = 1;
	int answer = 0;
	while (true) {
		int mid = (low + high) / 2;
		for (int i = box + 1; i < N; i++) {
			if (x[i] - x[box] >= mid) {
				box = i;
				count++;
			}
		}
		if (count > C) {
			low = mid;
		}
		else if (count < C) {
			high = mid;
		}
		else {
			answer = mid;
			break;
		}
	}
	cout << answer;
}