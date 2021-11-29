#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	vector<int> x;
	cin >> N;
	x.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}
	//다음 순열 next_permutation
	int a =	prev_permutation(x.begin(), x.end());
	if (a == 1) {
		for (int i = 0; i < N; i++) {
			cout << x[i] << ' ';
		}
	}
	else {
		cout << "-1";
	}
}