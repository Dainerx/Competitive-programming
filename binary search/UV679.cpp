#include <bits/stdc++.h>
#include <algorithm>
#include <set>
#include <queue>
#include <bits/algorithmfwd.h> 
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
typedef long long ll;

bool mycomp(char c1, char c2) {
    return std::tolower(c1) < std::tolower(c2);

}

template<typename T, typename TT> ostream& operator<<(ostream &s, pair<T, TT> t) {
    return s << t.first << " - " << t.second;
}
const ll MOD = 1e9 + 7;

int MAX_TREE = 0;

int _binary(int currentNode, int balls) {
    int childLeft = currentNode * 2;
    int childRight = childLeft + 1;

    if (childLeft <= MAX_TREE && childRight <= MAX_TREE) {
        if (balls % 2)
            _binary(childLeft, balls / 2 + 1);
        else
            _binary(childRight, balls / 2);
    } else
        return currentNode;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int D, I;
        cin >> D;
        if (D == -1)
            break;
        cin >> I;

        MAX_TREE = pow(2, D) - 1;
        cout << _binary(1, I) << endl;
    }


    cin.ignore(), cin.get();

}

