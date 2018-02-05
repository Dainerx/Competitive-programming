#include <iostream>
#include <math.h>
#include <valarray>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

int qua[70], dp[1000001];

bool quasi(int n) {
    int x;
    while (n) {
        if (n % 10 > 1)
            return false;
        n /= 10;
    }
    return true;
}

int main() {

    int n, x = 0;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (quasi(i))
            qua[x++] = i;
    }


    memset(dp, 67, sizeof dp);
    dp[1] = 1;
    dp[0] = 0;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < x; j++) {
            if (i >= qua[j] && dp[i - qua[j]] + 1 < dp[i])
                dp[i] = dp[i - qua[j]] + 1;
        }
    }

    cout << dp[n] << endl;

    int n_ = n;
    int dpn_ = dp[n];
    while(n_>0)
    {
        for (int i=0; i<x; i++)
        {
            if (n_ >= qua[i] && dp[n_-qua[i]] + 1 <= dpn_)
            {
                cout << qua[i] << " ";
                n_-=qua[i];
                dpn_--;
            }
        }
    }

    return 0;
}
