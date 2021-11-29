#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'A') {
			cout << 'a';
		}
		else if (str[i] == 'B') {
			cout << 'v';
		}
		else if (str[i] == 'E') {
			cout << "ye";
		}
		else if (str[i] == 'K') {
			cout << 'k';
		}
		else if (str[i] == 'M') {
			cout << 'm';
		}
		else if (str[i] == 'H') {
			cout << 'n';
		}
		else if (str[i] == 'O') {
			cout << 'o';
		}
		else if (str[i] == 'P') {
			cout << 'r';
		}
		else if (str[i] == 'C') {
			cout << 's';
		}
		else if (str[i] == 'T') {
			cout << 't';
		}
		else if (str[i] == 'Y') {
			cout << 'u';
		}
		else if (str[i] == 'X') {
			cout << 'h';
		}
	}
	cout << '\n';
}