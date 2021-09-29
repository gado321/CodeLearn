#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *next;
    bool flag;
};

// Add node at the end
void addNode(Node** head, int dt) {
    Node *newNode = new Node;
    Node *last = *head;
    newNode->data = dt;
    newNode->next = NULL;
    newNode->flag = 0;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    return;
}

// Add node at the front
void push(Node** head, int dt)
{
    Node *newNode = new Node;
    newNode->data = dt;
    newNode->next = (*head);
    (*head) = newNode;
}

int main() {
    Node* a = NULL;
    addNode(&a, 1);
    addNode(&a, 2);
    addNode(&a, 3);
    a->next->next->next = a;
// Detect loop in a linked list
    while (a != NULL) {
        if (a->flag) {
            cout << "Yes";
            return 0;
        }
        a->flag = 1;
        a = a->next;
    }
    return 0;
}