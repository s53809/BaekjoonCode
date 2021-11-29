#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	vector<int> x(N);
	for (int i = 0; i < N; i++) {
		x[i] = i + 1;
	}
	do {
		for (int i = 0; i < N; i++) {
			cout << x[i] << ' ';
		}
		cout << '\n';
	} while (next_permutation(x.begin(), x.end()));
}