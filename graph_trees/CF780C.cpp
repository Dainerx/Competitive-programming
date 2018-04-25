// Graph coloring Level 4
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

int result = -1;
vector<vector<int> > adj;
vector<int> color;
int n;
bool visited[200010];

void dfs(int cur, int last) {
    int colPossible = 0;
    visited[cur]=true;
    for (int i = 0; i < adj[cur].size(); i++) {
        if (adj[cur][i] != last) {
            while (1) {
                if (colPossible == color[cur] || colPossible == color[last])
                    colPossible++;
                else
                    break;
            }
            result = max(result,colPossible);
            color[adj[cur][i]] = colPossible++;
        }
    }

    for (int i = 0; i < adj[cur].size(); i++) {
        if(adj[cur][i]!=last)
            dfs(adj[cur][i],cur);
    }
    return;
}

int main() {
    fillTab(visited, false);
    cin >> n;
    adj.resize(n);
    color.resize(n);

    FOR(i, 0, n - 1) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        color.at(a) = -1;
        color.at(b) = -1;
        adj.at(a).pb(b);
        adj.at(b).pb(a);
    }
    color[0] = 0;
    dfs(0, 0);

    cout << ++result << endl;

    FOR(i, 0, n) {
        int x = color.at(i);
        cout << ++x << " ";
    }

    return 0;
}
