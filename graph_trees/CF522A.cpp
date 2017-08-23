#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <list>
#include <queue>
#include <string>
#include <stdio.h>
#include <cmath>
#include <complex>
#include <math.h>
#include <string>
#include <string.h>
#include <ctype.h>
#include <map>
#include <set>
#include <numeric>
#include <bits/stl_bvector.h>

using namespace std;
#define MAX(a,b,c) max(a,max(b,c))
#define MIN(a,b,c) min(a,min(b,c))
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORJ(j,a,b) for(int j=(a);j<(b);j++)
#define REV(i,b,a) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back

struct node {
    std::pair<string, string> data;
    vector<node*> children;
};

int height(struct node * root) {

    if (root == NULL)
        return 0;

    else {
        int heightX = 0;
        for (int i = 0; i < root->children.size(); i++) {
            heightX = max(heightX, height(root->children.at(i)));
        }

        return heightX + 1;
    }

}

struct node* newNode(std::pair<string, string> data) {
    struct node *temp = new struct node;
    temp->data = data;
    vector <node *> children;
    temp->children = children;


    return temp;
}

bool icompare_pred(unsigned char a, unsigned char b) {
    return std::tolower(a) == std::tolower(b);
}

bool icompare(std::string const& a, std::string const& b) {
    if (a.length() == b.length()) {
        return std::equal(b.begin(), b.end(),
                a.begin(), icompare_pred);
    } else {
        return false;
    }
}

node* nodes[200];

int main() {

    int n;
    cin>>n;

    FOR(i, 0, n) {
        struct node *aNode = new struct node;
        aNode = newNode(mp(".", "."));
        nodes[i] = aNode;
    }

    FOR(i, 0, n) {
        string name1;
        string dump;
        string name2;


        cin >> name1 >> dump>>name2;
        nodes[i]->data = mp(name1, name2);

        FOR(j, 0, n) {
            if (icompare(nodes[j]->data.first, name2)) {
                nodes[j]->children.pb(nodes[i]);
            }
        }

    }
    
    int repost_chain=0;
    
    FOR(i,0,n)
    {
        repost_chain=max(repost_chain,height(nodes[i]));
    }
    
    cout << repost_chain + 1 ;


    return 0;
}
