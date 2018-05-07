#include <bits/stdc++.h>
#include <algorithm> 
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

bool mycomp(char c1, char c2) {
    return std::tolower(c1) < std::tolower(c2);
}

template<typename T, typename TT> ostream& operator<<(ostream &s, pair<T, TT> t) {
    return s << "(" << t.first << "," << t.second << ")";
}


vvi adj;
bool visited[50001];
int sum[50001];

int dfs(int u) {
    visited[u] = true;
    int tot = 0;
    for (int i = 0; i < adj[u].size(); i++) {
        int cur = adj[u][i];
        if (!visited[cur]) {
            tot += 1 + dfs(cur);
        }
    }
    visited[u] = false;
    return sum[u] = tot;
}

int main() {

    int T;
    cin >> T;

    FOR(i, 0, T) {
        fillTab(sum, -1);
        fillTab(visited, false);
        adj.clear();
        int N;
        cin >> N;
        adj.resize(N);

        FOR(k, 0, N) {
            int a;
            int b;
            cin >> a >> b;
            adj[--a].pb(--b);
        }
        
        int result = -1;
        int index_result = -1;

        FOR(k, 0, N) {
            if (sum[k] == -1) {

                if (result < dfs(k)) {
                    result = dfs(k);
                    index_result = k;
                }
            }
        }
        
        int case_ = i;
        cout << "Case " << ++case_ << ": "  <<  ++index_result << endl;
    }

}
