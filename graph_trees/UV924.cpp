#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REV(i,b,a) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back
#define fillTab(a,v)                    memset(a, v, sizeof a)
#define all(a)                      a.begin(), a.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector< vector<ii> > vw;
typedef long long ll;

vvi adj;
int boom[2501];
vi distances;
vi p;
int ans = 0;

void printPath(int u, int s) {
    if (u == s) {
        return;
    }
    printPath(p[u], s);
}

void SSSP(int E, int s) {
    ii ans = mp(-1, -1);
    p.resize(E);
    distances.assign(E, -1);
    distances[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        FOR(i, 0, adj[u].size()) {
            int v = adj[u][i];
            if (distances[v] == -1) {
                int dadd = distances[u] + 1;
                boom[dadd] += 1;
                if (ans.first < boom[dadd]) {
                    ans.first = boom[dadd];
                    ans.second = dadd;
                }
                distances[v] = dadd;
                p[v] = u;
                q.push(v);
            }
        }
    }

    if (ans.first != -1 && ans.second != -1)
        cout << ans.first << " " << ans.second << endl;
    else
        cout << 0 << endl;

}

int main() {

    int E;
    cin >> E;
    adj.resize(E);

    FOR(i, 0, E) {
        int M;
        cin >> M;

        FOR(c, 0, M) {
            int e;
            cin >> e;
            adj[i].pb(e);
        }
    }
    int T;
    cin >> T;
    while (T--) {
        fillTab(boom, 0);
        ans = 0;
        int s;
        cin >> s;
        SSSP(E, s);
    }

    return 0;
}
