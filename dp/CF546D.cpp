//go always for one more try
#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < b; i++)
#define mp std::make_pair

using namespace std;

const int MAXN = 5000001;
long dp[MAXN];
void buildPFCount()
{
    for (int i = 2; i < MAXN; i++)
        dp[i] = 1;
    // even
    for (int i = 4, j = 2; i < MAXN; i += 2, j++)
        dp[i] = dp[i / 2] + 1;

    for (int i = 3; i * i < MAXN; i++)
    {
        // checking if i is prime
        if (dp[i] == 1)
        {
            for (int j = i * i; j < MAXN; j += i)
                dp[j] = dp[j / i] + 1;
        }
    }
}

int main(int argc, char **argv)
{
    dp[1] = 1;
    vector<long> dp2(MAXN);
    buildPFCount();
    dp2[1] = 1;
    FOR(i, 2, MAXN)
    {
        dp2[i] = dp2[i - 1] + dp[i];
    }
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        long sol = dp2[a] - dp2[b];
        cout << sol << "\n";
    }
    return 0;
}
