#include <bits/stdc++.h>
#include <algorithm>
#include <set> 
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

int R, C, M, N;
int odd, even;
bool water[101][101];
bool visited[101][101];

std::set<ii> getPossibleMoves(int xi, int yi) {
    std::set<ii> possible_moves;
    possible_moves.insert(mp(xi + M, yi + N));
    possible_moves.insert(mp(xi + M, yi - N));
    possible_moves.insert(mp(xi - M, yi + N));
    possible_moves.insert(mp(xi - M, yi - N));

    possible_moves.insert(mp(xi + N, yi + M));
    possible_moves.insert(mp(xi + N, yi - M));
    possible_moves.insert(mp(xi - N, yi + M));
    possible_moves.insert(mp(xi - N, yi - M));
    return possible_moves;
}

void dfs(int r, int c) {
    visited[r][c] = true;

    std::set<ii> possible_moves = getPossibleMoves(r, c);
    int ct = 0;
    std::set<ii>::iterator it;
    for (it = possible_moves.begin(); it != possible_moves.end(); ++it) {
        int xi = it->first;
        int yi = it->second;
        if (xi >= 0 && xi <= R - 1 && yi >= 0 && yi <= C - 1 && !water[xi][yi]) {
            ct++;
            if (!visited[xi][yi])
                dfs(xi, yi);
        }
    }

    if (ct % 2)
        odd++;
    else
        even++;
    return;
}

int main() {
    int T;
    cin >> T;

    FOR(index, 0, T) {
        odd = even = 0;
        fillTab(water, false);
        fillTab(visited, false);
        cin >> R >> C >> M >> N;
        int W;
        cin >> W;
        while (W--) {
            int xi, yi;
            cin >> xi >> yi;
            water[xi][yi] = true;
        }

        dfs(0, 0);
        int caseNum = index;
        cout << "Case " << ++caseNum << ": " << even << " " << odd << endl;
    }

}
