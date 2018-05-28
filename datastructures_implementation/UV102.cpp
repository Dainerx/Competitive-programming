#include <bits/stdc++.h>
#include <algorithm>
#include <set>
#include <queue> 
using namespace std;

#define MAX(a,b,c) max(a,max(b,c))
#define MIN(a,b,c) min(a,min(b,c))

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORJ(j,a,b) for(int j=(a);j<(b);j++)
#define REV(i,b,a) for(int i=(a);i>=(b);i--)

#define mp make_pair
#define pb push_back

#define fillTab(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))

#define all(a)                      a.begin(), a.end()
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector< vector<ii> > vw;
typedef long long ll;

bool mycomp(char c1, char c2) {
    return std::tolower(c1) < std::tolower(c2);
}

template<typename T, typename TT> ostream& operator<<(ostream &s, pair<T, TT> t) {
    return s << t.first << " - " << t.second;
}


vi B, G, C;
int start[3];

bool customSort(std::pair<int, string> x, std::pair<int, string> y) {
    if (x.first == y.first) {
        return x.second < y.second;
    }
    return x.first < y.first;
}

int find(int b_, int g_, int c_) {
    int cost = 0;

    FOR(i, 0, 3) {
        if (i == b_)
            continue;
        cost += B[i];
    }

    FOR(i, 0, 3) {
        if (i == g_)
            continue;
        cost += G[i];
    }

    FOR(i, 0, 3) {
        if (i == c_)
            continue;
        cost += C[i];
    }
    return cost;
}

int main() {
    int b;
    while (scanf("%d", &b) != EOF) {
        vector< std::pair<int, string> > v;
        B.clear();
        G.clear();
        C.clear();
        B.pb(b);
        int g;
        cin >> g;
        G.pb(g);
        int c;
        cin >> c;
        C.pb(c);

        FOR(i, 0, 2) {
            int b;
            cin >> b;
            B.pb(b);
            int g;
            cin >> g;
            G.pb(g);
            int c;
            cin >> c;
            C.pb(c);
        }

        string bins[3];
        bins[0] = "B";
        bins[1] = "G";
        bins[2] = "C";

        FOR(i, 0, 3) {
            start[i] = i;
        }

        int min_ = INT_MAX;
        string solution;
        do {
            int b_ = std::find(start, start + 3, 0) - start;
            int g_ = std::find(start, start + 3, 1) - start;
            int c_ = std::find(start, start + 3, 2) - start;
            if (min_ >= find(b_, g_, c_)) {
                min_ = find(b_, g_, c_);
                solution = bins[start[0]] + bins[start[1]] + bins[start[2]];
                v.pb(mp(min_, solution));
            }
        } while (std::next_permutation(start, start + 3));


        std::sort(all(v), customSort);
        cout << v[0].second << " " << min_ << endl;
    }
}
