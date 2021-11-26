#include <iostream>
#include <vector>

int main() {
	using namespace std;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	int veryUri = INT_MIN;
	int veryUriNum = 0;
	int cnt = 1;
	while (cnt != N + 1) {
		int chessUri = 0;
		vector<int> myChess(5);
		vector<int> enemyChess(5);
		vector<int> gaChi;
		gaChi.push_back(1);
		gaChi.push_back(3);
		gaChi.push_back(4);
		gaChi.push_back(5);
		gaChi.push_back(9);
		for (int i = 0; i < 5; i++) {
			cin >> myChess[i];
		}
		for (int i = 0; i < 5; i++) {
			cin >> enemyChess[i];
		}
		for (int i = 0; i < 5; i++) {
			chessUri += (myChess[i] * gaChi[i]) - (myChess[i] * gaChi[i]);
		}
		if (veryUri < chessUri) {
			veryUri = chessUri;
			veryUriNum = cnt;
		}
		cnt++;
	}//Æù1, ³ªÀÌÆ®3, ºñ¼ó3, ·è5, Äý9
	cout << veryUriNum;
}