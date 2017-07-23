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
    int data;
    struct node *left;
    struct node *right;
};

int depth(struct node * root) {

    if (root == NULL)
        return 0;

    else {
        int ldepth = depth(root->left);
        int rdepth = depth(root->right);

        if (ldepth > rdepth)
            return ldepth + 1;
        else
            return rdepth + 1;

    }

}

struct node* newNode(int data) {
    struct node *temp = new struct node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

node* nodes[2000];

int main() {

    int n;
    cin>>n;

    FOR(i, 0, n) {
        struct node *aNode = new struct node;
        aNode = newNode(0);
        nodes[i] = aNode;
    }

    FOR(i, 0, n) {
        int p;
        cin>>p;

        if (p == -1) {
            continue;
        } else {

            if (nodes[p - 1]->left == NULL) {
                nodes[p - 1]->left = nodes[i];
            } else
                nodes[p - 1]->right = nodes[i];
        }
    }

    int tables = 0;
       
    FOR(i, 0, n) {
        tables = max(depth(nodes[i]),tables);
    }

    cout << tables;


    return 0;
}
