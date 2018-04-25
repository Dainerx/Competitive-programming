#include <bits/stdc++.h> 
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
vi ts;
bool visited[101];

void dfs(int src) {
    visited[src] = true;
    for (int i = 0; i < adj[src].size(); i++) {
        int cur = adj[src][i];
        if (!visited[cur])
            dfs(cur);
    }
    ts.pb(src);
}

int main() {

    while (1) {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0)
            break;
        ts.clear();
        adj.clear();
        fillTab(visited, false);
        adj.resize(n);

        FOR(i, 0, m) {
            int a, b;
            cin >> a >> b;
            adj[--a].pb(--b);
        }

        FOR(i, 0, n) {
            if (!visited[i]) 
                dfs(i);

        }
        
        REV(i, 0, ts.size()-1) {
            cout << ++ts[i] << " ";
        }
        cout << endl;
    }

}
