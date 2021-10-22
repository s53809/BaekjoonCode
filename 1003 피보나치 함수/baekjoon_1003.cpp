#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ansX;
vector<pair<int, int>> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	ansX.resize(T);
	int max = 0;
	for (int i = 0; i < T; i++) {
		cin >> ansX[i];
		if (max < ansX[i]) {
			max = ansX[i];
		}
	}
	ans.push_back(make_pair(1, 0));
	ans.push_back(make_pair(0, 1));
	for (int i = 2; i <= max; i++) {
		ans.push_back(make_pair(ans[i - 2].first + ans[i - 1].first, ans[i - 2].second + ans[i - 1].second));
	}
	for (int i = 0; i < T; i++) {
		cout << ans[ansX[i]].first << ' ' << ans[ansX[i]].second << '\n';
	}
	return 0;
}