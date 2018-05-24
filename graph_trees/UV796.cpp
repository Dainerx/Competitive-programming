#include <bits/stdc++.h>
#include <algorithm>
#include <set> 
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
    return s << t.first << " - " << t.second;
}

int dfsNumberCount, dfsRoot, root_children;
vvi adj;
vi dfs_num, dfs_low, dfs_parent;
vector<ii> bridges;

bool bridge_sort(ii x, ii y) {
    if (x.first == y.first)
        return x.second < y.second;
    else
        return x.first < y.first;
}

void articulationPB(int cur) {
    dfs_num[cur] = dfs_low[cur] = dfsNumberCount++;
    for (int i = 0; i < adj[cur].size(); i++) {
        int v = adj[cur][i];
        if (dfs_num[v] == -1) {
            dfs_parent[v] = cur;
            articulationPB(v);
            if (dfs_low[v] > dfs_num[cur]) {
                if (cur > v)
                    bridges.pb(mp(v, cur));
                else
                    bridges.pb(mp(cur, v));
            }

            dfs_low[cur] = min(dfs_low[v], dfs_low[cur]);

        } else if (v != dfs_parent[cur]) {
            dfs_low[cur] = min(dfs_num[v], dfs_low[cur]);
        }

    }

}

int main() {
    int N;
    //freopen("go.out", "w", stdout);
    while (scanf("%d", &N) != EOF) {
        adj.clear();
        adj.resize(N);

        FOR(index, 0, N) {
            int a, b, M;
            scanf("%d (%d)", &a, &M);

            FOR(m, 0, M) {
                cin >> b;
                adj[a].pb(b);
                adj[b].pb(a);
            }
        }

        dfsNumberCount = 0;
        dfs_low.assign(N, 0);
        dfs_num.assign(N, -1);
        dfs_parent.assign(N, -1);
        bridges.clear();

        FOR(i, 0, N) {
            dfsRoot = i;
            root_children = 0;
            if (dfs_num[i] == -1) {
                articulationPB(i);
            }
        }

        std::sort(all(bridges), bridge_sort);
        cout << bridges.size() << " critical links" << endl;

        FOR(i, 0, bridges.size()) {
            cout << bridges[i] << endl;
        }


        cout << endl;
    }

}
