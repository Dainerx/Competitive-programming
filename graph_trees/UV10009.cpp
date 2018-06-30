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
map<string, int> cities;
vector<string> names;
vi distances;
vi p;

void printPath(int u, int s) {
    if (u == s) {
        cout << names[u].substr(0, 1);
        return;
    }
    printPath(p[u], s);
    cout << names[u].substr(0, 1);
}

void SSSP(int count, int s, int t) {
    p.resize(count + 1);
    distances.assign(count + 1, -1);
    distances[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        FOR(i, 0, adj[u].size()) {
            int v = adj[u][i];
            if (distances[v] == -1) {

                distances[v] = distances[u] + 1;
                p[v] = u;
                q.push(v);
            }

        }
    }

    printPath(t, s);
}

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        cities.clear();
        adj.clear();
        adj.resize(N * 2); //stupid but still gets you accepted; waste of memory
        names.clear();
        names.resize(N * 2); //stupid but still gets you accepted; waste of memory

        int id = -1;

        FOR(i, 0, N) {
            string s1, s2;
            int id1, id2;
            cin >> s1 >> s2;
            if (cities.find(s1) != cities.end())
                id1 = cities.find(s1)->second;
            else {
                cities.insert(mp(s1, ++id));
                id1 = id;
                names[id1] = s1;
            }

            if (cities.find(s2) != cities.end())
                id2 = cities.find(s2)->second;
            else {

                cities.insert(mp(s2, ++id));
                id2 = id;
                names[id2] = s2;
            }

            adj[id1].pb(id2);
            adj[id2].pb(id1);
        }

        FOR(i, 0, M) {
            string s1, s2;
            cin >> s1 >> s2;
            SSSP(id, cities.at(s1), cities.at(s2));
            cout << endl;
        }

        if (T != 0)
            cout << endl;
    }

    return 0;
}
