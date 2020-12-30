
#include <iostream>
#include "problem/list/430.h"

using namespace std;

int main() {
    Solution s;

    Node *head = new Node();
    head->val = 1;
    Node *second = new Node();
    second->val = 2;
    head->next = second;
    Node *third = new Node();
    third->val = 3;
    head->child = third;

    auto *h = s.flatten(head);

    auto *cur = h;
    while (cur != nullptr) {
        cout << cur->val << ",";
        cur = cur->next;
    }
    cout << endl;
    cur = h;
    while (cur->next != nullptr) cur = cur->next;
    while (cur != nullptr) {
        cout << cur->val << ",";
        cur = cur->prev;
    }
}

