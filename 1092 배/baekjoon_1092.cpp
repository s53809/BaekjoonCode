#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int i, int j) {
	return j < i;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, high = 0;
	vector<int> cMax;
	cin >> N;
	cMax.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> cMax[i];
		if (high < cMax[i]) {
			high = cMax[i];
		}
	}
	sort(cMax.begin(), cMax.end());
	vector<int> cant;
	cant.resize(N);
	cant[N - 1] = 1;
	for (int i = 0; i < cant.size() - 1; i++) {
		cant[i] = cMax[i - 1] + 1;
	}
	cin >> M;
	vector<int> kg;
	kg.resize(M);
	bool notPick = false;
	for (int i = 0; i < M; i++) {
		cin >> kg[i];
		if (high < kg[i]) {
			notPick = true;
		}
	}
	if (notPick == true) {
		cout << "-1";
		return 0;
	}
	sort(kg.begin(), kg.end(), compare);
	int cnt = 0;
	vector<int> x(0);
	x.resize(N);
	for (int i = 0; i < kg.size(); i++) {
		if (kg[i] < cant[cnt]) {
			cnt++;
		}
		x[cnt]++;
	}
	for (int i = 0; i < x.size(); i++) {
		for (int j = i + 1; j < x.size(); j++) {
			if (x[i] > x[j]) {
				
			}
		}
	}
}