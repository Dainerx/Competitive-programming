#include <bits/stdc++.h>
#include <algorithm>
#include <set>
#include <queue> 
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
typedef vector< vector<ii> > vw;

bool mycomp(char c1, char c2) {
    return std::tolower(c1) < std::tolower(c2);
}

template<typename T, typename TT> ostream& operator<<(ostream &s, pair<T, TT> t) {
    return s << t.first << " - " << t.second;
}

vector< vector <std::pair<int, std::pair<double, bool> > > > adj;
vi taken;
priority_queue< std::pair< std::pair<double,int>, bool> > pq;

void compute(int cur) {
    taken[cur] = 1;

    FOR(i, 0, adj[cur].size()) {
        int v = adj[cur][i].first;
        double w = adj[cur][i].second.first;

        if (!taken[v])
            pq.push(mp(mp(-w, -v), adj[cur][i].second.second));
    }
    return;
}

double distanceCalculate(double x1, double y1, double x2, double y2) {
    double x = x1 - x2;
    double y = y1 - y2;
    double dist;

    dist = pow(x, 2) + pow(y, 2); 
    dist = sqrt(dist);

    return dist;
}

int main() {

    int T;
    cin >> T;
    //freopen("go.out","w",stdout);
    FOR(index, 0, T) {
        ii nodes[1001];

        int n, r;
        cin >> n >> r;

        FOR(i, 0, n) {
            int x, y;
            cin >> x >> y;
            nodes[i] = mp(x, y);
        }

        int number_states = 1;
        adj.clear();
        adj.resize(n);
        taken.assign(n, 0);

        FOR(i, 0, n) {
            ii cur = nodes[i];

            FOR(j, i + 1, n) {
                ii v = nodes[j];
                double d = distanceCalculate(cur.first, cur.second, v.first, v.second);
                if (distanceCalculate(cur.first, cur.second, v.first, v.second) > r) {
                    adj[i].pb(mp(j, mp(d, true)));
                    adj[j].pb(mp(i, mp(d, true)));

                } else {
                    adj[i].pb(mp(j, mp(d, false)));
                    adj[j].pb(mp(i, mp(d, false)));
                }
            }
        }

        compute(0);

        double cost_roads = 0;
        double cost_rail_roads = 0;

        while (!pq.empty()) {
            double w = abs(pq.top().first.first);
            int v = abs(pq.top().first.second);
            int isRailed = pq.top().second;
            pq.pop();
            if (!taken[v]) {
                if (isRailed) {
                    number_states++;
                    cost_rail_roads += w;
                    compute(v);
                } else {
                    cost_roads += w;
                    compute(v);
                }
            }
        }

        int i_ = index;
        cout << "Case #" << ++i_ << ": " << number_states << " " << round(cost_roads) << " " << round(cost_rail_roads) << endl;



    }
}
