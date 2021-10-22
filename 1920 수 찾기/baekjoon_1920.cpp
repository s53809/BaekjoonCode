#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> x;
vector<int> ansX;

int twobun(int num) {
	int start, end, mid;
	start = 0;
	end = N - 1;
	bool istrue = false;
	while (start <= end) {
		mid = (start + end) / 2;
		if (x[mid] > num) {
			end = mid - 1;
		}
		else if (x[mid] < num) {
			start = mid + 1;
		}
		else {
			istrue = true;
			break;
		}
	}
	if (istrue == true) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	x.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}
	sort(x.begin(), x.end());
	vector<int> ansX;
	cin >> M;
	ansX.resize(M);
	for (int i = 0; i < M; i++) {
		cin >> ansX[i];
	}
	for (int i = 0; i < M; i++) {
		cout << twobun(ansX[i]) << '\n';
	}
}