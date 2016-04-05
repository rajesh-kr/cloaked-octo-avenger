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

Node* rearrange(Node* node, int x) {
    Node* head = node;
    Node* tail = node;

    while(node != NULL) {
        Node* next = node->next;
        if(node->data < x) {
            node->next = head;
            head = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
        node = next;
    }
    tail->next = NULL;

    return head;
}

int main() {
    Node* head = NULL;
    Node* n1 = new Node(6);
    Node* n2 = new Node(3);
    Node* n3 = new Node(7);
    Node* n4 = new Node(1);
    Node* n5 = new Node(8);
    Node* n6 = new Node(11);
    Node* n7 = new Node(12);
    Node* n8 = new Node(2);
    Node* n9 = new Node(4);

    insert_node(&head, n1);
    insert_node(&head, n2);
    insert_node(&head, n3);
    insert_node(&head, n4);
    insert_node(&head, n5);
    insert_node(&head, n6);
    insert_node(&head, n7);
    insert_node(&head, n8);
    insert_node(&head, n9);

    cout << "List before:\n\t";
    print_list(head);

    Node* arr = rearrange(head, 5);
    cout << "List after:\n\t";
    print_list(arr);

    return 0;
}
