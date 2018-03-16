#include <cmath>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <complex>
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

int n, m, numSCC, dfsNumberCount;

vvi adj;

vi dfs_num, dfs_low, stock;
bool visited[1001];

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
        ++numSCC;
        while (1) {
            int v = stock.back();
            stock.pop_back();
            visited[v] = false;
            if (cur == v) break;
        }
    }
}

int main() {

    while (cin >> n >> m) {
        if (n == m && n == 0)
            break;

        adj.resize(n);
        adj.clear();
        fillTab(visited, false);
        dfs_low.assign(n, 0);
        dfs_num.assign(n, -1);
        numSCC = dfsNumberCount = 0;
        stock.clear();

        map<string, int> names;

        FOR(i, 0, n) {
            string s, s1;
            cin >> s;
            cin >> s1;
            string toinsert = s + s1;
            names.insert(mp(toinsert, i));
        }

        FOR(i, 0, m) {
            string s, s1;
            cin >> s;
            cin >> s1;
            string toInsertAt = s + s1;
            cin >> s;
            cin >> s1;
            string toInsertTo = s + s1;
            adj[names.at(toInsertAt)].pb(names.at(toInsertTo));
        }

        FOR(i, 0, n) {
            if (dfs_num[i] == -1)
                SCC(i);
        }

        cout << numSCC << endl;
    }
    return 0;
}
