#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REV(i,b,a) for(int i=(a);i>=(b);i--)
#define fillTab(a,v)                    memset(a, v, sizeof a)
#define MAX(a,b,c,d) max(a,max(b,max(c,d)))
#define pb push_back
#define mp make_pair
typedef vector< vector<int> > vvi;

vector<int> stalls;
vector<bool> picked;

bool doable(int, int, int);

int bound(int N, int C, int left, int right) {
    int solution = -1;
    int middle = -1;
    while (left < right) {
        middle = (left + right) / 2;
        if (!doable(middle, N, C))
            right = middle;
        else {
            solution = max(solution, middle);
            left = middle + 1;
        }
    }

    return solution;
}

bool doable(int sol, int N, int C) {
    int count = 1;
    for (int i = N - 1; i >= 1;) {
        int pos_ = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (stalls[i] - stalls[j] >= sol) {
                pos_ = j;
                count++;
                break;
            }
        }
        i = pos_;
    }
    return (count >= C);
}

int main() {

    //freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        int N, C;
        cin >> N >> C;
        stalls.resize(N);

        FOR(i, 0, N) {
            int x;
            cin >> x;
            stalls[i] = x;
        }

        std::sort(stalls.begin(), stalls.end());

        int max_ = -1;
        int min_ = 0;

        FOR(i, 1, N) {
            int diff = (int) (stalls[i] - stalls[i - 1]);
            min_ = min(min_, diff);
        }

        max_ = stalls[N - 1] - stalls[0] + 1;
        cout << bound(N, C, min_, max_);
        cout << endl;
    }
}
