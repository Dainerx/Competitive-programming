// std::begin / std::end example
#include <iostream>     // std::cout
#include <vector>       // std::vector, std::begin, std::end
#include <algorithm>
#include <stdio.h>
using namespace std;


#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REV(i,b,a) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back
#define SZ(v) (int)v.size()
#define sz(v) (int)v.size()
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define mem(s,v) memset(s,v,sizeof(s))
#define ppc(x) __builtin_popcount((x))
#define iter(it,s) for(__typeof(s.begin())it = s.begin();it!=s.end();it++)
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;


// Simple binary search algorithm
/*
int binarySearch(vector <char>& message, int l, int r, char c)
{
    if (r>=l)
    {
        int mid = l + (r - l)/2;
        if (message[mid] == c)
            return mid;
        if (message[mid] > c)
            return binarySearch(message, l, mid-1, c);
        return binarySearch(message, mid+1, r, c);
    }
    return -1;
}


int findPos(vector <char>& message, char c)
{
    int l = 0, h = 1;
    char val = message[0];
 
    // Find h to do binary search
    while (val < c)
    {
        l = h;        // store previous high
        h = 2*h;      // double high index
        val = message[h]; // update new val
    }
 
    // at this point we have updated low and high indices,
    // thus use binary search between them
    return binarySearch(message, l, h, c);
}
*/

vector <int> hasit;


bool gift (vector <int>& balls)
{
    hasit.clear();
    bool flag=true;
    short counter=0;       
    for (int i=0; i<sz(balls); i++) {
        for (int j=i+1; j<sz(balls); j++)
        {
            flag=true;
            if ((balls.at(i)-balls.at(j)<=2) && (balls.at(i)-balls.at(j)>=-2) && (balls.at(i)-balls.at(j)!=0))
            {
                for (int k=0; k<hasit.size(); k++)
                {
                    if (balls.at(j)==hasit.at(k))
                    {
                        flag=false;
                        break;
                    }
                }

                if (flag==true)
                {
                hasit.pb(balls.at(j));
                ++counter;
                if (counter==2)
                    return true;
                }
            }
        }
        counter=0;
    }
    return false;
}

struct myclass {
  bool operator() (int i,int j) { return (i>j);}
} myobject;

int main () {
    
    vector <int> balls; 

    int n;
    cin >> n;
    
    FOR(i,0,n) {
        int a;
        cin >> a;
        balls.pb(a);
    }
    
    std::sort (balls.begin(), balls.end(), myobject);
    
    
    if (gift(balls)==true)
        cout << "YES";
    else
        cout << "NO";
    
    
  return 0;
}
