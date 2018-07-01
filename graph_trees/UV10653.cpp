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

int R, C;
int distances[1001][1001];
bool bombed[1001][1001];

const vector<ii> possibleMoves(int sr, int sc) {
    vector<ii> result;
    result.pb(mp(sr + 1, sc));
    result.pb(mp(sr - 1, sc));
    result.pb(mp(sr, sc + 1));
    result.pb(mp(sr, sc - 1));
    return result;
}

int SSSP(int sr, int sc, int dr, int dc) {
    fillTab(distances, -1);
    distances[sr][sc] = 0;
    queue<ii> q;
    q.push(mp(sr, sc));
    while (!q.empty()) {
        ii u = q.front();
        q.pop();
        const vector<ii> moves = possibleMoves(u.first, u.second);

        FOR(i, 0, moves.size()) {
            ii v = moves[i];
            if ((v.first >= 0 && v.first <= R - 1) && (v.second >= 0 && v.second <= C - 1)) {
                if (distances[v.first][v.second] == -1 && !bombed[v.first][v.second]) {
                    distances[v.first][v.second] = distances[u.first][u.second] + 1;
                    q.push(v);
                }
            }
        }
    }

    return distances[dr][dc];
}

int main() {

    while (cin >> R >> C) {
        if (R == 0 && C == 0)
            break;

        fillTab(bombed, false);


        int bombs;
        cin >> bombs;

        FOR(i, 0, bombs) {

            int r;
            cin >> r;
            int num;
            cin >> num;
            while (num--) {
                int c;
                cin >> c;
                bombed[r][c] = true;

            }
        }


        int sr, sc;
        cin >> sr >> sc;
        int dr, dc;
        cin >> dr >> dc;

        cout << SSSP(sr, sc, dr, dc) << "\n";


    }
    return 0;
}
