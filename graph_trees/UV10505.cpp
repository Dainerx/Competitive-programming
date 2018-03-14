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

int n;
vvi adj;
int colors[300];
bool visited[300];
bool isBiPart;

void enemies(int cur) {
    visited[cur] = true;

    FOR(i, 0, adj.at(cur).size()) {
        int v = adj[cur][i];
        if (colors[v] != -1) {
            if (colors[v] == colors[cur]) {
                isBiPart = false;
            }
        } else
            colors[v] = 1 - colors[cur];
        if (visited[v] == false)
            enemies(v);
    }
    return;
}

int main() {

    int M;
    cin >> M;
    while (M--) {
        cin >> n;
        adj.resize(300);
        fillTab(visited, false);

        FOR(i, 0, n) {
            int e;
            cin >> e;

            FORJ(j, 0, e) {
                int a;
                cin >> a;
                adj[i].pb(--a);
                adj[a].pb(i);
            }
        }

        int total = 0;

        FOR(i, 0, n) {
            if (visited[i] == false) {
                fillTab(colors, -1);
                isBiPart = true;
                colors[i] = 0;
                enemies(i);
                if (isBiPart) {
                    int counter_0, counter_1; //
                    counter_0 = counter_1 = 0;

                    FOR(c, 0, n) {
                        if (colors[c] == 0)
                            counter_0++;
                        else if (colors[c] == 1)
                            counter_1++;
                    }
                    total += max(counter_0, counter_1);
                }
            }
        }
        cout << total;
        cout << endl;
        adj.clear();
    }
    return 0;
}
