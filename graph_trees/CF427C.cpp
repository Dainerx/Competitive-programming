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

int n, m, dfsNumberCount;

vvi adj;
ll totalCost = 0, numSCC = 0;
vi dfs_num, dfs_low, stock, costs, ways, holder;
bool visited[100001];

int fact(int x) {
    if (x == 0)
        return 1;
    else
        return x * fact(x - 1);
}

void SCC(int cur) {
    visited[cur] = true;
    dfs_num[cur] = dfs_low[cur] = dfsNumberCount++;
    stock.pb(cur);
    for (int i = 0; i < adj[cur].size(); i++) {
        int v = adj[cur][i];
        if (dfs_num[v] == -1)
            SCC(v);
        if (visited[v])
            dfs_low[cur] = min(dfs_low[v], dfs_low[cur]);
    }
    if (dfs_low[cur] == dfs_num[cur]) {
        int possibleWays = 0;
        int min_ = INT_MAX;
        holder.clear();
        while (1) {
            int v = stock.back();
            stock.pop_back();
            visited[v] = false;
            holder.pb(costs[v]);
            min_ = min(min_, costs[v]);
            if (cur == v) break;
        }
        possibleWays += std::count(all(holder), min_);

        if (possibleWays)
            ways.pb(possibleWays);
        totalCost += ll(min_);
    }
}

int main() {



    cin >> n;
    adj.resize(n);
    fillTab(visited, false);
    dfs_low.assign(n, 0);
    dfs_num.assign(n, -1);
    costs.assign(n, -1);
    dfsNumberCount = 0;

    FOR(i, 0, n) {
        int a;
        cin >> a;
        costs[i] = a;
    }

    cin >> m;

    FOR(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
    }

    FOR(i, 0, n) {
        if (dfs_num[i] == -1)
            SCC(i);
    }

    const ll mod = 1000000007;
    ll ways_ = 1;

    FOR(i, 0, ways.size()) {
        ways_ *= ll(ways[i]);
    }

    ways_ %= mod;
            cout << totalCost << " " << ways_;

}
