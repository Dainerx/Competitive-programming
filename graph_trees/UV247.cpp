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
vector< vector< std::pair<int, string> > > adj;
vector< std::pair<int, string> > stock;
vi dfs_num, dfs_low;
bool visited[30];

void SCC(std::pair<int, string> cur) {
    visited[cur.first] = true;
    dfs_num[cur.first] = dfs_low[cur.first] = dfsNumberCount++;
    stock.pb(cur);
    for (int i = 0; i < adj[cur.first].size(); i++) {
        std::pair<int, string> v = adj[cur.first][i];
        if (dfs_num[v.first] == -1)
            SCC(v);
        if (visited[v.first])
            dfs_low[cur.first] = min(dfs_low[v.first], dfs_low[cur.first]);
    }
    if (dfs_low[cur.first] == dfs_num[cur.first]) {
        string result, temp;
        result = temp = "";
        while (1) {
            std::pair<int, string> v = stock.back();
            stock.pop_back();
            visited[v.first] = false;
            temp += v.second + ", ";
            if (cur.first == v.first) break;
        }
        result = temp.substr(0, temp.size() - 2);
        cout << result;
        cout << endl;
    }
}

int main() {

    int c = 0;
    while (cin >> n >> m) {
        c++;
        int generalCount = -1;
        map<string, int> names;
        if (n == 0 && m == 0)
            break;
        numSCC = dfsNumberCount = 0;
        adj.clear();
        adj.resize(n);
        dfs_num.assign(n, -1);
        dfs_low.assign(n, 0);
        fillTab(visited, false);

        FOR(i, 0, m) {
            string a, b;
            int a_index, b_index;

            cin >> a;
            if (names.find(a) == names.end()) {
                names.insert(mp(a, ++generalCount));
                a_index = generalCount;
            } else {
                a_index = names.at(a);
            }

            cin >> b;
            if (names.find(b) == names.end()) {
                names.insert(mp(b, ++generalCount));
                b_index = generalCount;
            } else {
                b_index = names.at(b);
            }
            adj.at(a_index).pb(mp(b_index, b));
        }

        cout << "Calling circles for data set " << c << ":" << endl;
        for (map<string, int>::iterator it = names.begin(); it != names.end(); it++) {
            if (dfs_num[it->second] == -1)
                SCC(mp(it->second, it->first));
        }

    }
    return 0;
}
