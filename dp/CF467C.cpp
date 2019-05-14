//go always for one more try
#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a); i<b; i++)
#define mp std::make_pair

using namespace std;

int main(int argc, char** argv) {


    int n, m, k;
    cin >> n >> m >> k;

    vector< vector<long long> > dp;
    dp.resize(n);

    FOR(i, 0, n) {
        dp[i].resize(k + 1);
    }

    long long * arr = new long long[n];
    FOR(i, 0, n)
    cin >> arr[i];

    FOR(i, 0, m - 1) {

        FOR(j, 0, k + 1) {
            dp[i][j] = 0;
        }
    }

    long long acc = 0;
    FOR(i, 0, m)
    acc += arr[i];
    dp[m - 1][0] = 0;
    FOR(i, 0, n)
    dp[i][0] = 0;
    FOR(j, 1, k + 1)
    dp[m - 1][j] = acc;

    FOR(i, m, n) {
        acc -= arr[i - m];
        acc += arr[i];

        FOR(c, 1, k + 1) {
            dp[i][c] = max(dp[i - 1][c], dp[i - m][c - 1] + acc);
        }
    }


    cout << dp[n - 1][k];
}
