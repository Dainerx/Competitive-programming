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

vector<vector<int> > adj;
int n, m;
bool visited[150000];
bool flag = true;

void dfs(int cur, int last) {
    visited[cur] = true;
    if (last != -1) {
        if (adj[cur].size() == adj[last].size()) {
            for (int i = 0; i < adj[cur].size(); i++) {
                int j = adj[cur][i];
                if (std::find(adj[last].begin(), adj[last].end(), j) != adj[last].end())
                    continue;
                else if (j == last)
                    continue;
                else {
                    flag = false;
                    break;
                }
            }
        } else
            flag = false;
    }
    for (int i = 0; i < adj[cur].size(); i++) {
        if (visited[adj[cur][i]] != true)
            dfs(adj[cur][i], cur);
    }
    return;
}

int main() {
    fillTab(visited, false);
    cin >> n;
    cin >> m;
    adj.resize(n);

    FOR(i, 0, m) {
        int a, b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }

    for (int i = 0; i < n; i++) {
        if (adj[i].size() > 0) {
            if (visited[i] == false)
                dfs(i, -1);
        }
    }

    if (flag)
        cout << "YES";
    else
        cout << "NO";



    return 0;
}
