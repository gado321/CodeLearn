#include <bits/stdc++.h>

using namespace std;

struct node {
    int val;
    node *l, *r;
}; 

node *T = new node;
int n;

node *createNode(int x) {
    node *tmp = new node;
    tmp -> val = x;
    tmp -> l = tmp -> r = NULL;
    return tmp;
}

node *insertNode(node *T, int x) {
    if (T == NULL) T = createNode(x);
    else if (T -> val < x) T -> r = insertNode(T -> r,x);
    else if (T -> val >= x) T -> l = insertNode(T -> l,x);
    return T;
}



int main(int argc, char const *argv[])
{
    
    return 0;
}