#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <bitset>
using namespace std;

int main() {
	int N, M;
	cout << "���� �� �� ������?>>";
	cin >> N;
	cout << "������?>>";
	cin >> M;
	int isYong;
	cout << "(0 ~ N-1) or (1 ~ N) (0 �Ǵ� 1 �Է�)>>";
	cin >> isYong;
	vector<unsigned int> twoZinSu;
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		int Num = rand() % M + isYong;
		cout << Num << '\n';
		twoZinSu.push_back(Num);
	}
	cout << "������ ǥ��\n";
	for (int i = 0; i < twoZinSu.size(); i++) {
		cout << bitset<8>(twoZinSu.at(i)) << '\n';
	}
	cout << bitset<8>(46) << '\n' << bitset<8>(14) << '\n';
	cout << bitset<8>(46 & 14);

}