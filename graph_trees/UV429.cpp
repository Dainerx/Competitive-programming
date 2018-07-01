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
vi distances;
vi p;

int SSSP(int N, int s, int d) {
    p.resize(N);
    distances.assign(N, -1);
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

    return distances[d];
}

int main() {

    //freopen("test.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        map<string, int> indexes;
        vector<string> words;
        string word;
        int index = 0;
        while (cin >> word) {
            if (word == "*")
                break;
            words.pb(word);
            indexes.insert(mp(word, index++));
        }

        adj.clear();
        adj.resize(index + 1);

        FOR(i, 0, words.size()) {
            string word1 = words[i];

            FOR(j, i + 1, words.size()) {
                string word2 = words[j];
                if (word1.size() == word2.size()) {
                    int c = 0;

                    FOR(k, 0, word1.size()) {
                        if (word1[k] != word2[k])
                            c++;
                    }
                    if (c == 1) {
                        int id1 = indexes.at(word1);
                        int id2 = indexes.at(word2);
                        adj[id1].pb(id2);
                        adj[id2].pb(id1);
                    }
                }
            }
        }

        cin.ignore();
        string line;
        while (getline(cin, line) && line != "") {
            stringstream ss(line);
            string s, d;
            ss >> s >> d;

            if (s == "")
                break;
            cout << s << " " << d << " " << SSSP(index + 1, indexes[s], indexes[d]);
            cout << endl;
        }

        if (T)
            cout << endl;

    }
    return 0;
}
