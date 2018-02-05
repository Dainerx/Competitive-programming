#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;
#define MAX(a,b,c) max(a,max(b,c))
#define MIN(a,b,c) min(a,min(b,c))
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REV(i,b,a) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back

int main() {
    
    int n;
    double l;
    vector <double> lanterns;
    cin >> n >> l;
    
    FOR(i,0,n)
    {
        double x; 
        cin >> x;
        lanterns.push_back(x);
    }
    
    sort(lanterns.begin(),lanterns.end());
    
    
    double last_step;
    double step;
    
    step = lanterns.at(0)*2;
    last_step = l-lanterns.at(n-1);    
    FOR(i,1,lanterns.size())
    {
        step = max (step,lanterns.at(i) - lanterns.at(i-1));
    }
    
    
    
    double display = step / 2 ;
    display = max(display,last_step);
    cout.precision(9);
    cout << fixed << display ;
    
    return 0;

}
