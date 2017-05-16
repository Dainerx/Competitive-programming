
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
//typedef map<string, list<string>>::const_iterator MapIterator;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   problemA.cpp
 * Author: dainer
 *
 * Created on March 13, 2017, 11:50 AM
 */


int main()
{
    
    ll l[30];
    ll u[30];
    string t,s;
    mem(l,0);
    mem(u,0);
    
    cin>>s>>t;
    
    FOR(i,0,sz(t))
    {
        if (t[i]>='a' && t[i]<='z')
        {
            l[t[i]-'a']++;
        }
        else
        {
            u[t[i]-'A']++;
        }
    }


    ll yes,whop;
    yes=whop=0;
    
    FOR (i,0,sz(s)) 
    {
        if (s[i]=='.')
            continue;

        if (s[i]>='a' && s[i]<='z')
        {
            if (l[s[i]-'a']>0)
            {
                yes++;
                l[s[i]-'a']--;
                s[i]='.';
            }
        }
        else if (s[i]>='A' && s[i]<='Z')
        {
            if (u[s[i]-'A']>0)
            {
                yes++;
                u[s[i]-'A']--;
                s[i]='.';
            }
        }
    }
    
    FOR (i,0,sz(s))
    {
        if (s[i]=='.')
            continue;
        
        if (s[i]>='a' && s[i]<='z')
        {
            if (u[s[i]-'a']>0)
            {
                whop++;
                u[s[i]-'a']--;
                s[i]='.';
            }
        }
        else if (s[i]>='A' && s[i]<='Z')
        {
            if (l[s[i]-'A']>0)
            {
                whop++;
                l[s[i]-'A']--;
                s[i]='.';
            }
        }
    }
    
    
    cout << yes  << " " << whop;
    

    
    return 0;

}
