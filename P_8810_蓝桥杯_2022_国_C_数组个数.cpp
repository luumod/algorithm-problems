#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
const int MOD = 1e9 + 7;

int n;
int dp[N][11][2][2][11], b[N], am[N];
int st;

inline int nxt (int idx) {
	return ((idx + 1) % n);
}

inline int pre (int idx) {
	return ((idx - 1 + n) % n);
}

int m (int x) {
	if (x < MOD) return x;
	return x - MOD;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i = 0;i < n;i++) cin >> b[i];
	for (int i = 0;i < n;i++) am[i] = min(b[pre(i)], min(b[i], b[nxt(i)]));
	for (int i = 0;i <= am[0];i++) if (i < b[0]) dp[0][i][0][0][i] = 1; else dp[0][i][1][1][i] = 1;
	for (int x = 0;x <= am[0];x++) for (int st = 0;st <= 1;st++) for (int j = 0;j <= am[1];j++) {
		if (j < b[1] && x < b[1]) {
			if (j < b[0]) dp[1][j][0][st][x] += m(dp[0][x][0][st][x] + dp[0][x][1][st][x]), dp[1][j][0][st][x] = m(dp[1][j][0][st][x]);
			else dp[1][j][0][1][x] += m(dp[0][x][0][st][x] + dp[0][x][1][st][x]), dp[1][j][0][1][x] = m(dp[1][j][0][1][x]);
		}
		else {
			if (j < b[0]) dp[1][j][1][st][x] += m(dp[0][x][0][st][x] + dp[0][x][1][st][x]), dp[1][j][1][st][x] = m(dp[1][j][1][st][x]);
			else dp[1][j][1][1][x] += m(dp[0][x][0][st][x] + dp[0][x][1][st][x]), dp[1][j][1][1][x] = m(dp[1][j][1][1][x]);
		}
	}
	for (int i = 2;i < n;i++) {
		int p = i - 1;
		for (int x = 0;x <= am[0];x++) for (int st = 0;st <= 1;st++) {
			for (int j = 0;j <= am[i];j++) {
				for (int z = 0;z <= am[p];z++) {
					if (j < b[i] && z < b[i]) {
						if (j < b[p]) dp[i][j][0][st][x] += dp[p][z][1][st][x];else dp[i][j][0][st][x] += m(dp[p][z][0][st][x] + dp[p][z][1][st][x]);
						dp[i][j][0][st][x] = m(dp[i][j][0][st][x]);
					}
					else {
						if (j < b[p]) dp[i][j][1][st][x] += dp[p][z][1][st][x];
						else dp[i][j][1][st][x] += m(dp[p][z][0][st][x] + dp[p][z][1][st][x]);
						dp[i][j][1][st][x] = m(dp[i][j][1][st][x]);
					}
				}
			}
		}
	}
	int ans = 0;
	for (int x = 0;x <= am[0];x++) for (int i = 0;i <= am[n - 1];i++) {
		ans += dp[n - 1][i][1][1][x]; ans = m(ans);
		if (i >= b[0]) ans += dp[n - 1][i][1][0][x];
		if (x >= b[n - 1]) ans += dp[n - 1][i][0][1][x];
		ans = m(ans);
	}
	cout << ans << endl;
	return 0;
} 