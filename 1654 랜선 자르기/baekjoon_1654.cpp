#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;

ll K, N;
vector<ll> x;

ll twobun(ll num) {
	ll mid = num, start = 0, end = num;
	ll lansonGetsu = 0;
	ll maxGillE = 0;
	while (start <= end) {
		for (int i = 0; i < K; i++) {
			lansonGetsu += x[i] / mid;
		}
		if (lansonGetsu < N) {
			end = mid - 1;
		}
		else if (lansonGetsu >= N) {
			if (maxGillE < mid) {
				maxGillE = mid;
			}
			start = mid + 1;
		}
		mid = (start + end) / 2;
		lansonGetsu = 0;
	}
	return maxGillE;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> K >> N;
	x.resize(K); 
	ll max = -1;
	for (int i = 0; i < K; i++) {
		cin >> x[i];
		if (max < x[i]) {
			max = x[i];
		}
	}
	cout << twobun(max);
}