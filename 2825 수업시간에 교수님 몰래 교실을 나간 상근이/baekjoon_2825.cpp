#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	vector<string> chinGu;
	chinGu.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> chinGu[i];
	}
	vector<int> numPad(10, 0);
	vector<bool> isZungBok(10, false);
	int	puRenDo = 0;
	bool isCheck = false;
	for (int i = 0; i < N; i++) {
		isZungBok.assign(10, false);
		isCheck = false;
		for (int j = 0; j < chinGu[i].size(); j++) {
			if (j >= 1) {
			}
			if (isZungBok[chinGu[i][j] - 48] == false) {
				numPad[chinGu[i][j] - 48]++;
				isZungBok[chinGu[i][j] - 48] = true;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		if (numPad[i] != 0) {
			puRenDo += numPad[i] - 1;
		}
	}
	cout << puRenDo;
} // 상근이 누군진 몰라도 저주한다