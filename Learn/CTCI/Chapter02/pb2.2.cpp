#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

void insert_node(Node** head, Node* n) {
    if(*head == NULL) {
        *head = n;
    }
    else {
        Node* curr = *head;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = n;
    }
}

void print_list(Node* head) {
    while(head != NULL) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

Node* kth_from_last(Node* head, int k) {
    Node* kth = head;
    Node* curr = head;

    // move kth pointer k times
    for(int i = 0; i < k && kth != NULL; i++) {
        kth = kth->next;
    }

    // now, move both the pointers one by one until kth is not null
    while(kth != NULL) {
        curr = curr->next;
        kth = kth->next;
    }

    return curr;
}

int main() {
    Node* head = NULL;
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);

    insert_node(&head, n1);
    insert_node(&head, n2);
    insert_node(&head, n3);
    insert_node(&head, n4);
    insert_node(&head, n5);
    insert_node(&head, n6);
    insert_node(&head, n7);
    insert_node(&head, n8);
    insert_node(&head, n9);

    cout << "Inital list:\t";
    print_list(head);
    int k = 3;
    cout << "k(" << k << ")th from last element : ";
    Node* n = kth_from_last(head, k);
    cout << n->data << endl;

    return 0;
}
