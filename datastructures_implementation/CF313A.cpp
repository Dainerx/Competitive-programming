#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <complex>
#include <math.h>
#include <string>
#include <string.h>
#include<ctype.h>
#include <map>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REV(i,b,a) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back

int main(int argc, char *argv[]) {


    int n;
    string n__;
    cin>>n;
    
    if (n>=0)
        cout << n;
    else
    {
        string x,x1,x2,x0;
        n__=std::to_string(n);
        x=n__.substr(1,n__.size()-1);
        x0=x;
        x1=x0.erase(x0.size()-2,1);
        x2=x.erase(x.size()-1,1);
        
        int x1__,x2__;
        x1__=std::stoi(x1);
        x2__=std::stoi(x2);
        if (x1__==0 || x2__==0)
        cout << 0;
        else if (x2__>x1__)
        cout << "-"<<x1;
        else
        cout <<"-"<<x2;
    }
    
    
    return 0;
}
