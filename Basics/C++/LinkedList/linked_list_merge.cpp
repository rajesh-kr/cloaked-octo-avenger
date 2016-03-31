#include <iostream>
using namespace std;

// This program merges two linked list in alternate manner

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
    Node* curr = head;
    while(curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void merge_list(Node** first, Node** second) {
    Node* curr = *first;
    Node* s = *second;
    Node* curr_n = NULL;
    Node* s_n = NULL;
    while(curr != NULL && s != NULL) {
        curr_n = curr->next;
        s_n = s->next;
        s->next = curr_n;
        curr->next = s;
        s = s_n;
        curr = curr_n;
    }
    *second = s;
}

int main() {
    Node* head1 = NULL;
    Node* a1 = new Node(1);
    Node* a2 = new Node(2);
    Node* a3 = new Node(3);
    insert_node(&head1, a1);
    insert_node(&head1, a2);
    insert_node(&head1, a3);
    cout << "Before Merge :" << endl;
    cout << "\tFirst List : ";
    print_list(head1);

    Node* head2 = NULL;
    Node* b1 = new Node(4);
    Node* b2 = new Node(5);
    Node* b3 = new Node(6);
    Node* b4 = new Node(7);
    Node* b5 = new Node(8);
    insert_node(&head2, b1);
    insert_node(&head2, b2);
    insert_node(&head2, b3);
    insert_node(&head2, b4);
    insert_node(&head2, b5);
    cout << "\tSecond List : ";
    print_list(head2);

    merge_list(&head1, &head2);

    cout << "After Merge :" << endl;
    cout << "\tFirst List : ";
    print_list(head1);
    cout << "\tSecond List : ";
    print_list(head2);

    return 0;
}
