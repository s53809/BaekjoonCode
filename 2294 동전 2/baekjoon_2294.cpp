#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
ll DP[101][20001];
ll n, k;
ll cost[101];

ll getsu(ll N, ll K) {
	if (N == n && K == 0) {
		return 0;
	}
	if (N == n && K != 0) {
		return 2e9;
	} //만들 수 없을 때
	if (DP[N][K] != -1) {
		return DP[N][K];
	}
	if (K < cost[N]) {
		return DP[N][K] = getsu(N + 1, K);
	}//코인을 사용했을때 값을 초과할때
	else {
		return DP[N][K] = min(getsu(N + 1, K), 1 + getsu(N, K - cost[N]));
	}
	//코인을 사용하는 경우와 안사용하고 넘어가는 경우중 최솟값
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(DP, -1, sizeof(DP));
	cin >> n >> k;
	for (ll i = 0; i < n; i++) {
		cin >> cost[i];
	}
	ll ans = getsu(0, k);
	if (ans == 2e9) {
		cout << -1 << "\n";
	}
	cout << DP[0][k] << "\n";
}