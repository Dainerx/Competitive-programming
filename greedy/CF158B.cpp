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
    short group__;
    vector <short> groups;
    cin>>n;

    FOR(i, 0, n) {
        cin>>group__;
        groups.pb(group__);
    }
    
    
    int _1=0;
    int _2=0;
    int _3=0;
    int _4=0;
    int counter=0;

    FOR(i, 0, n) {
        if (groups[i]==1)
            _1++;
        else if (groups[i]==2)
            _2++;
        else if (groups[i]==3)
            _3++;
        else if (groups[i]==4)
            _4++;
    }
 
    counter+=_4;
    
    if(_3-_1>0)
    {
        counter+=_1+(_3-_1);
        _1=0;
        _3=0;
    }
    else if (_3-_1<0)
    {
        counter+=_3;
        _1=_1-_3;
    }
    else
    {
        counter+=_3;
        _1=0;
        _3=0;
    }
    
    
    if (_2>1)
    {
    if(_2%2==0)
    {
        counter+=_2/2;
        _2=0;
    }
    else
    {
        counter+=ceil(_2/2);
        _2=1;
    }
    }
    else if (_2==1 && _1==0)
    {
        counter++;
        _2=0;
    }
    
    short container__=0;
    while (_1!=0)
    {
        container__++;
        _1--;
        
        if (_2!=0)
        {
            container__+=2;
            _2--;
        }
        
        if (container__==4)
        {
            counter++;
            container__=0;
        }
        
    }
    
    if (_2!=0)
        counter++;
    
    if (container__!=0)
        counter++;
    
    cout << counter;
    
    return 0;
}
