#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int> x;
	string str;
	cin >> str;
	x.resize(10);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] - 48 == 6) {
			x[9]++;
		}
		else {
			x[str[i] - 48]++;
		}
	}
	int box = 0;
	for (int i = 0; i < x.size(); i++) {
		if (i == 9) {
			if (x[i] % 2 == 1) {
				if ((x[i] / 2 + 1) > box) {
					box = x[i] / 2 + 1;
				}
			}
			else {
				if ((x[i] / 2 + 1) > box) {
					box = x[i] / 2;
				}
			}
		}
		else if (x[i] > box) {
			box = x[i];
		}
	}
	cout << box;
	return 0;
}