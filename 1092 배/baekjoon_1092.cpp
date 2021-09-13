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
	int N;
	cin >> N;
	vector<int> crain;
	for (int i = 0; i < N; i++) {
		int crain_Num;
		cin >> crain_Num;
		crain.push_back(crain_Num);
	}
	int M;
	cin >> M;
	vector<int> box;
	for (int i = 0; i < M; i++) {
		int box_Num;
		cin >> box_Num;
		box.push_back(box_Num);
	}
	box.resize(M);
	crain.resize(N);
	sort(box.begin(), box.end(), compare);
	sort(crain.begin(), crain.end(), compare);
	if (crain[0] < box[0]) {
		cout << "-1";
		return 0;
	}
	int day = 0;
	while (!box.empty()) {
		day++;
		for (int i = 0; i < crain.size(); i++) {
			for (int j = 0; j < box.size(); j++) {
				if (box[j] > crain[i]) {
					continue;
				}
				else {
					box.erase(box.begin() + j);
					break;
				}
			}
		}
	}
	cout << day;
	return 0;
}