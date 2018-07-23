#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REV(i,b,a) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back
#define fillTab(a,v)                    memset(a, v, sizeof a)
#define all(a)                      a.begin(), a.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector< vector<ii> > vw;
typedef long long ll;


vvi adj;
vi p, rank;

int findSet(int i) {
    return (i == p[i]) ? i : (p[i] = findSet(p[i]));
}

bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
}

void unionSet(int i, int j) {
    if (!(isSameSet(i, j))) {
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) {
            p[y] = x;
        } else {
            p[x] = y;
            if (rank[x] == rank[y])
                rank[y]++;
        }
    }
}

int main() {

    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        int N;
        scanf("\n%d\n", &N);
        p.assign(N, 0);
        rank.assign(N, 0);
        FOR(i, 0, N)
        p[i] = i;

        int uns, su;
        uns = su = 0;
        string s;

        while (1) {
            if (!getline(cin, s) || s.empty()) break;
            char c;
            int x, y;
            std::stringstream ss(s);
            ss >> c >> x >> y;
            if (c == 'c')
                unionSet(x, y);
            else {
                if (isSameSet(x, y))
                    su++;
                else
                    uns++;
            }
        }

        if (t != 1) printf("\n");
        printf("%d,%d\n", su, uns);

    }


    return 0;
}
