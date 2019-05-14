//go always for one more try
#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a); i<b; i++)
#define mp std::make_pair

using namespace std;

vector<double> sol;
vector< vector<int> > g;
bool visited[100001];

void dfs(int p, int s, int d, double odds) {

    if (g[s].size() == 1 && s != 0 && p != -1 && visited[p]) {
        sol.push_back(d * odds);
    } else {

        FOR(i, 0, g[s].size()) {
            int v = g[s][i];
            if (!visited[v]) {
                visited[v] = true;
                if (s == 0)
                    dfs(s, v, d + 1, odds / g[s].size());
                else
                    dfs(s, v, d + 1, odds / (g[s].size() - 1));
            }
        }
    }

    return;
}

int main(int argc, char** argv) {
    int n;
    cin >> n;
    g.resize(n);
    sol.resize(0);

    FOR(i, 0, 100001)
    visited[i] = false;

    FOR(i, 0, n - 1) {
        int a, b;
        cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }

    double ev = 0;
    cout.precision(9);

    if (n != 1) {
        visited[0] = true;
        dfs(-1, 0, 0, 1);

        FOR(i, 0, sol.size()) {
            ev += sol[i];
        }
    }

    cout << fixed << ev;
    return 0;

}
