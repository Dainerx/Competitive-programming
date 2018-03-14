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

#define fill(a,v)                    memset(a, v, sizeof a)
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


bool visited[401];
vector < vector<short> > adj;
short n, m;
long counter = 0;

void dfs(int cur) {
    counter++;
    visited[cur] = true;
    for (int i = 0; i < adj[cur].size(); i++) {
        int j = adj[cur][i];
        if (visited[j])
            continue;
        dfs(j);
    }
    return;
}

int main() {

    cin >> n >> m;

    adj.resize(n * m);
    int util[20][20];
    int c_ = 0;

    fill(util, 0);

    FOR(i, 0, n) {

        FORJ(j, 0, m) {
            util[i][j] = c_;
            c_++;
        }
    }


    char c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (c == '>') {
            for (int k = 0; k < m - 1; k++) {
                int x = k;
                adj.at(util[i][k]).pb(util[i][++x]);
            }
        } else {
            for (int k = m - 1; k > 0; k--) {
                int x = k;
                adj.at(util[i][k]).pb(util[i][--x]);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> c;
        if (c == 'v') {
            for (int k = 0; k < n - 1; k++) {
                int x = k;
                adj.at(util[k][i]).pb(util[++x][i]);
            }
        } else {
            for (int k = n - 1; k > 0; k--) {
                int x = k;
                adj.at(util[k][i]).pb(util[--x][i]);
            }
        }

    }



    dfs(0);
    int total = counter;

    FOR(i, 1, n * m) {
        fill(visited, false);
        counter = 0;
        dfs(i);
        if (counter != total) {
            cout << "NO";
            return 0;
        }
        total = counter;
    }

    cout << "YES";
    return 0;

}
