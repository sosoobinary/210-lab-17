// COMSC-210 | Lab 17 | Quang Ngo
// IDE used: Visual Studio Code
#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);
void addFront(Node *&, float);
void addTail(Node *&, float);
void deleteNode(Node *&, int);
void insertNode(Node *&, int, float);
void deleteList(Node *&);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        addFront(head, tmp_val);
    }
    output(head);

    // deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    deleteNode(head, entry);
    output(head);

    // insert a node
    cout << "After which node to insert 10000? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;

    insertNode(head, entry, 10000);
    output(head);

    // deleting the linked list
    deleteList(head);
    output(head);

    return 0;
}

void output(Node * hd) {
    if(!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while(current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void addFront(Node*& hd, float val) {
    Node* newNode = new Node{val, hd};
    hd = newNode;
}
void addTail(Node*& hd, float val) {
    Node* newNode = new Node{val, nullptr};
    if(!hd) {
        hd = newNode;
        return;
    }
    Node* current = hd;
    while(current->next) {
        current = current->next;
    }
    current->next = newNode;
}
void deleteNode(Node*& hd, int pos) {
    if(pos < 1 || !hd) return;

    Node* current = hd;

    if(pos == 1) {
        hd = hd->next;
        delete current;
        return;
    }
    Node* prev = nullptr;
    int count = 1;

    while(current && count < pos) {
        prev = current;
        current = current->next;
        count++;
    }

    if(current && prev) {
        prev->next = current->next;
        delete current;
    }
}
void insertNode(Node*& hd, int pos, float val) {
    if(pos < 1) return;

    Node* current = hd;
    int count = 1;

    while(current && count < pos) {
        current = current->next;
        count++;
    }

    if(!current) return;

    Node* newNode = new Node{val, current->next};
    current->next = newNode;
}
void deleteList(Node*& hd) {
    Node* current = hd;
    while(current) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    hd = nullptr;
}